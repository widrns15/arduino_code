int Sensor = A2;

void setup() {
  Serial.begin(9600);
  pinMode(Sensor,INPUT);
  pinMode(24,OUTPUT);
  pinMode(25,OUTPUT);
  pinMode(26,OUTPUT);
}

void loop() {
  int Sound = analogRead(Sensor);
  delay(100);
  Serial.println(Sound);
  

  if(Sound > 600){
    digitalWrite(24,HIGH);
  }
  if(Sound > 700){
    digitalWrite(25,HIGH);
  }
  if(Sound > 800){
    digitalWrite(26,HIGH);
 }
}
