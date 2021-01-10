
 const int ledPin1 = 13, ledPin2 = 12, inputPin = 2;
//connect pin 13 to ledr
//connect pin 12 to ledb
//connect pin 2 to IR

void setup() {
  // put your setup code here, to run once:
  pinMode(inputPin,INPUT);
  pinMode(ledPin1,OUTPUT);
  pinMode(ledPin2,OUTPUT);
  digitalWrite(ledPin1,LOW);
  digitalWrite(ledPin2,LOW);
   Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  if(digitalRead(inputPin)==HIGH)
    {
      digitalWrite(ledPin1,LOW);
      digitalWrite(ledPin2,LOW);
    }
  else
    {for(int i =0;i<50;i++)
    {
      digitalWrite(ledPin2,LOW);
      digitalWrite(ledPin1,HIGH);
      Serial.println();
      Serial.print(inputPin);
      delay(50);
      digitalWrite(ledPin1,LOW);
      digitalWrite(ledPin2,HIGH);
      delay(50);
    }
    }
  delay(10);
  digitalWrite(ledPin1,LOW);
  digitalWrite(ledPin2,LOW);
}
