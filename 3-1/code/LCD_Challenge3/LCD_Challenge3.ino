#include <LiquidCrystal.h>

LiquidCrystal lcd(22,23,24,25,26,27);

void setup(){
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  Serial.begin(9600);
}

void loop(){
  int i=1,k,j;
  
  if(Serial.available()){
    delay(100);
    if(i=1){
    while(Serial.available()>0){
      char ch=Serial.read();
      lcd.print(ch);
      k=1;
    }
    if(k=1){
      i=2;
      lcd.home();
    }
    }
    if(i=2){
      lcd.setCursor(0,1);
      while(Serial.available()>0){
      char ch=Serial.read();
      lcd.print(ch);
      j=1;
    }
    if(j=1){
      i=1;
    }
  }
}
}
