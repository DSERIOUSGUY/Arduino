#include<SoftwareSerial.h>

SoftwareSerial s(3,1);

void setup() {
  // put your setup code here, to run once:
  s.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  s.write(123);
  delay(1000);
  }
