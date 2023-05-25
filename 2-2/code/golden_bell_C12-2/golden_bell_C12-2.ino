int sw1_state; //스위치 함수 지정
int sw2_state;
int LED1=7; // LED 출력 지정
int LED2=12;
 

void setup() {
pinMode(11, INPUT);
pinMode(12, OUTPUT);
pinMode(6, INPUT); // LED 입력핀 지정
pinMode(7, OUTPUT); // LED 출력핀 지정

Serial.begin(9600);

}

 

void loop() { // 아래는 풀 다운 세팅.

  sw2_state = digitalRead(11); 

  sw1_state = digitalRead(6);

  

  if(sw1_state==1){ //풀업으로 했을경우에 HIGH를 LOW로(1>0)바꿔줌. 풀업으로 바꿨을때 항상 전류가 흐르는 상태(1)이므로 관리하려면 0인 상태이어야함

  digitalWrite(LED1,HIGH); // 얘낸 스위치에 대한 키고 끔임이므로 독립적임. 폴다운 폴업과 관계 X
  delay(1000);
  digitalWrite(LED1,LOW);
  delay(1000);
  digitalWrite(LED2,HIGH);
  delay(1000);
  digitalWrite(LED2,LOW);
  delay(1000);

  

  Serial.print(HIGH);

  Serial.println("LED1 on HIGH");
delay(2000);
 

 }

  if(sw2_state==1){

  digitalWrite(LED1,HIGH);
  digitalWrite(LED2,HIGH);
  delay(1000);
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
  delay(1000);

  

  Serial.print(HIGH);

  Serial.println("LED2 on HIGH");
  delay(2000);

 

  }

  if((sw1_state==1)&&(sw2_state==1))

  {

  digitalWrite(LED1,HIGH);
digitalWrite(LED2,HIGH);
 

  Serial.print(HIGH);

  Serial.println("BOTH on HIGH");
delay(2000);
}

}
