#include<ESP8266WiFi.h>
#include<ESP8266mDNS.h>
#include<WiFiUdp.h>
#include<ArduinoOTA.h>

//network creds
const char *ssid = "Agarwals";
const char *psswd = "kjng@4321";

 uint8_t LED_Pin = D4; 


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("booting");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid,psswd);
  while(WiFi.status()!= WL_CONNECTED)
  {
    Serial.print(".");
    delay(1000);
    }

    ArduinoOTA.onStart([]()
    {
      Serial.println("\nstart");}
    );
  ArduinoOTA.onEnd([]()
  {
    Serial.println("\nend");
    });

    ArduinoOTA.onProgress([](unsigned int progress, unsigned int total)
    {
      Serial.printf("Progress: %u%%\r",(progress/(total/100)));
      });

    ArduinoOTA.onError([](ota_error_t error){
      Serial.printf("Error[%u]:",error);
      if(error == OTA_AUTH_ERROR) Serial.println("AUTH FAILED!");
      else if(error == OTA_BEGIN_ERROR) Serial.println("BEGIN FAILED!");
      else if(error == OTA_CONNECT_ERROR) Serial.println("CONNECT FAILED!");
      else if(error == OTA_RECEIVE_ERROR) Serial.println("RECEIVE FAILED!");
      else if(error == OTA_END_ERROR) Serial.println("END FAILED!");
      });

      ArduinoOTA.begin();
      Serial.println("Ready");
      Serial.print("IP: ");
      Serial.print(WiFi.localIP());   
      pinMode(LED_Pin, OUTPUT); 
}

void loop() {
  ArduinoOTA.handle();
  digitalWrite(LED_Pin, HIGH);

}
