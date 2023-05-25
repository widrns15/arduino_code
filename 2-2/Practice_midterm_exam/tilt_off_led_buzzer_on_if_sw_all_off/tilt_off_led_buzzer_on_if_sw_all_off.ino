
// 지진감지 센서
// 평소에 부저랑 led 반복재생, 기울어지면 멈춤
// 스위치는 모두 스탑

void setup() {
  pinMode(13,INPUT);    //틸트 (그라운드 / 입력13/ 저항vcc)
  pinMode(12,OUTPUT);   //led
  pinMode(3,OUTPUT);    //부저
  pinMode(2,INPUT);     //스위치
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(13)==0)
  { // 스위치 그라운드에 저항

    Serial.println("on");
    digitalWrite(12,HIGH);
    tone(3,500);
    delay(500);
    tone(3,250);
    delay(500);
    noTone(3);
    digitalWrite(12,LOW);

}
    
  
  if((digitalRead(13)==1)||(digitalRead(2)==1))
  {
    Serial.println("OFF");
    digitalWrite(12,LOW);
    noTone(3);
    delay(1000);
  }
}
