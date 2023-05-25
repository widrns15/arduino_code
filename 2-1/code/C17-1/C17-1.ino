int TEMP_PIN=A0; 
int value;
float Temp_current;

void setup() {

  pinMode(TEMP_PIN, INPUT);
  Serial.begin(9600);
}

 

void loop() { // 아래는 풀 다운 세팅.

  value = analogRead(TEMP_PIN);
  Temp_current = (5.0*value*100.0)/1024.0;
  Serial.print("Temp:");
  Serial.print(Temp_current);
  Serial.print("\n");
  delay(1000);
 }
