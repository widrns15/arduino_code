int LED=13;

void setup() {
  pinMode(LED,OUTPUT);
  Serial.begin(9600);

}

void loop()
{
  if(Serial.available())
  {
    int LED_ON = Serial.parseInt();
    digitalWrite(LED,LED_ON);
    Serial.println("LED_ON");
    Serial.println(LED_ON);
    delay(5000);  
  }
}
