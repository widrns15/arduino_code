void setup() {
  int led=9;
  pinMode(led,OUTPUT);
  digitalWrite(led,LOW);
  Serial.begin(9600);

}

void loop() {
  int value;
  if(Serial.available()){
    value=Serial.parseInt();
    analogWrite(9,value);
    Serial.println(value);
    delay(3000);
  }
}
