// 지진감지 센서
// 기울어지면 buzzer가 켜지고 3번 켜질때마다
// led on, 스위치 누르면 all off.

#define Buz 3
#define sw1 2
int count=0;

void setup() {
  pinMode(13,INPUT);    //틸트 (그라운드 / 입력13/ 저항vcc)
  pinMode(12,OUTPUT);   //led
  pinMode(3,OUTPUT);    //부저
  pinMode(2,INPUT);     //스위치
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(13)==HIGH)
  { // 스위치 그라운드에 저항
    
    Serial.println("on");
    tone(3,500);
    delay(500);
    tone(3,250);
    delay(500);
    noTone(3); 
    
    count+=1;
    
    if((count%3)==0)
    {
    digitalWrite(12,HIGH);
    delay(1000);
    digitalWrite(12,LOW);
    delay(1000);
    }
    
    if(digitalRead(2)==HIGH)
    {
    Serial.println("OFF");
    digitalWrite(12,LOW);
    noTone(3);
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
