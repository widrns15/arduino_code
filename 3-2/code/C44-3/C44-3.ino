#include <Stepper.h>

int IN1=22;
int IN2=24;
int IN3=26;
int IN4=28;

//step motor 객체 생성
Stepper motor(64,IN1,IN2,IN3,IN4);

void setup(){

  //step motor pin 초기화
  for(int pin=IN1; pin<IN4; pin++)
  pinMode(pin, OUTPUT);

  Serial.begin(9600);
  motor.setSpeed(100);  //step motor speed 설정

  Serial.println("Speed : 100rpm");
  Serial.print("Enter steps :  ");
}

void loop(){
  if(Serial.available())
  {
    int steps = Serial.parseInt();
    Serial.println(steps);
    motor.step(steps);
    Serial.print("Enter steps :   ");
  
   }
}
