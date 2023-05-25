#include<arduino.h>

#define BUZ 7

int red = 9;
int green = 10;
int blue = 11;


void setup()
{
  Serial.begin(9600);
  pinMode(12, OUTPUT); // 트리거 출력
  pinMode(13, INPUT); // 에코 입력
  pinMode(7,OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);


}

void loop()
{

  long duration, cm; // 변수 duration, cm설정
  digitalWrite(12, LOW); //HIGH신호를 보내기전 깨끗하게
  delayMicroseconds(2);

  digitalWrite(12, HIGH); // 초음파 트리거 출력 시작
  delayMicroseconds(10);

  digitalWrite(12, LOW); //출력 종료

  duration = pulseIn(13, HIGH); //에코핀이 트리거가 HIGH인 시간 저장

  cm = (duration / 2) / 29.4; //초음파 거리를 cm로 산출

  Serial.print(cm);
  Serial.println("cm");
  delay(100);

  if (cm <= 10) // 빨간 LED만 켜짐
  {
    digitalWrite(BUZ,HIGH);
    Color(255,0,0);
  }

  else if ((cm > 10)&&(cm < 30)) // 파랑 LED만 켜짐
  {
    digitalWrite(BUZ,HIGH);
    Color(0,0,255);
    delay(500);
    digitalWrite(BUZ,LOW);
    Color(0,0,0);
    delay(500);
  }

  else if (cm >= 30) // 초록 LED만 켜짐
  {
    digitalWrite(BUZ,HIGH);
    Color(0,255,0);
    delay(1000);
    digitalWrite(BUZ,LOW);
    Color(0,0,0);
    delay(1000);
  } 
}

void Color(int r, int g, int b)
{
  analogWrite(red,r);
  analogWrite(green,g);
  analogWrite(blue,b);
}
