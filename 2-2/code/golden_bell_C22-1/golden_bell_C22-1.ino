#define relayPin 7

void setup() {

  Serial.begin(9600);
  pinMode(13,OUTPUT); //13번핀 트리거 출력
  pinMode(12,INPUT);  //12번핀 에코 입력
  pinMode(relayPin,OUTPUT);
  digitalWrite(relayPin,HIGH); // relay 초기상태 HIGH, C와 NO가 연결됨, motor 회전

}

void loop()
{

long duration, cm; // 변수 duration, cm설정
  digitalWrite(13,LOW);//HIGH신호를 보내기전 깨끗하게
  delayMicroseconds(2);

  digitalWrite(13,HIGH);// 초음파 트리거 출력 시작
  delayMicroseconds(10);

  digitalWrite(13,LOW);//출력 종료
  
  duration = pulseIn(12,HIGH); //에코핀이 트리거가 HIGH인 시간 저장

  cm=(duration/2)/29.4; //초음파 거리를 cm로 산출

  Serial.print(cm);
  Serial.println("cm");
  delay(1000);

    
    if(cm<20)
    {
    digitalWrite(relayPin,HIGH);
    Serial.println("Relay ON");
    }

    else if(cm>20)
    {
      digitalWrite(relayPin,LOW);
      Serial.println("Relay OFF");
    }

 
}
