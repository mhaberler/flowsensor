#pragma once
#include <stddef.h>
#include <stdint.h>

#ifndef MANUFACTURER_ID
#define MANUFACTURER_ID 0x4711 // https://www.4711.com/en/
#endif

#define FLAG_QUADRATURE 1
#define FLAG_WIFICONNECTED 2
#define FLAG_CHARGING 4
#define FLAG_DISCHARGING 8
#define FLAG_CHARGE_UNKNOWN 16
#define CHARGE_MASK (FLAG_CHARGING|FLAG_DISCHARGING|FLAG_CHARGE_UNKNOWN)

typedef struct __attribute__((packed)) {
  uint8_t mfidLow;
  uint8_t mfidHigh;
  uint8_t address[6];   // replicate to tunnel past iOS 
  int32_t count;        // counts
  uint32_t last_change; // uS since startup
  int16_t rate;         // counts/second
  uint8_t batteryLevel; // %
  uint8_t flags;
} mfdReport_t;

void ui_update_values(const mfdReport_t &mfd, float maxRate);
