/* Wi-Fi STA Connect and Disconnect Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.

*/
#include <WiFi.h>
#include <WiFiUdp.h>
#include <WakeOnLan.h>

WiFiUDP UDP;
WakeOnLan WOL(UDP);

const char *ssid = "WIFI_SSID";
const char *password = "WIFI_PASS";
uint8_t MAC[6] = {0x04, 0x7C, 0x16, 0xBE, 0xA8, 0xBE}; 
uint8_t magic_packet_gpio = 13;

int trigger = LOW;

void setup() {
  Serial.begin(115200);
  delay(10);

  pinMode(magic_packet_gpio, INPUT);

  WOL.setRepeat(3, 100);

  WiFi.begin(ssid, password);

  // Will try for about 3 seconds (20x 500ms)
  int tryDelay = 500;
  int numberOfTries = 6;

  // Wait for the WiFi event
   while (true) {

    switch (WiFi.status()) {
      case WL_NO_SSID_AVAIL: Serial.println("[WiFi] SSID not found"); break;
      case WL_CONNECT_FAILED:
        Serial.print("[WiFi] Failed - WiFi not connected! Reason: ");
        return;
        break;
      case WL_CONNECTION_LOST: Serial.println("[WiFi] Connection was lost"); break;
      case WL_SCAN_COMPLETED:  Serial.println("[WiFi] Scan is completed"); break;
      case WL_DISCONNECTED:    Serial.println("[WiFi] WiFi is disconnected"); break;
      case WL_CONNECTED:
        Serial.println("[WiFi] WiFi is connected!");
        Serial.print("[WiFi] IP address: ");
        Serial.println(WiFi.localIP());
        return;
        break;
      default:
        Serial.print("[WiFi] WiFi Status: ");
        Serial.println(WiFi.status());
        break;
    }
    delay(tryDelay);

    if (numberOfTries <= 0) {
      Serial.print("[WiFi] Failed to connect to WiFi!");
      // Use disconnect function to force stop trying to connect
      WiFi.disconnect();
      return;
    } else {
      numberOfTries--;
    }
  }

}

void loop() {
  // Read the button state
  trigger = digitalRead(magic_packet_gpio);

  if (trigger) {
    WOL.sendMagicPacket(MAC, sizeof(MAC));
    Serial.println("Triggered");
    delay(5000);
  } else {
    delay(100);
  }

}
