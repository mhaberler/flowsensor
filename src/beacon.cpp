
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

void beacon_setup(void) {
  BLEDevice::init("");
  scanResponse.setAppearance(BLE_APPEARANCE_GENERIC_TAG);
  scanResponse.setFlags(BLE_HS_ADV_F_BREDR_UNSUP | BLE_HS_ADV_F_DISC_GEN);
  scanResponse.setName("FlowSensor");

}

void beacon_update_manufacturer_data(uint8_t *data, size_t size) {

  if (pAdvertising == NULL) {
    pAdvertising = BLEDevice::getAdvertising();
  }
  if (pAdvertising->isAdvertising()) {
    pAdvertising->reset();
  }

  std::string manufacturerData;
  manufacturerData.reserve(size + 2);
  manufacturerData.push_back(MANUFACTURER_ID &
                             0x00ff); // manufacturer ID low byte
  manufacturerData.push_back((MANUFACTURER_ID >> 8) &
                             0x00ff); // manufacturer ID high byte
  for (auto i = 0; i < size; i++) {
    manufacturerData.push_back(data[i]);
  }
  advData = new BLEAdvertisementData();

  advData->setManufacturerData(manufacturerData);
  Serial.printf("payload size=%u\n", advData->getPayload().size());

  pAdvertising->setScanResponseData(scanResponse);
  pAdvertising->setAdvertisementData(*advData);
  pAdvertising->setAdvertisementType(BLE_GAP_CONN_MODE_NON);

  pAdvertising->start();
  delete advData;
}
