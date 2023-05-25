// 홀짝 

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
  int i,k,p=0;
  


if((PINC&0x01)==1){
  while(p==0){
    for(i=t; i<=4; i++)
    {
      PORTA=segment[i*2+1];
      PORTC=led[i*2+1];
      _delay_ms(500);
      if((PINC&0x02)==2){
         t=i;
         p=1;
        break;
      }
      
    }
   }
 }


  if((PINC&0x02)==2){
  while(p==1){
    for(t=i; t<=4; t++)
    {
      PORTA=segment[t*2];
      PORTC=led[t*2];
      _delay_ms(500);
       if((PINC&0x01)==1){
        i=t;
        p=0;
        break;
      }
}
  }
  }
}
