#include <LiquidCrystal.h>

#define BUZ 33;
#define DO 256
#define RE 288
#define MI 320
#define FA 341
#define SO 384
#define LA 427
#define TI 480
#define DELAY 300

int music [] = { MI,LA,LA,MI,TI,DO,DO,TI,LA,FA,LA,TI,LA,MI,LA};

LiquidCrystal lcd(22,23,24,25,26,27);

void setup() 
{
  pinMode(28,OUTPUT);
  pinMode(29,OUTPUT);
  lcd.begin(16,2);
  lcd.print("     SUBWAY");
  delay(1000);
  Serial.begin(9600); // 시리얼 통신 시작
  pinMode(13,OUTPUT); //13번핀 트리거 출력
  pinMode(12,INPUT);  //12번핀 에코 입력
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

    if(cm < 5){
    lcd.clear();
    lcd.print("    Incheon");
    lcd.setCursor(0,1);
    lcd.print(" Wolgye arrive");
    digitalWrite(29,LOW);
    digitalWrite(28,HIGH);
    delay(500);
  }
   if((cm > 5)&&(cm < 10)){
    lcd.clear();
    lcd.print("    Incheon");
    delay(500);
    lcd.setCursor(0,1);
    lcd.print(" Wolgye approch");
    digitalWrite(28,LOW);
    digitalWrite(29,LOW);
    music_play();
  }
  if((cm > 10)&&(cm < 20)){
    lcd.clear();
    lcd.print("    Incheon");
    lcd.setCursor(0,1);
    lcd.print("Nokcheon station");
    digitalWrite(28,LOW);
    digitalWrite(29,HIGH);
    delay(500);
  }
  if(cm > 20){
    lcd.clear();
    lcd.print("    Incheon");
    digitalWrite(28,LOW);
    digitalWrite(29,LOW);
    delay(500);
  }
}

void music_play()
{
  for(int i=0; i<sizeof(music)/sizeof(int); i++)
  {
    delay(DELAY);
  }
}
