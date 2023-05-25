#include<Servo.h>
#define SW1 10
Servo myservo;

void setup() {
  pinMode(10,INPUT);
  myservo.attach(9); //pwm가용핀에 서보모터 연결

}

void loop(){
  if(digitalRead(10) == HIGH){
  for(int angle=0;angle<180;angle++)
  {
    if(digitalRead(10) == LOW){
    }
        myservo.write(angle);
    delay(50);
  }
}  
 }
