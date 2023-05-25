#include <LiquidCrystal.h>

LiquidCrystal lcd(22,23,24,25,26,27);

void setup(){
  lcd.begin(16,2);
  lcd.print("induk, mecha!");
}
void loop(){
  lcd.setCursor(0,1);
  lcd.print(millis()/1000);
}
