#include<Servo.h>
Servo myservo;

void setup() {
  Serial.begin(9600);
  myservo.attach(9); //pwm가용핀에 서보모터 연결
  myservo.write(0);
  Serial.println("servo motor");
  delay(100);
  Serial.print("servo angle : ");
}

void loop() {
  int value;
  if(Serial.available()){
    value = Serial.parseInt();  //시리얼 입력값 정수형으로 저장
    Serial.println(value);
    myservo.write(value);
    Serial.println("complete");
    Serial.print("next servo angle : ");
  }
}
