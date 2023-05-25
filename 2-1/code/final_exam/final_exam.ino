#include<arduino.h>

#define LED1 12
#define LED2 13


int push=2;


#define sw1 4 // sw1을 1로 지정

void setup()
{
  pinMode(5, OUTPUT); // 트리거 출력
  pinMode(6, INPUT); // 에코 입력
  pinMode(sw1, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  Serial.begin(9600);

}

void loop()
{
  int sw1_state = digitalRead(sw1);

  long duration, cm; // 변수 duration, cm설정
  digitalWrite(5, LOW); //HIGH신호를 보내기전 깨끗하게
  delayMicroseconds(2);

  digitalWrite(5, HIGH); // 초음파 트리거 출력 시작
  delayMicroseconds(10);

  digitalWrite(5, LOW); //출력 종료

  duration = pulseIn(6, HIGH); //에코핀이 트리거가 HIGH인 시간 저장

  cm = (duration / 2) / 29.4; //초음파 거리를 cm로 산출

Serial.print(cm);
Serial.println("cm");
delay(1000);

if(push==2){
  if (cm < 20)
  {
    digitalWrite(LED1, HIGH);
    delay(1000);
    digitalWrite(LED1, LOW);
    delay(1000);
    
  }

  else if (cm > 20) // 노란 LED만 켜짐
  {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    delay(2000);
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    delay(2000);
  }
}


  if((sw1_state==1)||(push==1))
   { 
      push=1;
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(5, LOW); //출력 종료
      pulseIn(6, LOW);
   }


 
}
