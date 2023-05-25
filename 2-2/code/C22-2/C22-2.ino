#define relayPin 7
 
void setup() {
  pinMode(relayPin,OUTPUT);
  Serial.begin(9600);
  digitalWrite(relayPin,HIGH); // relay 초기상태 HIGH, C와 NO가 연결됨, motor 회전
  
}

void loop()
{
  if(Serial.available())
  {
    switch(Serial.read()){
      case '1': // relay Input이 HIGH이면, C와 NO가 연결됨, MOTOR 회전
    digitalWrite(relayPin,HIGH);
    Serial.println("Relay ON");
    break;
    case '2': //relay Input이 LOW이면, C와 NC가 연결됨, motor 정지
    digitalWrite(relayPin,LOW);
    Serial.println("Relay OFF");
    break;
  }
 }
}
