#include <SoftwareSerial.h>
#include<Servo.h>
int DCmotor=10;
int buzzer = 8;
Servo myservo;
#define cds A2
SoftwareSerial bt(2,3); // RX/TX 핀 설정/ 시리얼 통신 객체 생성

void setup() {
  pinMode(DCmotor,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(cds, INPUT);
  Serial.begin(9600);
  myservo.attach(9);
  myservo.write(0);
  bt.begin(9600); // softwareSerial 통신 속도 및 시작
}

void loop() {
  char value;
 if(bt.available())
 {
  value = (char)bt.read();

    Serial.print("value = ");
    Serial.println(value);
    delay(1);
    
  if(value == '1'){
  int cdsvalue = analogRead(A2);
  analogWrite(DCmotor,cdsvalue/4);
  Serial.println("빛의 양 : ");
  Serial.println(cdsvalue);
  Serial.println("\n");
  delay(200);
  
  int potentiometer=(analogRead(A0)/4);
  myservo.write(potentiometer);
  Serial.println("가변저항 : ");
  Serial.print(potentiometer);
  Serial.println("\n\n");
  delay(200);
  if(potentiometer>180)
  {
  digitalWrite(buzzer,HIGH);
  delay(1000);
  digitalWrite(buzzer,LOW); 
  delay(1000);
  }
  delay(2000);
}

if(value == '2')
    {
      while(1){
      analogWrite(DCmotor,0);
      myservo.write(0);
      digitalWrite(buzzer,LOW);
    }
    }
}
} 
