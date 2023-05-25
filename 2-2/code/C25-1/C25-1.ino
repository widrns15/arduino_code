#include <SoftwareSerial.h>

#define RXD_PIN 2 // 아두이노 수신 핀
#define TXD_PIN 3 // 아두이노 발신 핀

//SoftwareSerial bt(RXD_PIN,TXD_PIN); // RX/TX 핀 설정/ 시리얼 통신 객체 생성
SoftwareSerial bt(2,3);
/*아두이노 수신 핀에는 HC-06의 발신핀(TX)연결
 아두이노 발신 핀에는 HC-06의 수신핀(RX)연결*/

char data; // data 변수 설정
void setup() {
  // put your setup code here, to run once;
Serial.begin(9600); // 통신 속도 및 시작
bt.begin(9600); // softwareSerial 통신 속도 및 시작
Serial.println("Ready...");
}

void loop() {
  Serial.flush(); // 수신버퍼 데이터 지움
  Serial.print("CMD: ");
  while(!Serial.available()); // 수신버퍼에 저장된 것이 없다면 대기
  while(Serial.available()) // 수신 버퍼에 저장된 것이 있다면
  {
    data=Serial.read(); // data변수에 저장
    if(data==-1) break;
    bt.print(data);
    Serial.print(data); // data 출력
    delay(1);
  }
    Serial.println(); // 한 줄 띄우기
    delay(1000); // 1초대기
    Serial.print("Return: ");
    while(bt.available()) // software serial 통신으로 값이 들어올 경우
    {
      data = bt.read(); // data에 저장
      if(data==-1) break;
      Serial.print(data); // 시리얼 모니터에 출력
      delay(1);
    }
    Serial.print("\n\n"); // 두 줄 띄우기
} 
