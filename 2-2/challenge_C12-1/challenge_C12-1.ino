int LED1=7; // LED 출력 지정



void setup() {

pinMode(7, OUTPUT); // LED 출력핀 지정

}

 

void loop() { // 아래는 풀 다운 세팅.

  digitalWrite(LED1,HIGH); // 얘낸 스위치에 대한 키고 끔임이므로 독립적임. 폴다운 폴업과 관계 X
  delay(2000);
  digitalWrite(LED1,LOW);
  delay(1000);
 
 }
