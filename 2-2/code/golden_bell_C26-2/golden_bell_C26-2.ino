#include<Servo.h>
int DCmotor=10;
int buzzer = 8;
Servo myservo;
#define cds A2

void setup() {
  pinMode(DCmotor,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(cds, INPUT);
  Serial.begin(9600);
  myservo.attach(9);
  myservo.write(0);
}

void loop() {
  
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
