int sound = 22;
int LED = 24;
int count = 0;

void setup(){
  pinMode(LED,OUTPUT);
  pinMode(sound,INPUT);
  Serial.begin(9600);
}

void loop(){
  if(digitalRead(sound) == HIGH){
    count++;
    delay(200);
  }
  if(count == 2)
  {
    count = 0;
  }
  if(count == 1){
    digitalWrite(LED,HIGH);
  }
  else{
    digitalWrite(LED,LOW);
  }
  Serial.println(count);
}
