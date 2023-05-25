int ledA=2;
int ledB=3;
int ledC=4;
int ledD=5;
int ledE=6;
int ledF=7;
int ledG=8;
int DOT=9;
int sw1=10;
int sw2=11;

int cnt =0;


void setup() {
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledC, OUTPUT);
  pinMode(ledD, OUTPUT);
  pinMode(ledE, OUTPUT);
  pinMode(ledF, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(DOT, OUTPUT);
}

void loop() {
  int sw1_state;
  int sw2_state;
  sw1_state=digitalRead(sw1);
  sw2_state=digitalRead(sw2);
  


while(sw1_state==1)
  {
    sw2_state = digitalRead(sw2);
      if(sw2_state==1)
    {
      break;
    } 
     Number(cnt);
      ++cnt;
      delay(1000);
    if(cnt>9)
      {
        cnt=0;
      }
  }
  sw1_state = digitalRead(sw1);
  sw2_state = digitalRead(sw2);
  if(sw1_state==1&&sw2_state==1){
    while(sw1_state==1&&sw2_state==1){
      for(cnt=0; cnt<5; ++cnt){
        Number(cnt*2);
        delay(500);
      }
    }
  } 
  
while(sw2_state==1)
  {
      sw1_state = digitalRead(sw1);
      if(sw1_state==1)
    {
      break; 
    }
     Number(cnt);
      --cnt;
      delay(1000);
    if(cnt<0)
      {
        cnt=9;
      }
  }                                       // 먼저 비교하면서 기본틀부터 보고 뭐가 추가되었는지.뭐가 어떻게 되었는지
  sw1_state = digitalRead(sw1);           // 1. 위치 파악, 2. 구조 파악(각자 무슨 역할을 하는지)
  sw2_state = digitalRead(sw2);           // 3. 가감법, 4. 구조,위치 변경, 5. 테스트. 6. 최적화.
  if(sw1_state==1&&sw2_state==1){
    while(sw1_state==1&&sw2_state==1){    // * 문제에선 동시에 누르는 경우이기때문에 입력값을 한 번더 준 후
      for(cnt=0; cnt<5; ++cnt){           // 주어진 조건을 이어나감
        Number(cnt*2);
        delay(500);
      }
    }
  } 
}




void Number(int n)
{
  switch(n){
    
    case 0: // 0출력
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledC, HIGH);
    digitalWrite(ledD, HIGH);
    digitalWrite(ledE, HIGH);
    digitalWrite(ledF, HIGH);
    digitalWrite(ledG, LOW);
    digitalWrite(DOT, LOW);
    break;
    
    case 1: // 1 출력
    digitalWrite(ledA, LOW);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledC, HIGH);
    digitalWrite(ledD, LOW);
    digitalWrite(ledE, LOW);
    digitalWrite(ledF, LOW);
    digitalWrite(ledG, LOW);
    digitalWrite(DOT, LOW);
    break;

    case 2: // 2 출력
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledC, LOW);
    digitalWrite(ledD, HIGH);
    digitalWrite(ledE, HIGH);
    digitalWrite(ledF, LOW);
    digitalWrite(ledG, HIGH);
    digitalWrite(DOT, LOW);
    break;

    case 3: // 3 출력
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledC, HIGH);
    digitalWrite(ledD, HIGH);
    digitalWrite(ledE, LOW);
    digitalWrite(ledF, LOW);
    digitalWrite(ledG, HIGH);
    digitalWrite(DOT, LOW);
    break;

    case 4: // 4 출력
    digitalWrite(ledA, LOW);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledC, HIGH);
    digitalWrite(ledD, LOW);
    digitalWrite(ledE, LOW);
    digitalWrite(ledF, HIGH);
    digitalWrite(ledG, HIGH);
    digitalWrite(DOT, LOW);
    break;

    case 5: // 5 출력
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, LOW);
    digitalWrite(ledC, HIGH);
    digitalWrite(ledD, HIGH);
    digitalWrite(ledE, LOW);
    digitalWrite(ledF, HIGH);
    digitalWrite(ledG, HIGH);
    digitalWrite(DOT, LOW);
    break;

    case 6: // 6 출력
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, LOW);
    digitalWrite(ledC, HIGH);
    digitalWrite(ledD, HIGH);
    digitalWrite(ledE, HIGH);
    digitalWrite(ledF, HIGH);
    digitalWrite(ledG, HIGH);
    digitalWrite(DOT, LOW);
    break;

    case 7: // 7 출력
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledC, HIGH);
    digitalWrite(ledD, LOW);
    digitalWrite(ledE, LOW);
    digitalWrite(ledF, HIGH);
    digitalWrite(ledG, LOW);
    digitalWrite(DOT, LOW);
    break;

    case 8: // 8 출력
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledC, HIGH);
    digitalWrite(ledD, HIGH);
    digitalWrite(ledE, HIGH);
    digitalWrite(ledF, HIGH);
    digitalWrite(ledG, HIGH);
    digitalWrite(DOT, LOW);
    break;

    case 9: // 9 출력
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledC, HIGH);
    digitalWrite(ledD, HIGH);
    digitalWrite(ledE, LOW);
    digitalWrite(ledF, HIGH);
    digitalWrite(ledG, HIGH);
    digitalWrite(DOT, LOW);
    break;


  }
}
