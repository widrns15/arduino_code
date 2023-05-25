int sw1_state; //스위치 함수 지정

int LED1=13; // LED 출력 지정



void setup() {

pinMode(12, INPUT); // LED 입력핀 지정

pinMode(13, OUTPUT); // LED 출력핀 지정

}

 

void loop() { // 아래는 풀 다운 세팅.

  sw1_state = digitalRead(12);

  

  if(sw1_state==0){ //풀업으로 했을경우에 HIGH를 LOW로(1>0)바꿔줌. 풀업으로 바꿨을때 항상 전류가 흐르는 상태(1)이므로 관리하려면 0인 상태이어야함

  digitalWrite(LED1,HIGH); // 얘낸 스위치에 대한 키고 끔임이므로 독립적임. 폴다운 폴업과 관계 X
  }
  else
{
  digitalWrite(LED1,LOW);  
}
}
