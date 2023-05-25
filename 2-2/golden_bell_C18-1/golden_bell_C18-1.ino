#define cds A2
#define led 3
int cdsvalue;
int p;

void setup() {

pinMode(cds, INPUT);
pinMode(led, OUTPUT);
Serial.begin(9600);

}

 

void loop() { 
  cdsvalue = analogRead(cds);
  Serial.println(cdsvalue);
  p=cdsvalue/4;
  delay(500);
  
  if(cdsvalue<350) // 밝으면 꺼지고
  {
  digitalWrite(led, LOW); //analogWrite로도 가능?
  }

  else if((cdsvalue>350)&&(cdsvalue<1000))//어두움 켜짐
  {
    analogWrite(led, p);
  }
  while(cdsvalue>1000)// 어두움 맥스.
  {
     delay(10000);
     digitalWrite(led,LOW);
     break;
  }     
}
