#include <LiquidCrystal.h>

LiquidCrystal lcd(22,23,24,25,26,27);

void setup() {
  lcd.begin(16,2);

}

void loop() {
  lcd.print("induk university");

  while(1){
    lcd.scrollDisplayLeft();
    delay(500);
  }
}
