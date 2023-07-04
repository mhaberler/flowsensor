#pragma once
#include <stddef.h>
#include <stdint.h>

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
  int16_t rate;
  uint8_t batteryLevel;
  uint8_t flags;
} mfdReport_t;

void ui_update_values(const mfdReport_t &mfd, float maxRate);
