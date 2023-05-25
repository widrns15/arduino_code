#include<arduino.h>
#define ledA 3
#define ledB 7
#define ledC 11
#define ledD 9
#define ledE 8
#define ledF 4
#define ledG 12
#define DOT 10
#define seg1 2
#define seg2 5
#define seg3 6
#define seg4 13

int push=2;

void fnd(int n)   // 숫자 출력 함수
{ 
  switch(n)
  {
      case 0:
      //Displays 0
      digitalWrite(ledD, HIGH);
      digitalWrite(ledE, HIGH);
      digitalWrite(ledF, HIGH);
      digitalWrite(ledG, LOW);
      digitalWrite(ledA, HIGH);
      digitalWrite(ledB, HIGH);
      digitalWrite(ledC, HIGH);
      digitalWrite(DOT , LOW);
      break;
     
      case 1:
      //Displays 1
      digitalWrite(ledD, LOW);
      digitalWrite(ledE, LOW);
      digitalWrite(ledF, LOW);
      digitalWrite(ledG, LOW);
      digitalWrite(ledA, LOW);
      digitalWrite(ledB, HIGH);
      digitalWrite(ledC, HIGH);
      digitalWrite(DOT , LOW);
      break;  

      case 2:
      //Displays 2
      digitalWrite(ledD, HIGH);
      digitalWrite(ledE, HIGH);
      digitalWrite(ledF, LOW);
      digitalWrite(ledG, HIGH);
      digitalWrite(ledA, HIGH);
      digitalWrite(ledB, HIGH);
      digitalWrite(ledC, LOW);
      digitalWrite(DOT , LOW);
      break;
     
      case 3:
      //Displays 3
      digitalWrite(ledD, HIGH);
      digitalWrite(ledE, LOW);
      digitalWrite(ledF, LOW);
      digitalWrite(ledG, HIGH);
      digitalWrite(ledA, HIGH);
      digitalWrite(ledB, HIGH);
      digitalWrite(ledC, HIGH);
      digitalWrite(DOT , LOW);
      break;     

      case 4:
      //Displays 4
      digitalWrite(ledD, LOW);
      digitalWrite(ledE, LOW);
      digitalWrite(ledF, HIGH);
      digitalWrite(ledG, HIGH);
      digitalWrite(ledA, LOW);
      digitalWrite(ledB, HIGH);
      digitalWrite(ledC, HIGH);
      digitalWrite(DOT , LOW);
      break;
     
      case 5:
      //Displays 5
      digitalWrite(ledD, HIGH);
      digitalWrite(ledE, LOW);
      digitalWrite(ledF, HIGH);
      digitalWrite(ledG, HIGH);
      digitalWrite(ledA, HIGH);
      digitalWrite(ledB, LOW);
      digitalWrite(ledC, HIGH);
      digitalWrite(DOT , LOW);
      break;

      case 6:
      //Displays 6
      digitalWrite(ledD, HIGH);
      digitalWrite(ledE, HIGH);
      digitalWrite(ledF, HIGH);
      digitalWrite(ledG, HIGH);
      digitalWrite(ledA, HIGH);
      digitalWrite(ledB, LOW);
      digitalWrite(ledC, HIGH);
      digitalWrite(DOT , LOW);
      break;
      case 7:
      //Displays 7
      digitalWrite(ledD, LOW);
      digitalWrite(ledE, LOW);
      digitalWrite(ledF, LOW);
      digitalWrite(ledG, LOW);
      digitalWrite(ledA, HIGH);
      digitalWrite(ledB, HIGH);
      digitalWrite(ledC, HIGH);
      digitalWrite(DOT , LOW);
      break; 

      case 8:
      //Displays 8
      digitalWrite(ledD, HIGH);
      digitalWrite(ledE, HIGH);
      digitalWrite(ledF, HIGH);
      digitalWrite(ledG, HIGH);
      digitalWrite(ledA, HIGH);
      digitalWrite(ledB, HIGH);
      digitalWrite(ledC, HIGH);
      digitalWrite(DOT , LOW);
      break;
     
      case 9:
      //Displays 9
      digitalWrite(ledD, HIGH);
      digitalWrite(ledE, LOW);
      digitalWrite(ledF, HIGH);
      digitalWrite(ledG, HIGH);
      digitalWrite(ledA, HIGH);
      digitalWrite(ledB, HIGH);
      digitalWrite(ledC, HIGH);
      digitalWrite(DOT , LOW);
      break;    
       
  }
}  
void clr()   //led clear 함수
{
  //Clears the LED

  digitalWrite(ledA, LOW);
  digitalWrite(ledB, LOW);
  digitalWrite(ledC, LOW);
  digitalWrite(ledD, LOW);
  digitalWrite(ledE, LOW);
  digitalWrite(ledF, LOW);
  digitalWrite(ledG, LOW);
  digitalWrite(DOT , LOW);
}
void set()  // led set 함수
{  
  //Set the LED

  digitalWrite(ledA, HIGH);
  digitalWrite(ledB, HIGH);
  digitalWrite(ledC, HIGH);
  digitalWrite(ledD, HIGH);
  digitalWrite(ledE, HIGH);
  digitalWrite(ledF, HIGH);
  digitalWrite(ledG, HIGH);
  digitalWrite(DOT , HIGH);
}
// Switch를 누를 때마다 1씩 증가하는 Program

int a[4]= {0,0,0,0};  // 각 segment 숫자를 저장할 배열        
int b;

#define sw1 A0   // sw1 을 A0로 지정
#define sw2 A1   // sw1 을 A0로 지정
#define sw3 A2   // sw1 을 A0로 지정

void setup()
{
  //각각의 핀들을 OUTPUT으로 설정해 준다.
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledC, OUTPUT);
  pinMode(ledD, OUTPUT);
  pinMode(ledE, OUTPUT);
  pinMode(ledF, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(DOT, OUTPUT);
  pinMode(seg1, OUTPUT);
  pinMode(seg2, OUTPUT);
  pinMode(seg3, OUTPUT);
  pinMode(seg4, OUTPUT);
  pinMode(sw1, INPUT);
  pinMode(sw2, INPUT);
  pinMode(sw3, INPUT);  // 1번 포트로 스위치 값 입력받음
  
  Serial.end(); 
  /* Serial.end는 Serial통신 핀(0, 1번)을 사용하지 않도록 하는 함수임
     Serial.begin()이 Serial 통신을 사용하기 위해 사용되는 것이면, 
     Serial.end()는 Serial 핀( 0, 1번)을 일반 디지털 핀으로 사용하게 하는 함수*/
}
void loop()
{  
   int sw1_state = digitalRead(sw1);
   int sw2_state = digitalRead(sw2);
   int sw3_state = digitalRead(sw3);   //스위치가 연결된 1번 포트의 값을 읽어옴 
   
   if((sw1_state==1)||(push==0))
   { push=0;
     ++a[3];
     if(a[3]>9)
     {
      a[3]=0;
      ++a[2];
     }
     if(a[2]>9)
     {
      a[2]=0;
      ++a[1]; 
     }
     if(a[1]>9)
     {
      a[1]=0;
      ++a[0];
     }
     if(a[0]>9)
     {
      a[0]=0;
     }
     delay(1000);
   }

  if((sw2_state==1)||(push==1))
   { 
      push=1;
   }
  
  if((sw3_state==1)||(push==2))
    {
      push=2;
      
      a[3]=0;
      a[2]=0;
      a[1]=0;
      a[0]=0;
    }


   for(b=0;b<5;b++)   /* sw1의 입력이 여러 번 들어가는 것을 방지, delay 역할*/ 
     {
     digitalWrite(seg1,LOW);
     fnd(a[0]);
     delay(5);
     digitalWrite(seg1,HIGH);
     digitalWrite(seg2,LOW);
     fnd(a[1]);
     delay(5);
     digitalWrite(seg2,HIGH);
     digitalWrite(seg3,LOW);
     fnd(a[2]);
     delay(5);
     digitalWrite(seg3,HIGH);
     digitalWrite(seg4,LOW);
     fnd(a[3]);
     delay(5);
     digitalWrite(seg4,HIGH);
     }
   }
