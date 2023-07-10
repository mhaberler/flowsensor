#pragma once
#include <stddef.h>
#include <stdint.h>

#ifndef PIN_FLOWSENSOR_A
#define PIN_FLOWSENSOR_A -1
#endif

#ifndef PIN_FLOWSENSOR_B
#define PIN_FLOWSENSOR_B -1
#endif

#ifndef BLE_PREFIX
#define BLE_PREFIX "FlowSensor"
#endif

#ifndef MANUFACTURER_ID
#define MANUFACTURER_ID 0x4711 // https://www.4711.com/en/
#endif

// https://infocenter.nordicsemi.com/index.jsp?topic=%2Fcom.nordic.infocenter.s132.api.v3.0.0%2Fgroup___b_l_e___a_p_p_e_a_r_a_n_c_e_s.html
#ifndef BLE_APPEARANCE_GENERIC_TAG
#define BLE_APPEARANCE_GENERIC_TAG 512
#endif

#define FLAG_QUADRATURE 1
#define FLAG_WIFICONNECTED 2 // unused
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
void ui_set_inital_values(void);

