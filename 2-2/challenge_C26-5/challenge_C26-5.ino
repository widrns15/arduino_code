#include<Servo.h>
Servo myservo;

void setup() {
  myservo.attach(9); //pwm가용핀에 서보모터 연결
  myservo.write(0);
}

void loop() {
  while(1)
  {
    Number(0);
    Number(0);
    Number(1);
    Number(1);
  }
}

void Number(int n)
{
  switch(n){
    
    case 0: // 90도
    for(int angle=0;angle<90;angle+=10)
  {
    myservo.write(angle);
    delay(200);
  }
    break;

    case 1: // 180도
    for(int angle=0;angle<180;angle+=10)
  {
    myservo.write(angle);
    delay(200);
  }
    break;
  }
}
