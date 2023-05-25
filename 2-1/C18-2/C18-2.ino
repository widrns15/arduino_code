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
  analogWrite(led,cdsvalue/4);
  Serial.println(cdsvalue);
  delay(1000);
 }
