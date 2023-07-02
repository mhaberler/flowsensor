#pragma once

#include "Arduino.h"
#include "Ticker.h"
#include "esp_log.h"

// https://www.mikrocontroller.net/articles/Drehgeber - "Solide Lösung"
// works both timer- and interrupt-driven

typedef struct {
  int32_t count;
  uint32_t last_change; // uS since startup
  uint32_t last_sample; // uS since startup
  uint32_t updates; // IRQ's, or timer samples
  bool changed;
} qsensor_report_t;

class QuadratureDecoder;
static void IRAM_ATTR pinChange(QuadratureDecoder *q);

class QuadratureDecoder {
public:
  void begin(int16_t pinA = -1, int16_t pinB = -1, uint8_t step = 1,
             uint32_t sampleTickMsec = 0, uint32_t changeDeltaT = 100000,
             uint8_t inputMode = INPUT_PULLUP, uint8_t edge = CHANGE) {
    if (pinA < 0)
      return;
    if (pinB < 0)
      return;
    if (!digitalPinIsValid(pinA)) {
      ESP_LOGD(__FILE__, "invalid pinA: %d", pinA);
      return;
    }
    if (!digitalPinIsValid(pinB)) {
      ESP_LOGD(__FILE__, "invalid pinB: %d", pinB);
      return;
    }
    pinA_ = pinA;
    pinB_ = pinB;
    inputMode_ = inputMode;
    sampleTickMsec_ = sampleTickMsec;
    changeDeltaT_ = changeDeltaT;
    step_ = step;
    edge_ = edge;
  }

  bool enable(void) {
    if ((pinA_ < 0) || (pinB_ < 0)) {
      return false;
    }
    pinMode(pinA_, inputMode_);
    pinMode(pinA_, inputMode_);
    if (sampleTickMsec_ > 0) {
      sampleTicker_.attach_ms(sampleTickMsec_, pinChange, this);
      irq_mode_ = false;
    } else {
      attachInterrupt(digitalPinToInterrupt(pinA_), std::bind(pinChange, this),
                      edge_);

      attachInterrupt(digitalPinToInterrupt(pinB_), std::bind(pinChange, this),
                      edge_);
      irq_mode_ = true;
    }
    enabled_ = true;
    return enabled_;
  }

  void disable(void) {
    sampleTicker_.detach();
    enabled_ = false;
  }

  void reset(void) {
    count_ = 0;
    qLastChangeAt_ = 0;
  }

  bool changeDetected(void) {
    return (micros() - qLastChangeAt_) < changeDeltaT_;
  }

  void getReport(qsensor_report_t &report) {
    report.changed = changeDetected();
    report.count = count_;
    report.last_change = qLastChangeAt_;
    report.updates = updates_; 
    report.last_sample = lastSample_;
  }

  bool enabled(void) { return enabled_; }

  friend void pinChange(QuadratureDecoder *q);

private:
  int16_t pinA_, pinB_;
  uint8_t inputMode_;
  uint8_t step_;
  uint8_t edge_;

  uint32_t sampleTickMsec_;
  bool enabled_, irq_mode_;
  Ticker sampleTicker_;
  uint32_t qLastChangeAt_, countLastChangeAt_, countBounces_, lastSample_;
  uint32_t changeDeltaT_;
  volatile int8_t enc_delta_; // -128 ... 127
  int8_t last_, current_;
  volatile int32_t count_ = 0;
  volatile uint32_t updates_;

  // read 1, 2, or 4 step encoders
  int8_t encode_read(uint8_t step) {
    int8_t val;

    // atomic access to enc_delta if
    if (!irq_mode_) {
      cli();
    }
    val = enc_delta_;
    switch (step) {
    case 2:
      enc_delta_ = val & 1;
      val >>= 1;
      break;
    case 4:
      enc_delta_ = val & 3;
      val >>= 2;
      break;
    default:
      enc_delta_ = 0;
      break;
    }
    if (!irq_mode_) {
      sei();
    }
    return val; // counts since last call
  }
};

static void IRAM_ATTR pinChange(QuadratureDecoder *q) {
  int8_t diff;
  q->lastSample_ = micros();
  q->current_ = 0;
  if (digitalRead(q->pinA_)) {
    q->current_ = 3;
  }
  if (digitalRead(q->pinB_)) {
    q->current_ ^= 1; // convert gray to binary
  }
  diff = q->last_ - q->current_;     // difference last - current_
  if (diff & 1) {                    // bit 0 = value (1)
    q->last_ = q->current_;          // store current as next last
    q->enc_delta_ += (diff & 2) - 1; // bit 1 = direction (+/-)
  }
  if (diff != 0) {
    int8_t n = q->encode_read(q->step_);
    if (n != 0) {
      q->count_ += n;
      q->qLastChangeAt_ = q->lastSample_;
    }
  }
  q->updates_++;
  // counter mode
}
