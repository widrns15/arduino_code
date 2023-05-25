#define flame A1
#define led 7

void setup() {
  Serial.begin(9600);
  pinMode(flame,INPUT);
  pinMode(led,OUTPUT);

}

void loop() {
  int flamesensor = analogRead(flame);
  Serial.print("Flame Sensor Value : ");
  Serial.println(flamesensor);
  delay(1000);

  if(flamesensor > 1000)
  {
    digitalWrite(led,LOW);
  }

  if(flamesensor < 1000)
  {
    digitalWrite(led,HIGH);
  }
  
 }
