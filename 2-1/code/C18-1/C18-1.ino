#define cds A2
int cdsvalue;


void setup() {

pinMode(cds, INPUT);
Serial.begin(9600);

}

 

void loop() { // 아래는 풀 다운 세팅.

  cdsvalue = analogRead(cds);
  Serial.println(cdsvalue);
  delay(1000);
 }
