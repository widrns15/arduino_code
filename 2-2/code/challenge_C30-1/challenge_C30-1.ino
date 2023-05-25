int led1=3;
int led2=4;
int led3=5;

void setup() {
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  Serial.begin(9600);

}

void loop() {
  char data;
  if(Serial.available()){
  data=Serial.read();

  if(data=='1'){
    digitalWrite(led1,HIGH);
    Serial.println("LED1 ON");
    delay(3000);
    digitalWrite(led1,LOW);
    Serial.println("LED1 OFF");
  }

  if(data=='2'){
    digitalWrite(led2,HIGH);
    Serial.println("LED2 ON");
    delay(3000);
    digitalWrite(led2,LOW);
    Serial.println("LED2 OFF");
  }

  if(data=='3'){
    digitalWrite(led3,HIGH);
    Serial.println("LED3 ON");
    delay(3000);
    digitalWrite(led3,LOW);
    Serial.println("LED3 OFF");
  }
}
}
