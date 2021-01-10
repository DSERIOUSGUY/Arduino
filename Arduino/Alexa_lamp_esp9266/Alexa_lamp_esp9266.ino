#include<Arduino.h>
#include<ESP8266WiFi.h>
#include "fauxmoESP.h"


#define WIFI_SSID "Agarwals"
#define WIFI_PSSWD "kjng@4321"
#define SERIAL_BAUD_RATE 9600
#define LAMP "lamp"

uint8_t d4 = D5;

fauxmoESP fauxmo;


//setup for wifi
void WiFiSetup()
{
  //starting station mode
  Serial.println("Station Mode");
  WiFi.mode(WIFI_STA);

  //connecting to wifi  
  WiFi.begin(WIFI_SSID,WIFI_PSSWD);
  Serial.println("connecting");
  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("Connected, IP ADDRESS: ");
  Serial.println(WiFi.localIP());
  }

  void setup()
  {
    Serial.begin(SERIAL_BAUD_RATE);
    WiFiSetup();

    //setting output pin
    pinMode(d4,OUTPUT);
    digitalWrite(d4,LOW);

    //creating web server
    fauxmo.createServer(true);
    //setting port to 80 for gen3 devices (set to 1901 by default)
    fauxmo.setPort(80);

    //enabling library so that device is discoverable
    fauxmo.enable(true);

    //adding devices to be discoved
    fauxmo.addDevice(LAMP);

  

    // Callback when a command from Alexa is received. 
    // You can use device_id or device_name to choose the element to perform an action onto (relay, LED,...)
    // State is a boolean (ON/OFF) and value a number from 0 to 255 (if you say "set kitchen light to 50%" you will receive a 128 here).
    // Just remember not to delay too much here, this is a callback, exit as soon as possible.
    // If you have to do something more involved here set a flag and process it in your main loop.
    fauxmo.onSetState([](unsigned char device_id, const char* device_name, bool state, unsigned value)
    {
    
      if(strcmp(device_name,LAMP)==0)
        {
          if(state)
            digitalWrite(d4,HIGH);
          else
            digitalWrite(d4,LOW);
          }
      });

      
      }

      

    

  void loop()
  {
  // fauxmoESP uses an async TCP server but a sync UDP server
  // Therefore, we have to manually poll for UDP packets
    fauxmo.handle();

    static unsigned long last = millis();
    if(millis() - last>5000)
    {
      Serial.printf("[MAIN] Free heap: %d bytes\n", ESP.getFreeHeap());
      }

    delay(600);  
    
   }
