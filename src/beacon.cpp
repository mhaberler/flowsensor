
#include "beacon.h"
#include "NimBLEBeacon.h"
#include "NimBLEDevice.h"
#include "esp_sleep.h"
#include "sys/time.h"

#ifndef MANUFACTURER_ID
#define MANUFACTURER_ID 0x4711 // https://www.4711.com/en/
#endif

// https://infocenter.nordicsemi.com/index.jsp?topic=%2Fcom.nordic.infocenter.s132.api.v3.0.0%2Fgroup___b_l_e___a_p_p_e_a_r_a_n_c_e_s.html

#define BLE_APPEARANCE_GENERIC_TAG 512
static BLEAdvertisementData *advData;
static BLEAdvertisementData scanResponse = BLEAdvertisementData();
static BLEAdvertising *pAdvertising;

const uint8_t *beacon_setup(void) {
  BLEDevice::init("");
  scanResponse.setAppearance(BLE_APPEARANCE_GENERIC_TAG);
  scanResponse.setFlags(BLE_HS_ADV_F_BREDR_UNSUP | BLE_HS_ADV_F_DISC_GEN);
  scanResponse.setName(BLE_NAME);
  return BLEDevice::getAddress().getNative();
}

void beacon_update_manufacturer_data(uint8_t *data, size_t size) {

  if (pAdvertising == NULL) {
    pAdvertising = BLEDevice::getAdvertising();
  }
  if (pAdvertising->isAdvertising()) {
    pAdvertising->reset();
  }

  advData = new BLEAdvertisementData();
  std::string manufacturerData((char *)data, size);

  advData->setManufacturerData(manufacturerData);
  ESP_LOGD("beacon.cpp", "payload size=%u\n", advData->getPayload().size());

  pAdvertising->setScanResponseData(scanResponse);
  pAdvertising->setAdvertisementData(*advData);
  pAdvertising->setAdvertisementType(BLE_GAP_CONN_MODE_NON);

  pAdvertising->start();
  delete advData;
}
