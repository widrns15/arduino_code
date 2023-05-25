#include <LiquidCrystal.h>

LiquidCrystal lcd(22,23,24,25,26,27);

int s,x=0;

void setup() {
  lcd.begin(16,2);
  pinMode(32,HIGH);
}

void loop() {
  lcd.setCursor(6,0);
 lcd.print("INDUK");
 
 for(int j=0; j<3; j++){
 
  for(int i = 0; i < 3; i++){
  if(s<24){
    lcd.setCursor(6,1);
    lcd.print(millis()/1000);
    s++;
    delay(500);
    if(x<18){
    lcd.scrollDisplayRight();
  delay(500);
  x++;
    }
  }
 }

  
   for(int i = 0; i < 3; i++){
   if(s<24){
    lcd.setCursor(6,1);
    lcd.print(millis()/1000); 
     s++;
     delay(500);
     if(x<18){
  lcd.scrollDisplayLeft();
  delay(500);
  x++;
  }
  }
}
 }
 }
