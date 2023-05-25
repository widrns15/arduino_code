#define LedRed 2
#define LedGreen 3
#define LedYellow 4


void setup() 
{
  Serial.begin(9600); // 시리얼 통신 시작
  pinMode(13,OUTPUT); //13번핀 트리거 출력
  pinMode(12,INPUT);  //12번핀 에코 입력
  
  pinMode(2,OUTPUT); // LED 출력 
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
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

    
    if(cm<10)
    {
      digitalWrite(LedYellow,LOW);
      digitalWrite(LedGreen,LOW);
      digitalWrite(LedRed,HIGH);
      Serial.print("\n Red on");
    }

    else if(cm<30)
    {
      digitalWrite(LedYellow,LOW);
      digitalWrite(LedGreen,HIGH);
      digitalWrite(LedRed,LOW);
      Serial.print("\n Green on");
    }

    else if(cm>30)
    {
      digitalWrite(LedYellow,HIGH);
      digitalWrite(LedGreen,LOW);
      digitalWrite(LedRed,LOW);
      Serial.print("\n Yellow on");
    }
    
  }
