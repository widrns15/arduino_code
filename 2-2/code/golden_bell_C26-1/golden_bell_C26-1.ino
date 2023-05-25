#include<Servo.h>
Servo myservo;

void setup() {
  Serial.begin(9600);
  myservo.attach(9); //pwm가용핀에 서보모터 연결
  myservo.write(0);
  delay(100);
  Serial.print("value = ");
}

void loop() {
  int value;
  if(Serial.available()){
    value = Serial.parseInt();  //시리얼 입력값 정수형으로 저장
    Serial.println(value);
    
    if(value == 1)    // 정수형이므로 '1'이 아님
    {
      while(1){
    Number(0);
    Number(0);
      }
    }

    if(value == 10)    // 정수형이므로 '1'이 아님
    {
      while(1){
    Number(1);
    Number(1);
      }
    }
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
