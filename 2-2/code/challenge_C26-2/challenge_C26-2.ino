int DCmotor=10;
void setup() {
  pinMode(DCmotor,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int potentiometer=analogRead(A0)/4;
  analogWrite(DCmotor,potentiometer);
  Serial.print(potentiometer);
  Serial.println("\n");
  delay(100);
  
}
