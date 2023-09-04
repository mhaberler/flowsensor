
#include "beacon.h"
#include "NimBLEBeacon.h"
#include "NimBLEDevice.h"
#include "esp_sleep.h"
#include "sys/time.h"

#define SERVICE_UUID "4faf"
static NimBLEUUID dataUuid(SERVICE_UUID);

/* Primary PHY used for advertising, can be one of BLE_HCI_LE_PHY_1M or
 * BLE_HCI_LE_PHY_CODED */
static uint8_t primaryPhy = BLE_HCI_LE_PHY_CODED;

/* Secondary PHY used for advertising and connecting,
 * can be one of BLE_HCI_LE_PHY_1M, BLE_HCI_LE_PHY_2M or BLE_HCI_LE_PHY_CODED
 */
static uint8_t secondaryPhy = BLE_HCI_LE_PHY_1M;

static NimBLEExtAdvertisement *advData;
static NimBLEExtAdvertisement scanResponse =
    NimBLEExtAdvertisement(primaryPhy, secondaryPhy);
static NimBLEExtAdvertising *pAdvertising;

uint8_t inst_id = 0;

static char g_devName[32] = {0};

/* Callback class to handle advertising events */
class advCallbacks : public NimBLEExtAdvertisingCallbacks {
  void onStopped(NimBLEExtAdvertising *pAdv, int reason, uint8_t inst_id) {
    /* Check the reason advertising stopped, don't sleep if client is connecting
     */
    printf("Advertising instance %u stopped\n", inst_id);
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

  NimBLEDevice::init("");
  memcpy(devAddrArray, BLEDevice::getAddress().getNative(), 6);
  snprintf(g_devName, 32, "%s%02X%02X%02X", BLE_PREFIX, devAddrArray[2],
           devAddrArray[1], devAddrArray[0]);

  NimBLEDevice::deinit();
  NimBLEDevice::init(g_devName);

  if (pAdvertising == NULL) {
    pAdvertising = BLEDevice::getAdvertising();
  }
  pAdvertising->setCallbacks(new advCallbacks);

  // scanResponse.setCompleteServices16({NimBLEUUID(SERVICE_UUID)});
  scanResponse.setAppearance(BLE_APPEARANCE_GENERIC_TAG);
  scanResponse.setFlags(BLE_HS_ADV_F_BREDR_UNSUP | BLE_HS_ADV_F_DISC_GEN);
  scanResponse.setName(g_devName);
  scanResponse.setScannable(true);
  scanResponse.setConnectable(false);

  std::string result;
  result.assign((const char *)BLEDevice::getAddress().getNative(), 6);
  return result;
}

void beacon_update_manufacturer_data(uint8_t *data, size_t size) {

  if (advData) {
    delete advData;
    advData = NULL;
  }
  advData = new NimBLEExtAdvertisement();
  std::string manufacturerData((char *)data, size+100);
  advData->setManufacturerData(manufacturerData);
  advData->setCompleteServices16({NimBLEUUID(SERVICE_UUID)});
  advData->setName(g_devName);

  if (pAdvertising->isAdvertising()) {
    pAdvertising->stop(inst_id);
  } else {
    pAdvertising->setScanResponseData(inst_id, scanResponse);
    pAdvertising->setInstanceData(inst_id, *advData);

    pAdvertising->start(inst_id);
  }
}
