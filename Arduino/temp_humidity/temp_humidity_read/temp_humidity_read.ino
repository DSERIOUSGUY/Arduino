//header files
#include<dht.h>

//constants
int data = 8;
int readData = 0;
float t=0;
float h=0;
dht DHT;

void setup() {
  // put your setup code here, to run once:
  pinMode(data,INPUT);
  Serial.begin(9600);
  Serial.print("Initializing device \n");
  for(int i = 0; i<5; i++)
  {
    Serial.print("#");
    delay(1000); //global reset time
  }
  Serial.print("\n Device ready");
  
}


void loop() {
  // put your main code here, to run repeatedly:
  readData   = DHT.read11(data);
  
  t = DHT.temperature;
  h = DHT.humidity;

  Serial.print("\n temp in F ");
  Serial.print((t * 9.0) / 5.0 + 32.0);
  
  Serial.print("\n humidity in % ");
  Serial.print(h);
  
  
  Serial.print("\n ------------");
  delay(1000);
  
  

}
