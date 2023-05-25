#define SOUND_PIN A2

void setup() {
  Serial.begin(9600);
  pinMode(SOUND_PIN,INPUT);
  pinMode(3,OUTPUT);
}

void loop() {
  int nValue = analogRead(SOUND_PIN);
  
  Serial.print("Sound Value : ");
  Serial.println(nValue);

  if(nValue>100) digitalWrite(3,HIGH);
  else digitalWrite(3,LOW);

delay(200);
}
