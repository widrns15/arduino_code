#include<arduino.h>

#define ledA 3
#define ledB 7
#define ledC 11
#define ledD 9
#define ledE 8
#define ledF 4
#define ledG 12
#define DOT 10
#define seg1 2
#define seg2 5
#define seg3 6
#define seg4 13

#define LED1 A2
#define LED2 A3
#define LED3 A4

int call = 0;
int count = 0;
int readVal;


int a[5] = {}; // 각 segment 숫자를 저장할 배열
int b;
int n1, n10, n100, n1000;

#define sw1 1 // sw1을 1로 지정

void setup()
{
  pinMode(A0, OUTPUT); // 트리거 출력
  pinMode(A1, INPUT); // 에코 입력
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledC, OUTPUT);
  pinMode(ledD, OUTPUT);
  pinMode(ledE, OUTPUT);
  pinMode(ledF, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(DOT, OUTPUT);
  pinMode(seg1, OUTPUT);
  pinMode(seg2, OUTPUT);
  pinMode(seg3, OUTPUT);
  pinMode(seg4, OUTPUT);
  pinMode(sw1, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  Serial.end();


}

void loop()
{
  int sw1_state = digitalRead(sw1);

  long duration, cm; // 변수 duration, cm설정
  digitalWrite(A0, LOW); //HIGH신호를 보내기전 깨끗하게
  delayMicroseconds(2);

  digitalWrite(A0, HIGH); // 초음파 트리거 출력 시작
  delayMicroseconds(10);

  digitalWrite(A0, LOW); //출력 종료

  duration = pulseIn(A1, HIGH); //에코핀이 트리거가 HIGH인 시간 저장

  cm = (duration / 2) / 29.4; //초음파 거리를 cm로 산출



  if (cm < 30) // 빨간 LED만 켜짐
  {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, HIGH);
  }

  else if (cm < 50) // 노란 LED만 켜짐
  {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW);
  }

  else if (cm < 100) // 초록 LED만 켜짐
  {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
  }

  else if (cm > 100) // 모두 꺼짐
  {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
  }

  if (sw1_state == HIGH)
  {
    if (call == 0) {
      delay(10);
      call = 1;
    }
  }


  if (sw1_state == LOW) {
    if (call == 1) {
      count += 1;
      delay(10);
      call = 0;
    }
  }


  if (count == 1) { //스위치를 1번 누르면
    if (cm > 0)
    {
      n1000 = (cm / 1000);
      a[0] = n1000;
      digitalWrite(seg1, LOW);
      Number(a[0]);
      delay(5);
      digitalWrite(seg1, HIGH);

      n100 = (cm % 1000) / 100;
      a[1] = n100;
      digitalWrite(seg2, LOW);
      Number(a[1]);
      delay(5);
      digitalWrite(seg2, HIGH);

      n10 = (cm % 100) / 10;
      a[2] = n10;
      digitalWrite(seg3, LOW);
      Number(a[2]);
      delay(5);
      digitalWrite(seg3, HIGH);

      n1 = (cm % 10);
      a[3] = n1;
      digitalWrite(seg4, LOW);
      Number(a[3]);
      delay(5);
      digitalWrite(seg4, HIGH);
    }
  }


  if (count == 2) // 스위치가 2번눌렸을때
  {
    count = 0;
  }
}


void Number(int n)
{
  switch (n) {

    case 0: // 0출력
      digitalWrite(ledA, HIGH);
      digitalWrite(ledB, HIGH);
      digitalWrite(ledC, HIGH);
      digitalWrite(ledD, HIGH);
      digitalWrite(ledE, HIGH);
      digitalWrite(ledF, HIGH);
      digitalWrite(ledG, LOW);
      digitalWrite(DOT, LOW);
      break;

    case 1: // 1 출력
      digitalWrite(ledA, LOW);
      digitalWrite(ledB, HIGH);
      digitalWrite(ledC, HIGH);
      digitalWrite(ledD, LOW);
      digitalWrite(ledE, LOW);
      digitalWrite(ledF, LOW);
      digitalWrite(ledG, LOW);
      digitalWrite(DOT, LOW);
      break;

    case 2: // 2 출력
      digitalWrite(ledA, HIGH);
      digitalWrite(ledB, HIGH);
      digitalWrite(ledC, LOW);
      digitalWrite(ledD, HIGH);
      digitalWrite(ledE, HIGH);
      digitalWrite(ledF, LOW);
      digitalWrite(ledG, HIGH);
      digitalWrite(DOT, LOW);
      break;

    case 3: // 3 출력
      digitalWrite(ledA, HIGH);
      digitalWrite(ledB, HIGH);
      digitalWrite(ledC, HIGH);
      digitalWrite(ledD, HIGH);
      digitalWrite(ledE, LOW);
      digitalWrite(ledF, LOW);
      digitalWrite(ledG, HIGH);
      digitalWrite(DOT, LOW);
      break;

    case 4: // 4 출력
      digitalWrite(ledA, LOW);
      digitalWrite(ledB, HIGH);
      digitalWrite(ledC, HIGH);
      digitalWrite(ledD, LOW);
      digitalWrite(ledE, LOW);
      digitalWrite(ledF, HIGH);
      digitalWrite(ledG, HIGH);
      digitalWrite(DOT, LOW);
      break;

    case 5: // 5 출력
      digitalWrite(ledA, HIGH);
      digitalWrite(ledB, LOW);
      digitalWrite(ledC, HIGH);
      digitalWrite(ledD, HIGH);
      digitalWrite(ledE, LOW);
      digitalWrite(ledF, HIGH);
      digitalWrite(ledG, HIGH);
      digitalWrite(DOT, LOW);
      break;

    case 6: // 6 출력
      digitalWrite(ledA, HIGH);
      digitalWrite(ledB, LOW);
      digitalWrite(ledC, HIGH);
      digitalWrite(ledD, HIGH);
      digitalWrite(ledE, HIGH);
      digitalWrite(ledF, HIGH);
      digitalWrite(ledG, HIGH);
      digitalWrite(DOT, LOW);
      break;

    case 7: // 7 출력
      digitalWrite(ledA, HIGH);
      digitalWrite(ledB, HIGH);
      digitalWrite(ledC, HIGH);
      digitalWrite(ledD, LOW);
      digitalWrite(ledE, LOW);
      digitalWrite(ledF, HIGH);
      digitalWrite(ledG, LOW);
      digitalWrite(DOT, LOW);
      break;

    case 8: // 8 출력
      digitalWrite(ledA, HIGH);
      digitalWrite(ledB, HIGH);
      digitalWrite(ledC, HIGH);
      digitalWrite(ledD, HIGH);
      digitalWrite(ledE, HIGH);
      digitalWrite(ledF, HIGH);
      digitalWrite(ledG, HIGH);
      digitalWrite(DOT, LOW);
      break;

    case 9: // 9 출력
      digitalWrite(ledA, HIGH);
      digitalWrite(ledB, HIGH);
      digitalWrite(ledC, HIGH);
      digitalWrite(ledD, HIGH);
      digitalWrite(ledE, LOW);
      digitalWrite(ledF, HIGH);
      digitalWrite(ledG, HIGH);
      digitalWrite(DOT, LOW);
      break;

    default:
      digitalWrite(ledA, LOW);
      digitalWrite(ledB, LOW);
      digitalWrite(ledC, LOW);
      digitalWrite(ledD, LOW);
      digitalWrite(ledE, LOW);
      digitalWrite(ledF, LOW);
      digitalWrite(ledG, LOW);
      digitalWrite(DOT, LOW);
      break;
  }
}
