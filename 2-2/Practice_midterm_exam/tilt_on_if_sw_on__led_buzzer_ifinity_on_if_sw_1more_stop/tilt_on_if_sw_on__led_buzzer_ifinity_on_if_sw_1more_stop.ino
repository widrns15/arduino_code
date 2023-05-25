
// 지진감지 센서
// 기울어지면 스위치를 눌렀을 때, led와 부저에 반복재생
// 한 번 더 스위치 누르면 정지, 다시 또 누르면 반복재생
// + 3번 누를때마다 부저 계속 울림

int call=0;

void setup() {
  pinMode(13,INPUT);    //틸트 (그라운드 / 입력13/ 저항vcc)
  pinMode(12,OUTPUT);   //led
  pinMode(3,OUTPUT);    //부저
  pinMode(2,INPUT);     //스위치
  Serial.begin(9600);
}

void loop() {
  while((digitalRead(13)==HIGH)&&(digitalRead(2)==HIGH))
  { // 스위치 그라운드에 저항
 while(1){
    Serial.println("on");
    digitalWrite(12,HIGH);
    tone(3,500);
    delay(500);
    tone(3,250);
    delay(500);
    noTone(3);
    digitalWrite(12,LOW);

    if((digitalRead(13)==LOW)||(digitalRead(2)==HIGH))
    {
    Serial.println("OFF");
    digitalWrite(12,LOW);
    noTone(3);
    delay(500);
    break;
    }
 
/*  if(digitalRead(2)==LOW)
    {
    Serial.println("OFF");
    digitalWrite(12,LOW);
    noTone(3);
    delay(500);
    //call+=1;
    }

    while((call&3)==0)
    {
    Serial.println("on");
    digitalWrite(12,HIGH);
    tone(3,500);
    delay(500);
    tone(3,250);
    delay(500);
    noTone(3);
    if(digitalRead(2)==HIGH)
    {
      break;
    }
   }*/
}
  }    
  
  if((digitalRead(13)==LOW)&&(digitalRead(2)==LOW))
  {
    Serial.println("OFF");
    digitalWrite(12,LOW);
    noTone(3);
    delay(1000);
  }
}
