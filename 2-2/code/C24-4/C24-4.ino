void setup() {
  pinMode(9,OUTPUT);
  Serial.begin(9600);
}

void loop() {

 int adjust = analogRead(A1);

 tone(9, 3*adjust, 300);

 Serial.println(2*adjust);
 
 delay(300);
 noTone(9);
 delay(300);
}
