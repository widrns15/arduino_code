#include <Servo.h>
Servo myservo;

void setup() {
  myservo.attach(9); //pwm가용핀에 서보모터 연결

}

void loop() {
  myservo.write(180); //서보각 180도
  delay(1000);
  myservo.write(0);
  delay(1000);
}
