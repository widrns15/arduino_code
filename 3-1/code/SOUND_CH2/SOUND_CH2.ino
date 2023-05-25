#include <LiquidCrystal.h>

LiquidCrystal lcd(22,23,24,25,26,27); 

int sound = 32;
int LED = 28;
int LED1 = 29;

void setup(){
  pinMode(28,OUTPUT);
  pinMode(29,OUTPUT);
  pinMode(32,INPUT);
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("LOGIN");
}

void loop(){
  int i,k;
  if(digitalRead(32) == HIGH){
    digitalWrite(28,HIGH);
    lcd.clear();
    lcd.print("LIGHT ON");
    delay(200);
    i = 1;
    if(digitalRead(32) == LOW){
    if(i=1){
    digitalWrite(28,LOW);
    lcd.clear();
    lcd.print("LIGHT OFF");
    delay(200);
    }
    }
    }
}
  
