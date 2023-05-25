
void setup() {
Serial.begin(9600);

}

 

void loop() { 
int potentiometer = analogRead(A0);
//A0핀에서 입력받은 아날로그 값을 int형 변수에 저항

Serial.println(potentiometer);
//시리얼 모니터로 potentiometer라는 변수에 저장된 값 출력

delay(1000);
 
  

}
