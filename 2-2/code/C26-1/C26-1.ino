int DCmotor=10;
void setup() {
  pinMode(DCmotor,OUTPUT);

}

void loop() {
  digitalWrite(DCmotor,HIGH);
  delay(2000);
  digitalWrite(DCmotor,LOW);
  delay(2000);
}
