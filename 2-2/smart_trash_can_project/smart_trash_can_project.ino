#include <Servo.h>

#define SERVO_PIN 9     // 서보모터 9번 사용

int echo = 13;      // echo핀 6번 사용
int trig = 12;      // trig핀 7번 사용

Servo myservo;

int cnt = 0;

void setup() {
  pinMode(trig, OUTPUT);    // trig 출력 설정
  pinMode(echo, INPUT);     // echo 입력 설정
  myservo.attach(SERVO_PIN); // 서보모터 초기화
  Serial.begin(9600);
}

void loop() {
    
  long duration, cm; // 변수 duration, cm 설정
  digitalWrite(12,LOW); // HIGH 신호를 보내기 전 깨끗하게
  delayMicroseconds(2);

  digitalWrite(12,HIGH); // 초음파 트리거 출력 시작
  delayMicroseconds(5);
  digitalWrite(12,LOW); // 출력 종료

  duration = pulseIn(13,HIGH); // 에코핀이 트리거가 HIGHㅣㅇㄴ 시작

  cm = (duration/2)/29.4; // 초음파 거리를 cm로 산출

  Serial.print(cm);
  Serial.println("cm");

  if (cm <= 15)     // 초음파센서 거리가 15cm 이하이면
  {
    if(cnt>=10){
        myservo.write(150);     // 서보모터 각도를 150도
    }else cnt = cnt + 2;
  
  }else{
    if (cnt==0)
    {
        myservo.write(90);
    }else cnt --;
  }
  delay(100);
}
