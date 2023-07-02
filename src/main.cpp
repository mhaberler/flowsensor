
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

#define T2OK(x) ((x) ? "OK" : "FAILED")

FlowSensor flow_sensor;
QuadratureDecoder qdecoder;

uint8_t flowsensor_A = PIN_FLOWSENSOR_A;
uint8_t flowsensor_B = PIN_FLOWSENSOR_B;
Ticker sampler, battery, sensor, idle;

void sensor_update(bool force);

#ifndef MANUFACTURER_ID
#define MANUFACTURER_ID 0x4711 // https://www.4711.com/en/
#endif
#define FLAG_QUADRATURE 1

typedef struct __attribute__((packed)) {
  uint8_t mfidLow;
  uint8_t mfidHigh;
  uint8_t address[6]; // iOS workaround stupid UUID scheme
  int32_t count;
  uint32_t last_change;
  uint8_t batteryLevel;
  uint8_t flags;
} mfdReport_t;

static mfdReport_t manufacturer_data;
void sensor_update(bool force);

void setup() {
#ifdef ARDUINO_USB_CDC_ON_BOOT
  delay(3000); // wait for USB to come uo before chatting
#endif

#ifdef M5UNIFIED
  auto cfg = M5.config();
  M5.begin(cfg);
#else
  Serial.begin(115200);
#endif
  while (!Serial) {
    yield();
  }
  ESP_LOGI(__FILE__, "total PSRAM=%u free PSRAM=%u\n", ESP.getPsramSize(),
           ESP.getFreePsram());
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
  M5.update();
  manufacturer_data.batteryLevel = M5.Power.getBatteryLevel();
  ESP_LOGI(__FILE__, "battery level: %d\n", manufacturer_data.batteryLevel);
  battery.attach(BATTERY_UPDATE_SEC, []() {
    M5.update();
    manufacturer_data.batteryLevel = M5.Power.getBatteryLevel();
  });
  const uint8_t *adr = beacon_setup();
  memcpy(manufacturer_data.address, adr, sizeof(manufacturer_data.address));
  sensor.attach_ms(UPDATE_MS, []() { sensor_update(false); });
  idle.attach_ms(IDLE_UPDATE_SEC * 1000, []() { sensor_update(true); });
}

void loop() { delay(1); }

void sensor_update(bool force) {

#ifdef QUADRATURE_DECODER

  static uint32_t track_count = 0xffffff;
  qsensor_report_t report;

  qdecoder.getReport(report);

  if ((report.count != track_count) || force) {
    ESP_LOGI(__FILE__, "A/B: count: %d last_change: %f updates %u force %d\n",
             report.count, report.last_change / 1000000.0, report.updates,
             force);
    track_count = report.count;

    manufacturer_data.count = report.count;
    manufacturer_data.last_change = report.last_change;
    beacon_update_manufacturer_data((uint8_t *)&manufacturer_data,
                                    sizeof((manufacturer_data)));
  }
#else
  if (flow_sensor.flowDetected() || force) {
    flowsensor_report_t report;
    flow_sensor.getReport(report);
    ESP_LOGI("IRQs: %u  count: %u bounces: %u force %d\n", report.irqs,
             report.count, report.bounces.force);

    manufacturer_data.count = report.count;
    manufacturer_data.last_change = report.last_edge;
    beacon_update_manufacturer_data((uint8_t *)&manufacturer_data,
                                    sizeof((manufacturer_data)));
  }
#endif
}
