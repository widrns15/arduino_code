int main(void)
{
  unsigned char count=0, interrupt_count=0, flag;
  initialize_timer();
  interrupt_count=100;
  DDRD=0xf0;
  do{
    flag = TIFR & 0x03;
    // Timer/Counter 1 Overflow Flag TOV1 체크

    if(flag){
      TIFR |= 0x03;
      // TOV1를 소프트웨어적으로 강제 클리어. 1일 때 클리어 됨

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


/*
1) Timer/Counter란

Timer/Counter(이하 T/C)는 사용자가 필요로 하는 주기를 설정하여 일정 주기마다 작업을 할 수 있게하는 도구라고 할 수 있다.
여러 개의 레지스터로 이루어져 있는 장치로, 타이머가 설정된 주기마다 카운터에게 신호를 주면 카운터가 그 신호의 갯수를 센다.
신호가 들어올 때마다 카운터는 '+1'되는 느낌이다. 정해진 갯수가 될 때마다 작업을 작동시키는 방식으로 실행된다.

T/C 0번과 2번은 8bit T/C로, 2^8인 256마다 타이머가 카운터에게 신호를 주고

T/C 1번과 3번은 16bit T/C로, 2^16인 65536마다 타이머가 카운터에게 신호를 준다.

카운터는 타이머가 신호를 줄 때마다 증가하다가 OCn으로 설정한 값이 되면 인터럽트를 만든다.
위에서 설명한 것처럼 최댓값이자 기본값은 각각 256과 65536이다.

1 타이머는 10bit prescaler, Input Capture 가능 ,3개의 PWM(pulse) 출력 가능
(OCRA, B, C),10 Interrupt sources로 3가지 인터럽트가 있다

타이머/카운터 1은 TCNT 레지스터의 비트 수가 16비트이며,
8비트와 다르게 카운터 기능이 사용 가능하다.

TNCT1을 설정해주고 미리 세팅한 값에 도달하게 한다.
TIFR레지스터의 TOV1비트가 1이 될 때 인터럽트 벡터가 실행된다고 한다.
TIMSK 레지스터의 TOIE1 비트를 활성화시킨다. 값이 1이되고,
타이머/카운터1 오버플로 인터럽트 벡터가 실행되면 자동으로 TOV1은 0이 된다.
SREG의 I 비트가 1로 Set 되어 있으면 Timer Counter 1 Overflow
*/
