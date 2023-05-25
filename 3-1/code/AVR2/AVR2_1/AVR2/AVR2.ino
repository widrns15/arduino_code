#include <avr/io.h>

#include <util/delay.h>

int main(void)

{

  unsigned char led = 0xf0;

  DDRA = 0xf0;

  do{

    PORTA = (led<<2);

    _delay_ms(1000);

    led <<= 1;

    led |= 0xf0; //or 연산

    if(led==0xf0){

      PORTA = (led>>4);

      _delay_ms(1000);

      led = 0x0f ;

    }}while(1);

    return 0;

}
