#define WATER_PIN A0

void setup() {
  Serial.begin(9600);

}

void loop() {
 int waterLevel = analogRead(WATER_PIN);
 Serial.print("WL = ");
 Serial.println(waterLevel);
 delay(200);

}
