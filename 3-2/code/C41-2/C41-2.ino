#include <MsTimer2.h>

int sw;
int int_sw = 2;
int led1 = 22;
int led2 = 24;
int led1_state = HIGH;

void setup() {
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(int_sw,INPUT_PULLUP);
  MsTimer2::set(2000,timer0);
  MsTimer2::start();    // stop으로 멈춤
}

void loop() { // 2초에 한 번씩 ON OFF
  sw = digitalRead(2);
  
  if(sw==HIGH)    // timer 인터럽트를 통해 스위치를 눌러도 인식 가능
    digitalWrite(led2, LOW);
  else
    digitalWrite(led2, HIGH);
}

void timer0(){
  if(led1_state == HIGH){
    digitalWrite(led1, led1_state);
  }
  if(led1_state == LOW){
    digitalWrite(led1, led1_state);
  }
  led1_state =! led1_state;
}
