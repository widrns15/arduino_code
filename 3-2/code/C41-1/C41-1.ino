int sw;
int int_sw = 2;
int led1 = 22;
int led2 = 24;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(int_sw, INPUT_PULLUP);
}

void loop() {
  sw = digitalRead(2);
  digitalWrite(led1,HIGH);
  delay(2000);
  digitalWrite(led1,LOW);
  delay(2000);
  if(sw==1)
    digitalWrite(led2,LOW);
  else
    digitalWrite(led2,HIGH);
}
