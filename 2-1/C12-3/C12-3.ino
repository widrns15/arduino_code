int LED1=13; // LED 출력 지정
int sw1_state;


void setup() {
pinMode(12, INPUT);
pinMode(13, OUTPUT); // LED 출력핀 지정

}

 

void loop() { // 아래는 풀 다운 세팅.

sw1_state=digitalRead(12);
if(sw1_state==1)
  digitalWrite(LED1,HIGH);
  else
  digitalWrite(LED1,LOW);
  
 }

  
