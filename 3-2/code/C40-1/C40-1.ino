int led=22;
volatile int state = HIGH;

void blink(){
  state=! state;
}

void setup() {
  pinMode(led,OUTPUT);
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(0,blink,FALLING);
  //Interrupt 설정 함수 (Interrupt no., ISR, Mode)
}

void loop() {
  digitalWrite(led, state);
}
