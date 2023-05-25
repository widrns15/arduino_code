#include <DHT.h>

#define DHT_PIN A2
DHT dht (DHT_PIN, DHT11);

int ledA=3;
int ledB=4;
int ledC=5;
int ledD=6;
int ledE=7;
int ledF=8;
int ledG=9;
int DOT=10;

void setup() {
  Serial.begin(9600);
  Serial.println("DHT Test ~!!");
  dht.begin(); // 온습도 센서 동작 시작

  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledC, OUTPUT);
  pinMode(ledD, OUTPUT);
  pinMode(ledE, OUTPUT);
  pinMode(ledF, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(DOT, OUTPUT);
}

void loop() {
  
boolean chk = dht.read(); // 온습도 센서의 동작 체크


if(chk)
{
  Serial.print("Humidity (%): ");
  Serial.println((int)dht.readHumidity());
  int si=(int)dht.readHumidity();

  if(si<=30)
  {
    Number(5);
  }
  else if(si<=50)
  {
    Number(6);
  }
  else if(si<=80)
  {
    Number(7);
  }
  else
  {
    Number(8);
  }
delay(5000);
 
  
  Serial.print("Temperature (도): ");
  Serial.println((int)dht.readTemperature(false));
  int hj=(int)dht.readTemperature(false);
  
  if(hj<=10)
  {
    Number(1);
  }
  else if(hj<=20)
  {
    Number(2);
  }
  else if(hj<=30)
  {
    Number(3);
  }
  else
  {
    Number(4);
  }
  delay(5000);
  
 }
  else{
  Serial.print("Failed to read info.");
}
}


void Number(int n)
{
  switch(n){
    
    case 0: // 0출력
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledC, HIGH);
    digitalWrite(ledD, HIGH);
    digitalWrite(ledE, HIGH);
    digitalWrite(ledF, HIGH);
    digitalWrite(ledG, LOW);
    digitalWrite(DOT, LOW);
    break;
    
    case 1: // 1 출력
    digitalWrite(ledA, LOW);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledC, HIGH);
    digitalWrite(ledD, LOW);
    digitalWrite(ledE, LOW);
    digitalWrite(ledF, LOW);
    digitalWrite(ledG, LOW);
    digitalWrite(DOT, LOW);
    break;

    case 2: // 2 출력
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledC, LOW);
    digitalWrite(ledD, HIGH);
    digitalWrite(ledE, HIGH);
    digitalWrite(ledF, LOW);
    digitalWrite(ledG, HIGH);
    digitalWrite(DOT, LOW);
    break;

    case 3: // 3 출력
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledC, HIGH);
    digitalWrite(ledD, HIGH);
    digitalWrite(ledE, LOW);
    digitalWrite(ledF, LOW);
    digitalWrite(ledG, HIGH);
    digitalWrite(DOT, LOW);
    break;

    case 4: // 4 출력
    digitalWrite(ledA, LOW);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledC, HIGH);
    digitalWrite(ledD, LOW);
    digitalWrite(ledE, LOW);
    digitalWrite(ledF, HIGH);
    digitalWrite(ledG, HIGH);
    digitalWrite(DOT, LOW);
    break;

    case 5: // 5 출력
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, LOW);
    digitalWrite(ledC, HIGH);
    digitalWrite(ledD, HIGH);
    digitalWrite(ledE, LOW);
    digitalWrite(ledF, HIGH);
    digitalWrite(ledG, HIGH);
    digitalWrite(DOT, LOW);
    break;

    case 6: // 6 출력
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, LOW);
    digitalWrite(ledC, HIGH);
    digitalWrite(ledD, HIGH);
    digitalWrite(ledE, HIGH);
    digitalWrite(ledF, HIGH);
    digitalWrite(ledG, HIGH);
    digitalWrite(DOT, LOW);
    break;

    case 7: // 7 출력
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledC, HIGH);
    digitalWrite(ledD, LOW);
    digitalWrite(ledE, LOW);
    digitalWrite(ledF, HIGH);
    digitalWrite(ledG, LOW);
    digitalWrite(DOT, LOW);
    break;

    case 8: // 8 출력
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledC, HIGH);
    digitalWrite(ledD, HIGH);
    digitalWrite(ledE, HIGH);
    digitalWrite(ledF, HIGH);
    digitalWrite(ledG, HIGH);
    digitalWrite(DOT, LOW);
    break;

    case 9: // 9 출력
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledC, HIGH);
    digitalWrite(ledD, HIGH);
    digitalWrite(ledE, LOW);
    digitalWrite(ledF, HIGH);
    digitalWrite(ledG, HIGH);
    digitalWrite(DOT, LOW);
    break;

    default:
    digitalWrite(ledA, LOW);
    digitalWrite(ledB, LOW);
    digitalWrite(ledC, LOW);
    digitalWrite(ledD, LOW);
    digitalWrite(ledE, LOW);
    digitalWrite(ledF, LOW);
    digitalWrite(ledG, LOW);
    digitalWrite(DOT, LOW);
    break;
  }
}
