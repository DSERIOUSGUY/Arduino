#include<ESP8266WiFi.h>
#include<ESP8266HTTPClient.h>
#include<ArduinoJson.h>

const char* ssid = "Agarwals";
const char* psswd = "kjng@4321";

void setup()
{
  Serial.begin(9600);
  WiFi.begin(ssid,psswd);
  Serial.println("Device Starting, attempting connection");
  while(WiFi.status()!= WL_CONNECTED)
  {Serial.print(".");
  delay(1000);}
  Serial.println("Connection Success!");
  
  }

void loop()
{

  if(WiFi.status() == WL_CONNECTED)
  {
    HTTPClient http; 
    http.begin("http://api.weatherstack.com/current?access_key=fee06ab56250f42d1f7d693994fa0e21&query=Noida");
    int httpCode = http.GET();

    if(httpCode > 0)
    {
      const size_t bufferSize = JSON_OBJECT_SIZE(2) + JSON_OBJECT_SIZE(3) + JSON_OBJECT_SIZE(5) + JSON_OBJECT_SIZE(8) + 370;
      DynamicJsonBuffer jsonBuffer(bufferSize);
      JsonObject& root = jsonBuffer.parseObject(http.getString());

      const char* Name=root["request"]["query"];
      const int temp=root["current"]["temperature"];

      Serial.print("name: ");
      Serial.println(Name);
      Serial.print("temp: ");
      Serial.println(temp);
      
      delay(5000);
      
      }
    }
  }
