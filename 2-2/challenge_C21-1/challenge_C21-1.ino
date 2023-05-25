void setup() {
  pinMode(13,INPUT);
  pinMode(11,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  
if(digitalRead(13)==HIGH)
{
  Serial.println("on");
  digitalWrite(11,LOW);
}
else
{
  Serial.println("off");
  digitalWrite(11,HIGH);
}
delay(1000);

}
