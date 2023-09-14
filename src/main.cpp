
#include <Arduino.h>
#ifdef M5UNIFIED
#include <M5Unified.h>
#endif
#include "Esp.h"
#include "FlowSensor.h"
#include "FunctionalInterrupt.h"
#include "NimBLEAddress.h"
#include "QuadratureDecoder.h"
#include "Ticker.h"
#include "beacon.h"
#include "defs.h"

#include "lv_setup.h"
#include "ui/ui.h"

#define T2OK(x) ((x) ? "OK" : "FAILED")

#ifdef C3MATE
#define PIN_FLOWSENSOR_A 0 // https://docs.m5stack.com/en/core/StampS3
#define PIN_FLOWSENSOR_B 1
#define PIN_ADC 4
#define ADC_ATTENUATION                                                        \
  ADC_11db // https://espressif-docs.readthedocs-hosted.com/projects/arduino-esp32/en/latest/api/adc.html#analogsetattenuation
#define ANALOG_RESOLUTION 12
#define BUTTON_PIN 3
#define DLED_TYPE SK6812
#define LED_DATA_PIN 2
#define NUM_LEDS 1
#endif

FlowSensor flow_sensor;
QuadratureDecoder qdecoder;

uint8_t flowsensor_A = PIN_FLOWSENSOR_A;
uint8_t flowsensor_B = PIN_FLOWSENSOR_B;
Ticker sampler, battery, sensor, idle;

#ifdef NUM_LEDS
#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel pixel(NUM_LEDS, LED_DATA_PIN, NEO_GRBW + NEO_KHZ800);
#define BRIGHTNESS 255
#define GREEN 0x00FF00
#define BLUE 0x3a4493
#define ORANGE 0xff4500
#define RED 0xff4500
#define WHITE 0xffffff
#define BLACK 0x000000

#define setColor(color)                                                        \
  {                                                                            \
    pixel.setPixelColor(0, color);                                             \
    pixel.show();                                                              \
  }
#else
#define setColor(color)
#endif
bool currentButtonPressed = false;

void sensor_update(bool force);

static mfdReport_t manufacturer_data;
void sensor_update(bool force);

static int32_t track_count;
static uint32_t track_now;
static float max_rate;

#ifdef LVGL_UI
void clearCountPressed(lv_event_t *e) {
#ifdef QUADRATURE_DECODER
  qdecoder.reset();
#endif
#ifdef FLOWSENSOR
  flow_sensor.reset();
#endif
  track_count = 0;
  track_now = micros();
  max_rate = 0;
  sensor_update(true);
}
#endif

void setup() {
#ifdef NUM_LEDS
  // set up neopixel
  pixel.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixel.clear(); // Set pixel colors to 'off'
  pixel.show();
  pixel.setBrightness(BRIGHTNESS);
  setColor(RED);

#endif
  delay(1000);

#ifdef M5UNIFIED
  auto cfg = M5.config();
  M5.begin(cfg);
  M5.Display.setRotation(3);
#else
  Serial.begin(115200);
#endif

#ifdef BUTTON_PIN
  pinMode(BUTTON_PIN, INPUT_PULLUP);
#endif

#if PIN_ADC
  pinMode(PIN_ADC, INPUT);
#ifdef ANALOG_RESOLUTION
  // set the resolution to 12 bits (0-4096)
  analogReadResolution(ANALOG_RESOLUTION);
#endif
#ifdef ADC_ATTENUATION
  analogSetPinAttenuation(PIN_ADC, ADC_ATTENUATION);
#endif
#endif

#ifdef LVGL_UI
  lv_begin(); // Initialize LVGL for the Core2 screen
  ui_init();  // Initialize UI generated by Square Line
  ui_set_inital_values();
#endif
  ESP_LOGI(__FILE__, "total PSRAM=%u free PSRAM=%u mfd=%u\n",
           ESP.getPsramSize(), ESP.getFreePsram(), sizeof(mfdReport_t));
  ESP_LOGI(__FILE__, "flowsensor_A %u %s\n", flowsensor_A,
           T2OK(digitalPinIsValid(flowsensor_A)));
  ESP_LOGI(__FILE__, "flowsensor_B %u: %s\n", flowsensor_B,
           T2OK(digitalPinIsValid(flowsensor_B)));
#ifdef FLOWSENSOR
  flow_sensor.begin(flowsensor_A);
  ESP_LOGI(__FILE__, "flowsensor enabled: %s\n", T2OK(flow_sensor.enable()));
#endif

#ifdef QUADRATURE_DECODER
  qdecoder.begin(PIN_FLOWSENSOR_A, PIN_FLOWSENSOR_B, 1, 0);
  ESP_LOGI(__FILE__, "A/B sensor enabled: %s\n", T2OK(qdecoder.enable()));
#endif

  manufacturer_data.mfidLow = MANUFACTURER_ID & 0x00ff;
  manufacturer_data.mfidHigh = (MANUFACTURER_ID >> 8) & 0x00ff;
#ifdef QUADRATURE_DECODER
  manufacturer_data.flags |= FLAG_QUADRATURE;
#endif

#ifdef M5UNIFIED
  M5.update();
  manufacturer_data.batteryLevel = M5.Power.getBatteryLevel();
#endif
  const uint8_t *na = (const uint8_t *)beacon_setup().c_str();
  uint8_t *ap = manufacturer_data.address;
  *ap++ = na[5];
  *ap++ = na[4];
  *ap++ = na[3];
  *ap++ = na[2];
  *ap++ = na[1];
  *ap++ = na[0];
  sensor.attach_ms(UPDATE_MS, []() { sensor_update(false); });
  idle.attach_ms(IDLE_UPDATE_MS, []() {
    setColor(GREEN);
#ifdef M5UNIFIED
    M5.update();
    manufacturer_data.batteryLevel = M5.Power.getBatteryLevel();
    manufacturer_data.flags &= ~CHARGE_MASK;

    switch (M5.Power.isCharging()) {
    case m5::Power_Class::is_discharging:
      manufacturer_data.flags |= FLAG_DISCHARGING;
      break;
    case m5::Power_Class::is_charging:
      manufacturer_data.flags |= FLAG_CHARGING;
      break;
    case m5::Power_Class::charge_unknown:
      manufacturer_data.flags |= FLAG_CHARGE_UNKNOWN;
      break;
    }
#else
          manufacturer_data.flags = FLAG_CHARGE_UNKNOWN;
              manufacturer_data.batteryLevel = 0;
#endif
#ifdef PIN_ADC
    int mV = analogReadMilliVolts(PIN_ADC);
    float bar = mVtoPressure(mV);

    manufacturer_data.pressure_mBar = bar * 1000;
    manufacturer_data.flags |= FLAG_PRESSURE_MILLIBAR;
    ESP_LOGI(__FILE__, "pressure_mBar: %u  mV %d  bar %f\n",
             manufacturer_data.pressure_mBar, mV, bar);

#endif
    sensor_update(true);
    // setColor(BLACK);
  });
}

void loop() {
#ifdef LVGL_UI
  lv_handler(); // Update UI
  // update_time(); // Update time and date on UI
#endif
  delay(1);
}

void sensor_update(bool force) {

#ifdef QUADRATURE_DECODER
  qsensor_report_t report;
  qdecoder.getReport(report);
  setColor(BLUE);

  if ((report.count != track_count) || force) {
    uint32_t now = micros();
    setColor(ORANGE);

// try custom esp-idf component
#if CONFIG_FOO_ENABLE_BAR
    test_method(track_count);
#endif

    float delta = (float)(report.count - track_count);
    float rate = abs(delta * 1.e6f / (now - track_now));
    if (rate > max_rate) {
      max_rate = rate;
    }
    track_count = report.count;
    track_now = now;

    manufacturer_data.rate = rate * 10;
    manufacturer_data.count = report.count;
    manufacturer_data.last_change = report.last_change;
    beacon_update_manufacturer_data((uint8_t *)&manufacturer_data,
                                    sizeof((manufacturer_data)));
  }
  setColor(BLACK);

// ESP_LOGI(__FILE__, "count: %d rate: %d max_rate %f force %d\n",
//          manufacturer_data.count, manufacturer_data.rate, max_rate, force);
#ifdef LVGL_UI
  ui_update_values(manufacturer_data, max_rate);
#endif
#endif
#ifdef FLOWSENSOR
  flowsensor_report_t report;

  if (flow_sensor.flowDetected() || force) {
    setColor(GREEN);

    flow_sensor.getReport(report);
    // ESP_LOGI(__FILE__, "IRQs: %u  count: %u bounces: %u force %d\n",
    //          report.irqs, report.count, report.bounces, force);

    uint32_t now = micros();

    float delta = (float)(report.count - track_count);
    float rate = delta * 1.e6f / (now - track_now);
    if (rate > max_rate) {
      max_rate = rate;
    }
    track_count = report.count;
    track_now = now;

    manufacturer_data.rate = rate * 10;
    manufacturer_data.count = report.count;
    manufacturer_data.last_change = report.last_edge;
    beacon_update_manufacturer_data((uint8_t *)&manufacturer_data,
                                    sizeof((manufacturer_data)));
    // } else {
    //   setColor(BLACK);
  }
#ifdef LVGL_UI
  ui_update_values(manufacturer_data, max_rate);
#endif
#endif
}
