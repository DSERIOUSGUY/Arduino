#include <ESP8266WiFi.h>

const char *ssid = "Agarwals";
const char *pass = "kjng@4321";

void setup()
{
  Serial.begin(9600);
  delay(1000);
  
  Serial.print("\n connecting to: ");
  Serial.print(ssid);
  Serial.println();

  WiFi.begin(ssid,pass);
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print("WiFi Status: ");
    Serial.println(WiFi.status());
    }
    Serial.print("\n now connected to Agarwals");
    Serial.print("\n ip address: ");
    Serial.print(WiFi.localIP());
    WiFi.printDiag(Serial);
  }

  void loop(){}
