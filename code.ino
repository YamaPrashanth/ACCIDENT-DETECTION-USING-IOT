#include<LiquidCrystal.h>
const int rs=13,en=12,d4=11,d5=10,d6=9,d7=8;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
void setup() 
{
  lcd.begin(16,2);
  Serial.begin(9600);
  pinMode(2,INPUT); //vibrationsensor
  pinMode(7,OUTPUT); //Buzzer
}
void loop() 
{
  int val=digitalRead(2);
  if(val==HIGH)
  {
    lcd.print("Alert");
    Serial.println("Alert");
    digitalWrite(7,HIGH);
    delay(1000);
    lcd.clear();
  }
  else
  {
    lcd.print("Safe");
    Serial.println("Safe");
    digitalWrite(7,LOW);
    delay(1000);
    lcd.clear();
  }
}
