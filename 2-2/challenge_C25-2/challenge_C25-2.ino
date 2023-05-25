#include <SoftwareSerial.h>
#define Buzzer 9
int DCmotor=11;

SoftwareSerial bt(2,3); // RX/TX 핀 설정/ 시리얼 통신 객체 생성
/*아두이노 수신 핀에는 HC-06의 발신핀(TX)연결
 아두이노 발신 핀에는 HC-06의 수신핀(RX)연결*/

void setup() {

bt.begin(9600); // softwareSerial 통신 속도 및 시작
pinMode(DCmotor,OUTPUT);
pinMode(9,OUTPUT);
pinMode(5,OUTPUT);
}

void loop() {
  char value;
  
  if(bt.available())
  {
    value = (char)bt.read();

    Serial.print("value = ");
    Serial.println(value);
    delay(1);

    if(value == '1')
    {
      Serial.println("Buzzer ON");
      digitalWrite(Buzzer,HIGH);
    }

    if(value == '2')
    {
      Serial.println("Buzzer OFF");
      digitalWrite(Buzzer,LOW);
    }

    if(value == '3')
    {
   digitalWrite(DCmotor,HIGH);
  
    }

    if(value == '4')
    {
      digitalWrite(DCmotor,LOW); 
     
    }
    if(value == '5')
    {
      digitalWrite(5,HIGH);
      
    }
  if(value == '6')
    {
      digitalWrite(5,LOW);
  
  }
}
} 
