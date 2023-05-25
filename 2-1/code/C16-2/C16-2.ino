int POTEN_PIN = A0;
int LED_PIN = 13;

void setup() {
  pinMode(LED_PIN, OUTPUT);
Serial.begin(9600);

}

 

void loop() {

int readVal= analogRead(POTEN_PIN);
// Analog value -> Digital Value로 전환

readVal = map(readVal, 0, 1023, 0, 255);
//readVal을 읽어서 0~1023을 0~255로 비례적으로 맵핑

analogWrite(LED_PIN, readVal);
Serial.println(readVal);
delay(1000);
 
  

}
