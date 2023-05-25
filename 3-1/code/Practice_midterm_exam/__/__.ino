// 완전 AVR 랜덤

#include <avr/io.h>
#include <util/delay.h>

unsigned char led = 0x00; //LED 설정
unsigned char seg = 0xff; // seg 설정
int i,k;


void setup(){
  DDRA = 0xff; //seg 초기값 설정
  DDRC = 0x0f; //LED 초기값 설정
  num(0); 
}

void loop(){

  PORTA = seg;
  int sw = digitalRead(47);
  if(sw == 1)
  {
    while(1)
    {
      num(i);
      PORTA = seg;
      delay(300);
      i = random(10);
      sw = digitalRead(47);
      
      if(sw == 1)
      {
        k = 1;
        delay(200);
        break;      
      }
    }
  }

  else if(k == 1){
    PORTA = seg;
    PORTC = led;
  }
}

 

void num(int n){

  switch(n){  

    case 0 : 
    seg = 0xC0;

    led = 0x00;

    break;

 

    case 1 : 

    seg = 0xF9;

    led = 0x01;

    break;

 

    case 2 : 

    seg = 0xA4;

    led = 0x02;

    break;

 

    case 3 :

    seg = 0xB0;

    led = 0x03;

    break;

 

    case 4 : 

    seg = 0x99;

    led = 0x04;

    break;

 

    case 5 : 

    seg = 0x92;

    led = 0x05;

    break;

 

    case 6 : 

    seg = 0x82;

    led = 0x06;

    break;

 

    case 7 : 

    seg = 0xF8;

    led = 0x07;

    break;

 

    case 8 : 

    seg = 0x80;

    led = 0x08;

    break;

 

    case 9 : 

    seg = 0x90;

    led = 0x09;

    break;

 

  }

}
