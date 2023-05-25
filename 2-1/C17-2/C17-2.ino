int TEMP_PIN=A0; 
int value;
float Temp_current;
int led=13;

void setup() {
  pinMode(led,OUTPUT);
  pinMode(TEMP_PIN, INPUT);
  Serial.begin(9600);
}
 

void loop() {

  value = analogRead(TEMP_PIN);
  Temp_current = (5.0*value*100.0)/1024.0;
  if(Temp_current>=30)
  {
    digitalWrite(led,HIGH);
  }
  else
  {
    digitalWrite(led,LOW);
  }
  Serial.print("Temp:");
  Serial.print(Temp_current);
  Serial.print("\n");
  delay(1000);
 }
