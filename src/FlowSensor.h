#pragma once

#include "Arduino.h"
#include "FunctionalInterrupt.h"
#include "esp_log.h"

#define TOGGLE(pin) digitalWrite(pin, !digitalRead(pin))

// based upon: https://forum.arduino.cc/t/interrupt-in-class-esp32/1039326/12


typedef struct {
  uint32_t count;
  uint32_t bounces;
  uint32_t irqs;
  uint32_t last_edge; // mS since startup
  uint32_t timestamp; // mS since startup
  bool flowing;
} flowsensor_report_t;

class FlowSensor {
public:
  void begin(int16_t pin, unsigned long flowDeltaT = 100000,
             unsigned long bounceDeltaT = 10, int mode = FALLING) {
    if (pin < 0)
      return;
    if (!digitalPinIsValid(pin)) {
      ESP_LOGD( "FlowSensor", "invalid pin: %d", pin);
      return;
    }
    valid_ = true;
    pin_ = pin;
    flowDeltaT_ = flowDeltaT;
    bounceDeltaT_ = bounceDeltaT;
    mode_ = mode;
    pinMode(pin_, INPUT_PULLUP);
  }

  bool enable(void) {
    if (valid_) {
      attachInterrupt(digitalPinToInterrupt(pin_),
                      std::bind(&FlowSensor::sensorISR, this), mode_);
      enabled_ = true;
    } else {
      ESP_LOGD( "FlowSensor", "invalid configuration");
    }
    return enabled_;
  }

  void disable(void) {
    detachInterrupt(digitalPinToInterrupt(pin_));
    enabled_ = false;
  }
  
  void reset(void) {
    count_ = 0;
    irqs_ = 0;
    flowDetected_ = false;
    lastEdge_ = 0;
    bounces_ = 0;
  }

  bool flowDetected(void) { return (micros() - lastEdge_) < flowDeltaT_; }

  void getReport(flowsensor_report_t &report) {
    report.flowing = flowDetected();
    report.count = count_;
    report.bounces = bounces_;
    report.irqs = irqs_;
    report.last_edge = lastEdge_ / 1000;
    report.timestamp = millis();
  }
  uint32_t numIrqs(void) { return irqs_; }
  uint8_t pinNum(void) { return pin_; }
  bool enabled(void) { return enabled_; }

private:
  bool enabled_, valid_;
  int16_t pin_;
  int mode_;
  unsigned long flowDeltaT_, bounceDeltaT_;
  bool flowDetected_;
  volatile uint32_t irqs_;
  volatile bool changed_;
  volatile unsigned long lastEdge_;
  volatile uint32_t count_ = 0;
  volatile uint32_t bounces_ = 0;

  void IRAM_ATTR sensorISR() {
#ifdef ISR_PIN
    TOGGLE(ISR_PIN);
#endif
    irqs_++;

    unsigned long now = micros();
    if ((now - lastEdge_) < bounceDeltaT_) {
      bounces_++;
    } else {
      count_++;
    }
    changed_ = true;
    lastEdge_ = now;

#ifdef ISR_PIN
    TOGGLE(ISR_PIN);
#endif
  }
};
