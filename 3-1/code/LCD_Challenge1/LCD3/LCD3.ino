#include <LiquidCrystal.h>

LiquidCrystal lcd(22,23,24,25,26,27);

void setup(){
  lcd.begin(16,2);
  Serial.begin(9600);
  lcd.print("induk, mecha!");
}
void loop(){
  if(Serial.available()){
    delay(100);
    lcd.clear();
    while(Serial.available()>0){
      char ch = Serial.read();
      lcd.print(ch);
    }
  }
}
