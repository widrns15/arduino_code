int buzzer = 8;

void setup() {
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
  //digitalWrite(buzzer,HIGH)로 초기설정해주면 처음부터 부저 울리면서 시작.
}

void loop() {
  switch(Serial.read()){
    
    case '1': //  C와 NO가 연결됨, MOTOR 회전
    digitalWrite(buzzer,HIGH);
    Serial.println("Buzzer ON");
    break;
    case '2': // C와 NC가 연결됨, motor 정지
    digitalWrite(buzzer,LOW);
    Serial.println("Relay OFF");
    break;
  }
}
