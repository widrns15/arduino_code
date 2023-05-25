// 문제 2번 MsTimer2 사용

#include <MsTimer2.h>

int sw;
int int_sw = 2;
int led1 = 22;
int led2 = 24;
int led1_state = HIGH;
int led2_state = LOW;

void setup() {
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(int_sw,INPUT_PULLUP);
  MsTimer2::set(2000,timer0);
  MsTimer2::start();    // stop으로 멈춤
}

void loop() { // 2초에 한 번씩 ON OFF
  sw = digitalRead(2);
  
  if(sw==LOW)    // timer 인터럽트를 통해 스위치를 눌러도 인식 가능
    {
      digitalWrite(7, HIGH);
      delay(100);
      digitalWrite(7, LOW);
    }
}

void timer0(){
  if(led1_state == HIGH){
    digitalWrite(led1, led1_state);
  }
  if(led1_state == LOW){
    digitalWrite(led1, led1_state);
  }
  led1_state =! led1_state;

  if(led2_state == HIGH){
    digitalWrite(led2, led2_state);
  }
  if(led2_state == LOW){
    digitalWrite(led2, led2_state);
  }
  led2_state =! led2_state;
}


/* 문제 3번 TimerOne 사용

#include <TimerOne.h>

void setup() {
  pinMode(22,OUTPUT);
  pinMode(24,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(2,INPUT_PULLUP);

  Timer1.attachInterrupt( timerIsr );
}

void loop() {
  digitalRead(2);
  
  if(digitalRead(2)==LOW){    // 풀업 구성 시
      digitalWrite(7, HIGH);
      delay(100);
      digitalWrite(7, LOW);
    }
}

void timerIsr () {
  // Toggle LED = 반전
  digitalWrite(22,digitalRead(22)^1);
  Timer1.initialize(2000000);
  digitalWrite(24,digitalRead(22)^1);
}
*/
