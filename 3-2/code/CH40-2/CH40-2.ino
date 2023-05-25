int led=22;
volatile int state = LOW;
//풀다운 - 인터럽 사용이므로 LOW로 항상 꺼줌, 중요함

void blink(){
  state=! state;
}

void setup() {
  pinMode(led,OUTPUT);
  pinMode(3, INPUT_PULLUP);
  //풀업 회로 그대로 해도 무관, 회로 구성 또한 Polling으로해도 무관
  attachInterrupt(1,blink,RISING);
  //Interrupt 설정 함수 (Interrupt no., ISR, Mode)
}

void loop() {
  digitalWrite(led, state);
}
