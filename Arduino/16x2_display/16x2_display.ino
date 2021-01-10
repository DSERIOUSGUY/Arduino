//operating in 4 bit mode: require RS, E, D4-D7 for inputs
//use a potentiometer (knob thingy) for Vo input
//only writing data to display, therefore RW set LOW
//VSS set LOW (GND)
//VDD set HIGH (Vcc)
//A,K - Anode, Cathode : Anode connects via 10 kohm to HIGH, cathode set to LOW
//** format for setCursor(cols,rows)


#include<LiquidCrystal.h>

//creating a liquid crystal object(RS,E,D4,D5,D6,D7);
LiquidCrystal lcd(12,11,5,4,3,2);


//creating custom characters - only 8(max) can be stored at a time 
byte gun[8]{
  0b00000,
  0b00000,
  0b01111,
  0b11110,
  0b11000,
  0b11000,
  0b00000,
  0b00000
};

byte stickFigRun[8]{
  0b01100,
  0b11110,
  0b11110,
  0b01000,
  0b01111,
  0b11100,
  0b01010,
  0b01001
};


byte bullet[8]{
  0b00000,
  0b00000,
  0b00100,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};


byte blank[8]{
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};


byte burst[8]{
  0b01001,
  0b00000,
  0b00011,
  0b00001,
  0b00011,
  0b00000,
  0b01001,
  0b00000
};



void setup()
{
  lcd.begin(16,2); //(rows,cols)
  lcd.createChar(0,gun);
  lcd.createChar(1,stickFigRun);
  lcd.createChar(2,bullet);
  lcd.createChar(3,blank);
  lcd.createChar(4,burst);
  lcd.clear();
  }

void loop()
{
  lcd.setCursor(0,0); 
  lcd.print("Pew! Pew!");

  lcd.setCursor(8,1);
  lcd.write(byte(0));
  lcd.setCursor(7,1);
  lcd.write(byte(1));

  for(int i=9; i<16; i++)
  { 
    if(i>9)
    {
    lcd.setCursor(i-1,1);
    lcd.write(byte(3));
      }
    lcd.setCursor(i,1);
    lcd.write(byte(2));
    delay(50);
    }

    
    lcd.setCursor(15,1);
    lcd.write(byte(4));

    delay(500);
    
    lcd.setCursor(15,1);
    lcd.write(byte(3));
  


  //delay(1000);
  //lcd.scrollDisplayLeft();

  delay(1000);
  //lcd.clear();
  }
