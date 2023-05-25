int sw1 = 22;
int sw2 = 23;
int sw3 = 24;
int sw4 = 25;
int LED = 26;
int LED1 = 27;
int LED2 = 28;
int LED3 = 29;

void setup(){
  pinMode(22,INPUT);
  pinMode(23,INPUT);
  pinMode(24,INPUT);
  pinMode(25,INPUT);
  pinMode(26,OUTPUT);
  pinMode(27,OUTPUT);
  pinMode(28,OUTPUT);
  pinMode(29,OUTPUT);
}

void loop(){
  if(digitalRead(22) == 1){
      for(int i=0; i<3; i++){
        digitalWrite(LED,LOW);
        digitalWrite(LED1,LOW);
        digitalWrite(LED2,LOW);
        digitalWrite(LED3,LOW);
        delay(100);
        digitalWrite(LED,HIGH);
        digitalWrite(LED1,LOW);
        digitalWrite(LED2,LOW);
        digitalWrite(LED3,LOW);
        delay(100);
        digitalWrite(LED,LOW);
        digitalWrite(LED1,HIGH);
        digitalWrite(LED2,LOW);
        digitalWrite(LED3,LOW);
        delay(100);
        digitalWrite(LED,LOW);
        digitalWrite(LED1,LOW);
        digitalWrite(LED2,HIGH);
        digitalWrite(LED3,LOW);
        delay(100);
        digitalWrite(LED,LOW);
        digitalWrite(LED1,LOW);
        digitalWrite(LED2,LOW);
        digitalWrite(LED3,HIGH);
        delay(100);
        digitalWrite(LED,LOW);
        digitalWrite(LED1,LOW);
        digitalWrite(LED2,LOW);
        digitalWrite(LED3,LOW);
        delay(100);
      }
  }
  else if(digitalRead(23) == 1){
      for(int i=0; i<2; i++){
        digitalWrite(LED,LOW);
        digitalWrite(LED1,LOW);
        digitalWrite(LED2,LOW);
        digitalWrite(LED3,LOW);
        delay(100);
        digitalWrite(LED,LOW);
        digitalWrite(LED1,LOW);
        digitalWrite(LED2,LOW);
        digitalWrite(LED3,HIGH);
        delay(100);
        digitalWrite(LED,LOW);
        digitalWrite(LED1,LOW);
        digitalWrite(LED2,HIGH);
        digitalWrite(LED3,LOW);
        delay(100);
        digitalWrite(LED,LOW);
        digitalWrite(LED1,HIGH);
        digitalWrite(LED2,LOW);
        digitalWrite(LED3,LOW);
        delay(100);
        digitalWrite(LED,HIGH);
        digitalWrite(LED1,LOW);
        digitalWrite(LED2,LOW);
        digitalWrite(LED3,LOW);
        delay(100);
        digitalWrite(LED,LOW);
        digitalWrite(LED1,LOW);
        digitalWrite(LED2,LOW);
        digitalWrite(LED3,LOW);
        delay(100);
      }
  }
  else if(digitalRead(24) == 1){
      for(int i=0; i<3; i++){
        digitalWrite(LED,LOW);
        digitalWrite(LED1,LOW);
        digitalWrite(LED2,LOW);
        digitalWrite(LED3,LOW);
        delay(100);
        digitalWrite(LED,HIGH);
        digitalWrite(LED1,LOW);
        digitalWrite(LED2,LOW);
        digitalWrite(LED3,LOW);
        delay(100);
        digitalWrite(LED,HIGH);
        digitalWrite(LED1,HIGH);
        digitalWrite(LED2,LOW);
        digitalWrite(LED3,LOW);
        delay(100);
        digitalWrite(LED,HIGH);
        digitalWrite(LED1,HIGH);
        digitalWrite(LED2,HIGH);
        digitalWrite(LED3,LOW);
        delay(100);
        digitalWrite(LED,HIGH);
        digitalWrite(LED1,HIGH);
        digitalWrite(LED2,HIGH);
        digitalWrite(LED3,HIGH);
        delay(100);
        digitalWrite(LED,LOW);
        digitalWrite(LED1,LOW);
        digitalWrite(LED2,LOW);
        digitalWrite(LED3,LOW);
        delay(100);
      }
  }
  else if(digitalRead(25) == 1){
      for(int i=0; i<2; i++){
        digitalWrite(LED,LOW);
        digitalWrite(LED1,LOW);
        digitalWrite(LED2,LOW);
        digitalWrite(LED3,LOW);
        delay(100);
        digitalWrite(LED,LOW);
        digitalWrite(LED1,LOW);
        digitalWrite(LED2,LOW);
        digitalWrite(LED3,HIGH);
        delay(100);
        digitalWrite(LED,LOW);
        digitalWrite(LED1,LOW);
        digitalWrite(LED2,HIGH);
        digitalWrite(LED3,HIGH);
        delay(100);
        digitalWrite(LED,LOW);
        digitalWrite(LED1,HIGH);
        digitalWrite(LED2,HIGH);
        digitalWrite(LED3,HIGH);
        delay(100);
        digitalWrite(LED,HIGH);
        digitalWrite(LED1,HIGH);
        digitalWrite(LED2,HIGH);
        digitalWrite(LED3,HIGH);
        delay(100);
        digitalWrite(LED,LOW);
        digitalWrite(LED1,LOW);
        digitalWrite(LED2,LOW);
        digitalWrite(LED3,LOW);
        delay(100);
      }
  }
  
}
