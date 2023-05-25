#define SOUND_PIN A2

void setup() {
  Serial.begin(9600);
}

void loop() {
  int nValue = analogRead(SOUND_PIN);

  Serial.print("Sound Value : ");
  Serial.println(nValue);

delay(200);
}
