#include<arduino.h>

int buzzer = 8;
#define sw1 2

void setup() {
  pinMode(buzzer,OUTPUT);
  pinMode(sw1,INPUT);
}

void loop() {
  int sw1_state = digitalRead(sw1);

  if(sw1_state==HIGH)
  {
  digitalWrite(buzzer,HIGH);
  delay(1000);
  digitalWrite(buzzer,LOW); 
  }
}
