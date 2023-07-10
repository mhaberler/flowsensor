
#include "beacon.h"
#include "NimBLEBeacon.h"
#include "NimBLEDevice.h"
#include "esp_sleep.h"
#include "sys/time.h"



#define SERVICE_UUID "4faf"
static NimBLEUUID dataUuid(SERVICE_UUID);

static BLEAdvertisementData *advData;
static BLEAdvertisementData scanResponse = BLEAdvertisementData();
static BLEAdvertising *pAdvertising;

static char g_devName[32] = {0};

const uint8_t *beacon_setup(void) {
  uint8_t devAddrArray[6] = {0};

  BLEDevice::init("");
  memcpy(devAddrArray, BLEDevice::getAddress().getNative(), 6);
  snprintf(g_devName, 32, "%s%02X%02X%02X", BLE_PREFIX, devAddrArray[2], devAddrArray[1],
           devAddrArray[0]);

  BLEDevice::deinit();
  BLEDevice::init(g_devName);

  if (pAdvertising == NULL) {
    pAdvertising = BLEDevice::getAdvertising();
  }
  // scanResponse.setCompleteServices16({NimBLEUUID(SERVICE_UUID)});
  scanResponse.setAppearance(BLE_APPEARANCE_GENERIC_TAG);
  scanResponse.setFlags(BLE_HS_ADV_F_BREDR_UNSUP | BLE_HS_ADV_F_DISC_GEN);
  scanResponse.setName(g_devName);

  return BLEDevice::getAddress().getNative();
}

void beacon_update_manufacturer_data(uint8_t *data, size_t size) {

  if (advData) {
    delete advData;
    advData = NULL;
  }
  advData = new BLEAdvertisementData();
  std::string manufacturerData((char *)data, size);
  advData->setManufacturerData(manufacturerData);
  advData->setCompleteServices16({NimBLEUUID(SERVICE_UUID)});

  if (pAdvertising->isAdvertising()) {
    pAdvertising->reset();
  } else {
    pAdvertising->setScanResponseData(scanResponse);
    pAdvertising->setAdvertisementData(*advData);
    pAdvertising->setAdvertisementType(BLE_GAP_CONN_MODE_NON);
#if 0
    pAdvertising-> setMaxInterval(uint16_t maxinterval);
    pAdvertising-> setMinInterval(uint16_t mininterval);
#endif
    pAdvertising->start();
  }
}
