#include <SoftwareSerial.h>
#include <Stepper.h>
#include <LiquidCrystal_I2C.h>

#include "DHT.h"
#include <Wire.h>

#define                   DHTPIN                2 
#define                   DHTTYPE               DHT11

#define                   RGB_GREEN             3
#define                   RGB_BLUE              4
#define                   RGB_RED               5

#define                   DUST_LED              A0
#define                   DUST_IN               A1

#define                   GREEN_V               200
#define                   BLUE_V                300

#define RXD_PIN 12 //아두이노 수신핀
#define TXD_PIN 13 //아두이노 송신핀

int dset = 0; //창문상태 확인용
int dauto = 0; //자동상태 확인용
int count = 0;


const int stepsPerRevolution = 2048; //스텝모터 구동용
Stepper myStepper(stepsPerRevolution,11,9,10,8);


DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);
float           Voltage = 0, Cal_vol = 0, Dust_v = 0;
float           dht_temp = 0, dht_humi = 0;
unsigned long   prev_time;

SoftwareSerial bt(RXD_PIN,TXD_PIN);//RX/TX핀 설정/시리얼 통신 객체 설정(변수 bt사용)
//아두이노 [수신핀 > HC-06 발신핀(TX)] [발신핀 > HC-06 수신핀(RX)]

void setup() {
  Serial.begin(9600);
  myStepper.setSpeed(15); 
  bt.begin(9600);//softwareSerial 통신 속도 및 시작 pc>아두이노>bluetooth 맞춰야함
  dht.begin(); lcd.begin();
  pinMode(DUST_LED, OUTPUT);      pinMode(DUST_IN, INPUT);
  pinMode(RGB_GREEN, OUTPUT);     pinMode(RGB_BLUE, OUTPUT);      pinMode(RGB_RED, OUTPUT);
}

void loop() {   
  if( (millis() - prev_time) >= 1000 ){
    read_dht();
    read_dust();
    print_lcd();
    read_bt();
    d_auto();
    prev_time = millis();
    bt.print(Dust_v);  
    bt.print("/");
    bt.print(dht_temp);
    bt.print("/");
    bt.print(dht_humi);
  } 
}

void print_lcd(){
  lcd.clear();
  lcd.setCursor(2,0);  
  lcd.print("Dust  :  ");
  lcd.println(Dust_v);
  lcd.setCursor(2,1);  
  lcd.print("Temp  :  ");
 lcd.println(dht_temp);
}
void read_dht(){
  dht_temp = dht.readTemperature();  
  dht_humi = dht.readHumidity();
  Serial.print("DHT :: Temp:");  Serial.print(dht_temp);
  Serial.print("    Humi:");     Serial.println(dht_humi);  
}

void read_dust(){
  digitalWrite(DUST_LED, LOW);
  delayMicroseconds(280);
  Voltage = analogRead(DUST_IN);
  delayMicroseconds(40);
  digitalWrite(DUST_LED, HIGH);
  delayMicroseconds(9680);
  Cal_vol = Voltage * (5.0 / 1024.0);
  Dust_v = (0.17*(Cal_vol-0.3))*1000;
  
  delay(500);
  
  Serial.print( " DUST_VALUE : " );
  Serial.println(Dust_v);
}

void read_bt(){
  if(bt.available())  
  {
    char value = bt.read();

               // 수동 전환
    
    if(value == 'c' && dauto == 1)
    {
      dauto = 0;

      if(dset == 0)
      {
        myStepper.step(-stepsPerRevolution*1.3);
      }
      
    }

//               자동상태 확인           

    else if(value == 'c' && dauto == 0)
    {
     dauto = 1; //자동상태 
     if(count == 1)
     {
      myStepper.step(-stepsPerRevolution*1.3);
     }
      dset = 1; // 닫힘
      count = 0;
    }


    //               수동 여닫이
     if(value == 'a' && count != 1 && dauto == 0) // 창문 열기
    {
      myStepper.step(stepsPerRevolution*1.3);     
      count = 1;
    }

    else if(value == 'b' && count != 0 && dauto == 0) // 창문 닫기
    {
      myStepper.step(-stepsPerRevolution*1.3);
      count = 0;
    }
  }
}

void d_auto(){
  if(dauto == 1)
  {
    int a = Dust_v;

    if(a <= 90) //미세먼지가 50이하면 창문을 염
    {
      if(dset == 1){
        myStepper.step(stepsPerRevolution*(1.3));        
      }
      
      dset = 0;
    }

    else if(a >= 150) //미세먼지가 100이상이면 창문을 닫음
    {
      if(dset == 0){
        myStepper.step(-stepsPerRevolution*1.3);        // 닫힘
      }
      
      dset = 1;
    } 
  }
}
