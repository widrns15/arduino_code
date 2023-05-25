#include <LiquidCrystal.h>

LiquidCrystal lcd(22,23,24,25,26,27);

void setup() {
  lcd.begin(16,2);

}

void loop() {
  lcd.setCursor(1,1);
  lcd.print("induk!!!");
  for(int i=0; i<6; i++){
    lcd.scrollDisplayRight();
    delay(500);
  }
  for(int j=0; j<6; j++){
    lcd.scrollDisplayLeft();
    delay(500);
  }
}
