int main(void)
{
  unsigned char count=0, interrupt_count=0, flag;
  initialize_timer();
  interrupt_count=100;
  DDRD=0xf0;
  do{
    flag = TIFR & 0x01;
    // Timer/Counter 0 Overflow Flag TOV0 체크

    if(flag){
      TIFR |= 0x01;
      // TOV0를 소프트웨어적으로 강제 클리어. 1일 때 클리어 됨

      TCNT0 = 0x70;
      interrupt_count--; // 초기치 = 100
      if(!interrupt_count){ // 10ms * 100 = 1000ms delay = 1s
        interrupt_count = 100;
        count++;
        if(count>9)
        count=0;
        PORTD = (count<<4);
      }
    }
    }while(1);
}
