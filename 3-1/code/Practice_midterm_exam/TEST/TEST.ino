// 완전 아두이노 순차적

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int k=0;
int t = 0;

void setup(){
   DDRA = 0xff;
   DDRC = 0xf0; // 33-led, 37-sw
}


void loop()
{
  int segment[10] = {0xC0,0xf9,0xA4,0xB0,0x99,0x92,0x82,0xD8,0x80,0x90};
  int led[10]= {0x00,0x10,0x20,0x30,0x40,0x50,0x60,0x70,0x80,0x90};
  int i,k,p;
  


if((PINC&0x02)==2){
  while(k==0){
    for(i=t; i<=9; i++)
    {
      t = 0;
      PORTA=segment[i];
      PORTC=led[i];
      _delay_ms(500);

      if((PINC&0x02)==2){
      k = 1;
      delay(500);
      break;
      }
   }
   while(k == 1){
   PORTA = segment[i];
   PORTC = led[i];
   if((PINC&0x02)==2){
    k=0;
    t = i;
   break;
  }
}
  }
}
}
