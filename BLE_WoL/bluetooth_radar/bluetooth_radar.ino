/*
   Based on Neil Kolban example for IDF: https://github.com/nkolban/esp32-snippets/blob/master/cpp_utils/tests/BLE%20Tests/SampleScan.cpp
   Ported to Arduino ESP32 by Evandro Copercini
   Changed to a beacon scanner to report iBeacon, EddystoneURL and EddystoneTLM beacons by beegee-tokyo
   Upgraded Eddystone part by Tomas Pilny on Feb 20, 2023
*/

#include <Arduino.h>

#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>
#include <BLEBeacon.h>
#include <vector>

int scanTime = 5;  //In seconds
BLEScan *pBLEScan;

// const char *ssid = "VM0523484";
// const char *password = "gmnj3jbHbntf";

std::vector<String> trusted_UUIDs = {
                                      "00001812-0000-1000-8000-00805f9b34fb",
                                    };

void trigger_magic()
{
  //Set pin to output and read it as an input on the second board.
  //second board first checks if the PC/server is alive, if not, only 
  //then send a magic packet.

  Serial.println("Triggered");
  digitalWrite(13, HIGH);


  //OR
  //just use the second device as storage which sends data via tx/rx
  //upon request. Keep wifi and bluetooth both here only. Keep updating
  //with OTA
}

class MyAdvertisedDeviceCallbacks : public BLEAdvertisedDeviceCallbacks {
  void onResult(BLEAdvertisedDevice advertisedDevice) {
    if (advertisedDevice.haveServiceUUID()) {
      BLEUUID devUUID = advertisedDevice.getServiceUUID();
      
      if (std::find(trusted_UUIDs.begin(), trusted_UUIDs.end(), devUUID.toString()) != trusted_UUIDs.end())
        trigger_magic();
    }
  }
};

void setup() {
  Serial.begin(115200);
  //WiFi.begin(ssid, password);

  BLEDevice::init("");
  pBLEScan = BLEDevice::getScan();  //create new scan
  pBLEScan->setAdvertisedDeviceCallbacks(new MyAdvertisedDeviceCallbacks());
  pBLEScan->setActiveScan(true);  //active scan uses more power, but get results faster
  pBLEScan->setInterval(100);
  pBLEScan->setWindow(99);  // less or equal setInterval value

  //Pin 13 triggers magic packet
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW); 
  Serial.println("Starting");
}

void loop() {
  // put your main code here, to run repeatedly:
  BLEScanResults *foundDevices = pBLEScan->start(scanTime, false);
  pBLEScan->clearResults();  // delete results fromBLEScan buffer to release memory
  delay(5000);
  digitalWrite(13, LOW);
}



//Xbox Wireless Controller
