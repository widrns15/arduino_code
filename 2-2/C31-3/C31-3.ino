int sound = 7;
int led = 13;
int count = 0;

void setup() {
  Serial.begin(9600);
  pinMode(sound,INPUT);
  pinMode(led,OUTPUT);
}

void loop() {
  if(digitalRead(sound)==HIGH){
    count++;
    delay(200);
  }
  if(count==2) {
    count=0;
  }
  if(count==1) {
    digitalWrite(led,HIGH);
  }
  else {
    digitalWrite(led,LOW);
  }
  
}
