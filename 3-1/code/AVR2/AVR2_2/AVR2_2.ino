
int LED = 26;

int LED1 = 27;

int LED2 = 28;

int LED3 = 29;

 

void setup(){

  pinMode(26,OUTPUT);

  pinMode(27,OUTPUT);

  pinMode(28,OUTPUT);

  pinMode(29,OUTPUT);

}

void loop(){

  digitalWrite(LED,HIGH);

  digitalWrite(LED1,HIGH);

  digitalWrite(LED2,HIGH);

  digitalWrite(LED3,HIGH);

  delay(1000);

  digitalWrite(LED,LOW);

  digitalWrite(LED1,HIGH);

  digitalWrite(LED2,HIGH);

  digitalWrite(LED3,HIGH);

  delay(1000);

  digitalWrite(LED,LOW);

  digitalWrite(LED1,LOW);

  digitalWrite(LED2,HIGH);

  digitalWrite(LED3,HIGH);

  delay(1000);

  digitalWrite(LED,LOW);

  digitalWrite(LED1,LOW);

  digitalWrite(LED2,LOW);

  digitalWrite(LED3,HIGH);

  delay(1000);

  digitalWrite(LED,LOW);

  digitalWrite(LED1,LOW);

  digitalWrite(LED2,LOW);

  digitalWrite(LED3,LOW);

}
