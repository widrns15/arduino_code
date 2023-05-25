int led1=5;
int led2=6;

void setup() {
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(8,INPUT);
  Serial.begin(9600);

}

void loop() {
  
  int value;
  if(Serial.available()>0){
  value=Serial.parseInt();
  Serial.println(value);
  analogWrite(5,value);
  analogWrite(6,255-value);

  while(digitalRead(8)==1)
  {
    while(1){
    if(Serial.available()>0){
    value=Serial.parseInt();
    Serial.println(value);  
   
    digitalRead(8);
    analogWrite(5,255-value);
    analogWrite(6,value);
  }
}
}
  }
}
