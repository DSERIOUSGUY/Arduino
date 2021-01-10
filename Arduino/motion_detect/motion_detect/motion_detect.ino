//constants 
const int ledPin = 13, mPin = 12;
const int setUpTime = 5;
//variables
bool lowLock = 0;


//setup
void setup()
{


 
  Serial.begin(9600);
  Serial.print("Setting up sensor");
  Serial.println();
  digitalWrite(ledPin,LOW);
  digitalWrite(mPin,LOW);
  for(int i = 0; i<setUpTime; i++)
  {
    Serial.print("#");
    delay(1000);
    }
  Serial.println();  
  Serial.print("caliberation done");
  Serial.println();
  
  }

  //loop
  void loop()
  {
    delay(3000);
    Serial.print("\n ready");
    Serial.println();
    lowLock = digitalRead(mPin);
    while(lowLock==digitalRead(mPin))
      { lowLock = digitalRead(mPin);
        digitalWrite(ledPin,LOW);
        }
    digitalWrite(ledPin,HIGH);
    Serial.print("Motion Detected at ");
    Serial.print(millis()/1000);
    Serial.print(" secs");
    delay(1000);
    //Serial.print
    Serial.print("\n resetting");
    digitalWrite(ledPin,LOW);

    }
