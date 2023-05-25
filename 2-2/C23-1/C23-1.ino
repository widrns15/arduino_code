#define flame A0

void setup() {
  Serial.begin(9600);
  pinMode(flame,INPUT);

}

void loop() {
  int flamesensor = analogRead(flame);
  Serial.print("Flame Sensor Value : ");
  Serial.println(flamesensor);
  delay(1000);

}
