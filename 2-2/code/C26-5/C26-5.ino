#include<Servo.h>
Servo myservo;

void setup() {
  myservo.attach(9); //pwm가용핀에 서보모터 연결
  myservo.write(0);
}

void loop() {
  for(int angle=0;angle<180;angle+=10)
  {
    myservo.write(angle);
    delay(200);
  }
}
