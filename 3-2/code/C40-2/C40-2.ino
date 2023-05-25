volatile int count=0;
const byte interruptPin = 2;

void setup() {

  noInterrupts();
  DDRA = 0xff; // led output
  interrupts();
  attachInterrupt(digitalPinToInterrupt(interruptPin),cnt,FALLING); 
}

//ISR(PCINT0_vect){
//count++;
//}

void loop() {
  if(count<=5){ //led on
    PORTA = 0xff;
  }
  if(count>5){ //led off
    PORTA = 0x00;
  }
  if(count==11) count=0;
}

void cnt(){
  count++;
}
