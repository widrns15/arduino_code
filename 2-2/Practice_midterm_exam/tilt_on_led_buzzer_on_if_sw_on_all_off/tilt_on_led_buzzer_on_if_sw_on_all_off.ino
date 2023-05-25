// 지진감지 센서
// 기울어지면 led와 부저 on, 스위치 누르면 all off.

#define Buz 3
#define sw1 2

void setup() {
  pinMode(13,INPUT);    //틸트 (그라운드 / 입력13/ 저항vcc)
  pinMode(12,OUTPUT);   //led
  pinMode(3,OUTPUT);    //부저
  pinMode(2,INPUT);     //스위치
  Serial.begin(9600);
}

void loop() {
  while(digitalRead(13)==HIGH)
  { // 스위치 그라운드에 저항
    while(digitalRead(2)==HIGH)
    {
    Serial.println("OFF");
    digitalWrite(12,LOW);
    noTone(3);
    }
    Serial.println("on");
    digitalWrite(12,HIGH);
    tone(3,500);
    delay(1000);
    tone(3,250);
    delay(1000);
    noTone(3);   
  }

  if((digitalRead(13)==LOW)&&(digitalRead(2)==LOW))
  {
    Serial.println("OFF");
    digitalWrite(12,LOW);
    noTone(3);
    delay(1000);
  }
}
