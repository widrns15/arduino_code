int switch_state;
int LED = 33;

void setup() {

  pinMode(37,INPUT);

  pinMode(33,OUTPUT);

}

void loop() {

  switch_state = digitalRead(37);

  if(switch_state==1)

    digitalWrite(LED,HIGH);

  else

    digitalWrite(LED,LOW);
}
