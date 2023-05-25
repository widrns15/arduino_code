#include <Servo.h>
Servo myservo;

int call=0;


void setup() {

  pinMode(13,INPUT);    //  tilt
  pinMode(11,OUTPUT);   // led
  pinMode(4,INPUT);     // switch

  myservo.attach(6); //pwm가용핀에 서보모터 연결
  myservo.write(0);

  Serial.begin(9600);
  Serial.println("servo motor");
  delay(100);
  Serial.print("servo angle : ");
}

 

void loop() {

if(digitalRead(13)==LOW)    // 안기울였을때 tilt off
{
  Serial.println("off");
  myservo.write(0);
  for(int angle=0;angle<180;angle+=10)
     {
      myservo.write(angle);
      delay(200);
     }

    if(digitalRead(4)==HIGH){   // 스위치
      call++;

     while(call==1){
      digitalWrite(11,HIGH);
      delay(1000);
      digitalWrite(11,LOW);
      delay(1000);
      myservo.write(0);

      if(digitalRead(13)==HIGH) break;
     }
 }
}

 

 
if(digitalRead(13)==HIGH)   // 기울였을 때

{
  Serial.println("on");
  int value;
  if(Serial.available()){
    value = Serial.parseInt();
    Serial.println(value);
    myservo.write(value);
    Serial.println("complete");
    Serial.print("next servo angle : ");
  }
}
}
