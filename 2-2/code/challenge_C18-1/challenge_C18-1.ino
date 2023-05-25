#define cds A2
#define led 3
int cdsvalue;


void setup() {
pinMode(cds, INPUT);
pinMode(led, OUTPUT);
Serial.begin(9600);
}
 

void loop() { // 아래는 풀 다운 세팅.

  cdsvalue = analogRead(cds);
  Serial.println(cdsvalue);
  delay(500);
  if(cdsvalue<500)
  {
  digitalWrite(led, LOW);
  delay(1000);
  digitalWrite(led, HIGH);
  delay(1000);
  }
  else if(cdsvalue>500)
  {
  digitalWrite(led, HIGH);
  } 
 }
