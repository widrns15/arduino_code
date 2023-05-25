#include<arduino.h>

int LED_PIN1 = 3;
int LED_PIN2 = 5;
int readVal;

void setup() {
  Serial.begin(9600); // 시리얼 통신 시작
  pinMode(13,OUTPUT); // 트리거 출력
  pinMode(12,INPUT);  // 에코 입력
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);

}

void loop() {

long duration, cm; // 변수 duration, cm설정
  digitalWrite(13,LOW);//HIGH신호를 보내기전 깨끗하게
  delayMicroseconds(2);

  digitalWrite(13,HIGH);// 초음파 트리거 출력 시작
  delayMicroseconds(10);

  digitalWrite(13,LOW);//출력 종료
  
  duration = pulseIn(12,HIGH); //에코핀이 트리거가 HIGH인 시간 저장

  cm=(duration/2)/29.4; //초음파 거리를 cm로 산출

  Serial.print(cm);
  Serial.println("cm");

readVal = map(cm, 0, 30, 0, 255);

if(cm<30)
{
analogWrite(LED_PIN1,readVal); //0~255~0
analogWrite(LED_PIN2,255-readVal); // 255~0~255
delay(100);
}

else
{
  analogWrite(LED_PIN1,0);
  analogWrite(LED_PIN2,0);
}
/*int out= readVal ;

if(readVal>127.5)
{
  out=255-readVal;
}
analogWrite(LED_PIN1,out); //0~255~0 256
analogWrite(LED_PIN2,255-out); // 255~0~255
Serial.println(readVal);
delay(1000);
}
*/
}
