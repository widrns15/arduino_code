#include <LiquidCrystal.h>

LiquidCrystal lcd(22,23,24,25,26,27);

void setup() {
  lcd.begin(16,2);
  pinMode(32,HIGH);
}

void loop() {
 lcd.setCursor(0,0);
 lcd.print("Mecha");
 for(int j=0; j<3; j++){
  for(int i = 0; i < 11; i++){
  lcd.scrollDisplayRight();
  delay(500);
   if(digitalRead(32)==HIGH){
    while(1){
    lcd.clear();
    lcd.setCursor(0,2);
    lcd.print(millis()/1000);  
    }
  }
  }
   for(int i = 0; i < 11; i++){
  lcd.scrollDisplayLeft();
  delay(500);
   if(digitalRead(32)==HIGH){
    while(1){
    lcd.clear();
    lcd.setCursor(0,2);
    lcd.print(millis()/1000);  
    }
  }
  }

 }
}
