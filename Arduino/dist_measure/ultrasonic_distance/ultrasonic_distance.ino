//constants 
const int trig = 3, echo = 2;
//variables
bool flag = false;
float time_taken = 0;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
  Serial.print("device initiated \n");
  digitalWrite(echo,HIGH);
  digitalWrite(trig,LOW);
  for(int i=0; i<5; i++)
    { 
      Serial.print("#");
      delay(200);
      }
      Serial.print("\nsensor initiated");
}

void loop() {
  // put your main code here, to run repeatedly:
   digitalWrite(trig, HIGH);
   delayMicroseconds(10);
   digitalWrite(trig,LOW);
   Serial.print("\nwave triggered");
   
   time_taken = pulseIn(echo, HIGH);
   

  //gets distance travelled
  Serial.print("\n distance = ");
  Serial.print((time_taken/2000000)*343);
  Serial.print(" m");
  //gets time taken for signal to be recieved
  Serial.print("\n propagation time = ");
  Serial.print((time_taken/1000));
  Serial.print(" ms");

  delay(5000);
  
  
}
