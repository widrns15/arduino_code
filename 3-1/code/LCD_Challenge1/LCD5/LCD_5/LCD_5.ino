#include <LiquidCrystal.h>

LiquidCrystal lcd(22,23,24,25,26,27);

void setup(){
  lcd.begin(16,2);
}
void loop(){
   int i = 0;
   int j = 16; 
   while(1){
    lcd.setCursor(i,0);
    lcd.print("KORA FIGHTING!");
    for(int i =0; i<=16; i++){
      lcd.scrollDisplayRight();
      delay(500);
    }
    lcd.setCursor(j,1);
    lcd.print("induk university!");
      for(int j=16; j<=0; j--){
      lcd.scrollDisplayLeft();
      delay(500);
    }
}
}
