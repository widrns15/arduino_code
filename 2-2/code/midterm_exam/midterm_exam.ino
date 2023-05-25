
// 지진감지 센서
// 기울어지면 스위치를 눌렀을 때, led와 부저에 한번재생
// + 3번 누를때마다 부저 계속 울림

#define DO 256
#define RE 288
#define MI 320
#define ze 0

void setup() {
  pinMode(13,INPUT);    //틸트 (그라운드 / 입력13/ 저항vcc)
  pinMode(12,OUTPUT);   //led
  pinMode(3,OUTPUT);    //부저
  pinMode(2,INPUT);     //스위치
  Serial.begin(9600);
}

void loop() {
  int music[3] = {DO,RE,MI};
  int Ze[1]={ze};
  
  if(digitalRead(13)==HIGH)
  { 
    Serial.println("on");
    digitalWrite(12,HIGH);
    tone(3,500);
     if(digitalRead(2)==HIGH)
    {
      digitalWrite(12,LOW);
      noTone(3);
    }
}
    
  
  if(digitalRead(13)==LOW)
  {
    Serial.println("OFF");
    digitalWrite(12,HIGH);
    for(int t=0; t<3; t++)
    {
    tone(3, music[t]*2);
    delay(1000);
    
    if(digitalRead(2)==HIGH)
    {
     while(1)
     {
    digitalWrite(12,LOW);
    noTone(3);
     }
    }
    }
 }
   }

