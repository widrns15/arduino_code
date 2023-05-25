#include <LiquidCrystal.h>

LiquidCrystal lcd(22,23,24,25,26,27);

void setup() {
  lcd.begin(16,2);

}

void loop() {
  lcd.setCursor(0,1);
  lcd.print("KOREA Fighting!");
  for(int i=0; i<6; i++){
    lcd.scrollDisplayRight();
    delay(500);
  }
  lcd.setCursor(16,2);
  lcd.print("KOREA Fighting!");
  for(int j=0; j<6; j++){
    lcd.scrollDisplayLeft();
    delay(500);
  }
}
