int Sensor = A2;

void setup(){
  Serial.begin(9600);
  pinMode(Sensor, INPUT);
  pinMode(24,OUTPUT);
}
void loop(){
  int Sound = analogRead(Sensor);
  Serial.println(Sound);

  if(Sound > 520){
    digitalWrite(24,HIGH);
  }
  else
  digitalWrite(24,LOW);
  delay(20);
}
