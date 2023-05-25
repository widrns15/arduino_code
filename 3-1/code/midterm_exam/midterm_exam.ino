#include <avr/io.h>
#include <util/delay.h>

unsigned char led = 0x00; //LED 설정
unsigned char seg = 0xff; // seg 설정

int i=0,k;
int s=0;

void num(int n){
  switch(n){
    
    case 0 : 
    seg = 0xC0;
    led = 0x00;
    break;

    case 1 : 
    seg = 0xF9;
    led = 0x10;
    break;

    case 2 : 
    seg = 0xA4;
    led = 0x30;
    break;

    case 3 :
    seg = 0xB0;
    led = 0x70;
    break;

    case 4 : 
    seg = 0x99;
    led = 0xf0;
    break;

    case 5 : 
    seg = 0x92;
    led = 0x00;
    break;

    case 6 : 
    seg = 0x82;
    led = 0x10;
    break;

    case 7 : 
    seg = 0xF8;
    led = 0x30;
    break;

    case 8 : 
    seg = 0x80;
    led = 0x70;
    break;

    case 9 : 
    seg = 0x90;
    led = 0xf0;
    break;

    case 10 :
    seg = 0x00;
    led = 0x00;

  }
}

void setup(){

  DDRA = 0xff; //seg 초기값 설정
  DDRC = 0xf0; //LED 초기값 설정
  num(0); 

}



void loop(){

  PORTA = seg;
  
  if((PINC&0x01)==1)
  {
    if(s%2==0)
    {
      num(i);
      PORTA = seg;
      PORTC = led;
      delay(200);
      i++;
  
       if(i == 10){
        i = 0;
      }
    }
    delay(500);
    s++;
  }

  
  
  if((PINC&0x02)==2)
  {
    while(1){
      if((PINC&0x01)==1)
      {
        i=0;
        break;
      }
      num(0);
     
      
    }
  
  }
}
