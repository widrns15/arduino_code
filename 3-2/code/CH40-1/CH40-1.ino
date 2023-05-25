/* External Interrupt - SREG, EIMSK, EIFR, EICRA, EICRB
--------------------------------------------------------------------
External Interrupt를 처리하는 방식은 2가지이다.

1. interrupt Vector에 의한 방법
2. EIFR를 직접 이용하여 Program으로 처리하는 방법
(SREG를 0으로 만들고 단독적으로 진행 가능)
--------------------------------------------------------------------
ch1 - EIFR Register를 이용하여, External Interrupt(INT2)를 처리하는 Program을 AVR 
명령어를 이용하여 설명을 하세요

> 벡터를 이용하지 않는 방법으로 우선 cli() 진행
- SREG의 최상위 비트 I를 0으로 설정
- INT0 Flag Register(첫번째 비트가)가 Set 되었으면 처리

>
int main(void)
{
unsigned char interrupt_count=0, flag;
initialize();
DDRD = 0xf0;
do{
flag = EIFR & 0x03; 
//INT2 Flag Register (세번째 비트)가 Set 이 됐는지 판단
if(flag){ 
//Flag Register가 Set 되었으면, INT2 Interrupt request
interrupt_count++;
if(interrupt_count>9)
interrupt_count=0;
PORTD = (interrupt_count<<4);
EIFR |= 0x03; 
// EIFR의 최하위 비트인 INT0의 flag를 강제 클리어 시킴. 1일 때 클리어 됨
 EIFR 비트가 Bounce 현상 때문에 여러개의 입력 펄스 입력으로 Set되어 있을 가
능성이 높아서 강제로 클리어 시켜서 INT0 스위치가 한번 누를 때 여러 번 누른 것
과 같은 효과를 없애기 위해서 임
}
}while(1);
}


*/
