#define cds A2
#define led 3
int cdsvalue;


void setup() {

pinMode(cds, INPUT);
pinMode(led, OUTPUT);
Serial.begin(9600);

}

 

void loop() {

  cdsvalue = analogRead(cds);
  Serial.println(cdsvalue);
  delay(500);
  if(cdsvalue>500) digitalWrite(led, HIGH);
  delay(500);
  if(cdsvalue<500) digitalWrite(led, LOW);
  delay(500);
  }
