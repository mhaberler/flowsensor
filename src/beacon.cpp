
#include "Ticker.h"
#include <Arduino.h>

#include "NimBLEBeacon.h"
#include "NimBLEDevice.h"
#include "esp_sleep.h"
#include "sys/time.h"
#include <stddef.h>
#include <stdint.h>
#include <string>

#define SERVICE_UUID "4faf"
static NimBLEUUID dataUuid(SERVICE_UUID);
static NimBLEDevice dev;
static char g_devName[32] = {0};

static std::string adr;

#if CONFIG_BT_NIMBLE_EXT_ADV
static NimBLEExtAdvertisement *advData;
static NimBLEExtAdvertisement scanResponse =
    NimBLEExtAdvertisement(BLE_HCI_LE_PHY_1M, BLE_HCI_LE_PHY_2M);
static NimBLEExtAdvertising *pAdvertising;

/* Callback class to handle advertising events */
class advCallbacks : public NimBLEExtAdvertisingCallbacks {
  void onStopped(NimBLEExtAdvertising *pAdv, int reason, uint8_t inst_id) {
    /* Check the reason advertising stopped, don't sleep if client is connecting
     */
    printf("Advertising instance %u stopped\n", 0);
    switch (reason) {
    case 0:
      printf(" client connecting\n");
      return;
    case BLE_HS_ETIMEOUT:
      printf("Time expired \n");
      break;
    default:
      break;
    }

    // esp_deep_sleep_start();
  }
  bool m_updatedSR = false;
  void onScanRequest(NimBLEExtAdvertising *pAdv, uint8_t inst_id,
                     NimBLEAddress addr) {
    printf("Scan request for instance %u\n", inst_id);
    // if the data has already been updated we don't need to change it again.
    if (!m_updatedSR) {
      printf("Updating scan data\n");
      NimBLEExtAdvertisement sr;
      sr.setServiceData(NimBLEUUID(SERVICE_UUID),
                        std::string("Hello from scan response!"));
      pAdv->setScanResponseData(inst_id, sr);
      m_updatedSR = true;
    }
  }
};

const std::string beacon_setup(void) {
  uint8_t devAddrArray[6] = {0};

  dev.init("");
  memcpy(devAddrArray, BLEDevice::getAddress().getNative(), 6);
  snprintf(g_devName, 32, "%s%02X%02X%02X", BLE_PREFIX, devAddrArray[2],
           devAddrArray[1], devAddrArray[0]);

  dev.deinit();
  dev.init(g_devName);
  uint16_t mtu = dev.getMTU();
  printf("MTU: %d\n", mtu);

  if (pAdvertising == NULL) {
    pAdvertising = BLEDevice::getAdvertising();
  }

  // scanResponse.setCompleteServices16({NimBLEUUID(SERVICE_UUID)});
  scanResponse.setAppearance(BLE_APPEARANCE_GENERIC_TAG);
  scanResponse.setFlags(BLE_HS_ADV_F_BREDR_UNSUP | BLE_HS_ADV_F_DISC_GEN);
  scanResponse.setName(g_devName);
  scanResponse.setLegacyAdvertising(false);
  scanResponse.setScannable(true);
  scanResponse.setConnectable(false);

  std::string result;
  result.assign((const char *)BLEDevice::getAddress().getNative(), 6);
  return result;
}

void beacon_update_manufacturer_data(const char *data, size_t size) {

  if (advData) {
    delete advData;
    advData = NULL;
  }
  advData = new NimBLEExtAdvertisement(BLE_HCI_LE_PHY_1M, BLE_HCI_LE_PHY_2M);
  std::string manufacturerData((char *)data, size);
  advData->setManufacturerData(manufacturerData);
  advData->setCompleteServices16({NimBLEUUID(SERVICE_UUID)});
  advData->setName(g_devName);
  advData->setFlags(BLE_HS_ADV_F_BREDR_UNSUP | BLE_HS_ADV_F_DISC_GEN);
  // advData->setAppearance(BLE_APPEARANCE_GENERIC_TAG);
  advData->setLegacyAdvertising(false);
  advData->enableScanRequestCallback(true);

  if (pAdvertising->isAdvertising()) {
    printf("stopped advertising\n");
    pAdvertising->stop(0);
  } else {
    // pAdvertising->setScanResponseData(0, scanResponse);
    pAdvertising->setCallbacks(new advCallbacks);
    pAdvertising->setInstanceData(0, *advData);

    bool rc = pAdvertising->start(0);
    printf("started advertising: %s\n", rc ? "OK" : "FAILED");
  }
}

#else

static BLEAdvertisementData *advData;
static BLEAdvertisementData scanResponse = BLEAdvertisementData();
static BLEAdvertising *pAdvertising;

const std::string beacon_setup(void) {
  uint8_t devAddrArray[6] = {0};

  dev.init("");
  memcpy(devAddrArray, BLEDevice::getAddress().getNative(), 6);
  snprintf(g_devName, 32, "%s%02X%02X%02X", BLE_PREFIX, devAddrArray[2],
           devAddrArray[1], devAddrArray[0]);

  dev.deinit();
  dev.init(g_devName);
  uint16_t mtu = dev.getMTU();
  printf("MTU: %d\n", mtu);

  if (pAdvertising == NULL) {
    pAdvertising = BLEDevice::getAdvertising();
  }
  // scanResponse.setCompleteServices16({NimBLEUUID(SERVICE_UUID)});
  // scanResponse.setAppearance(BLE_APPEARANCE_GENERIC_TAG);
  scanResponse.setFlags(BLE_HS_ADV_F_BREDR_UNSUP | BLE_HS_ADV_F_DISC_GEN);
  scanResponse.setName(g_devName);

  std::string result;
  result.assign((const char *)BLEDevice::getAddress().getNative(), 6);
  return result;
}

void beacon_update_manufacturer_data(const char *data, size_t size) {

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
    // pAdvertising->setScanResponseData(scanResponse);
    pAdvertising->setAdvertisementData(*advData);
    pAdvertising->setAdvertisementType(BLE_GAP_CONN_MODE_NON);
    pAdvertising->start();
  }
}
#endif

Ticker sampler;

void setup() {
  delay(3000);
  Serial.begin(115200);
#if CONFIG_BT_NIMBLE_EXT_ADV
  printf("startup CONFIG_BT_NIMBLE_EXT_ADV\n");
#else
  printf("startup ble4x\n");
#endif
  adr = beacon_setup();
}

void loop() {

#if CONFIG_BT_NIMBLE_EXT_ADV
  const char *mfd =
      "\x11\x47The quick brown fox jumps over the lazy dog The quick "
      "brown fox jumps over the lazy dog";
#else
  const char *mfd = "\x11\x47hi there";
#endif
  const size_t len = strlen(mfd);

  beacon_update_manufacturer_data(mfd, len);

  delay(1000);
}
