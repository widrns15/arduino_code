#include <LiquidCrystal.h>

LiquidCrystal lcd(22,23,24,25,26,27);

int i=0;

void setup() {
  lcd.begin(16,2);
}

void loop(){
    while(1){
    lcd.setCursor(i,0);
    lcd.print("KOREA Fighting!");
    
    lcd.setCursor(16-i,1);
    lcd.print("induk university!");

    delay(500);
    
    i++;
    
    lcd.clear();

    if(i==16){
      i=0;
    }
    }
}
