#include <TimerOne.h>


void setup() {
  pinMode(22,OUTPUT);

  Timer1.initialize(100000);  // 0.1초
  Timer1.attachInterrupt( timerIsr );
}

void loop() {
  
}

void timerIsr () {
  // Toggle LED = 반전
  digitalWrite(22,digitalRead(22)^1);
}
