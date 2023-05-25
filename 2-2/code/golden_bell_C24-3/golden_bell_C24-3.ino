#define BUZ A1
#define DO 256
#define RE 288
#define MI 320
#define FA 341
#define SO 384
#define LA 427
#define TI 480
#define f_4 349
#define g_4 392
#define a_4 440
#define Me2 1318.510
#define Le2s 1244.508
#define Si 987.7666
#define Le2 1174.659
#define Do2 1046.502
#define Lal 880
#define Dol 523.2511
#define Mel 659.2551
#define Solls 830.6094

#define DELAY 10

#define l_4 800
#define l_8 400
#define l_8p 600
#define l_16 200
#define l_2 1600
#define sw1 2
#define sw2 3
#define sw3 4
#define sw4 5

int ledA=6;
int ledB=7;
int ledC=8;
int ledD=9;
int ledE=10;
int ledF=11;
int ledG=12;
int DOT=13;

int p=0;

void setup() {

pinMode(A1,OUTPUT);
pinMode(sw1,INPUT);
pinMode(sw2,INPUT);
pinMode(sw3,INPUT);
pinMode(sw4,INPUT);
pinMode(ledA, OUTPUT);
pinMode(ledB, OUTPUT);
pinMode(ledC, OUTPUT);
pinMode(ledD, OUTPUT);
pinMode(ledE, OUTPUT);
pinMode(ledF, OUTPUT);
pinMode(ledG, OUTPUT);
pinMode(DOT, OUTPUT);
clr();
set();
}


void loop() {
  

int music[28] = {SO,MI,MI,FA,RE,RE,DO,RE,MI,FA,SO,SO,SO,SO,SO,MI,MI,MI,FA,RE,RE,DO,MI,SO,SO,MI,MI,MI};
int length[28]={l_8,l_8,l_4,l_8,l_8,l_4,l_8,l_8,l_8,l_8,l_8,l_8,l_4,l_8,l_8,l_8,l_8,l_8,l_8,l_4,l_8,l_8,l_8,l_8,l_8,l_8,l_4};

int music2[25]={a_4,g_4,f_4,g_4,a_4,a_4,a_4,g_4,g_4,g_4,a_4,a_4,a_4,a_4,g_4,f_4,g_4,a_4,a_4,a_4,g_4,g_4,a_4,g_4,f_4};
int length2[25]={l_8p,l_16,l_8,l_8,l_8,l_8,l_4,l_8,l_8,l_4,l_8,l_8,l_4,l_8p,l_16,l_8,l_8,l_8,l_8,l_4,l_8,l_8,l_8p,l_16,l_2};

int music3[35]={Me2,Le2s,Me2,Le2s,Me2,Si,Le2,Do2,Lal,Dol,Mel,Lal,Si,Mel,Solls,Si,Do2,Mel,Me2,Le2s,Me2,Le2s,Me2,Si,Le2,Do2,Lal,Dol,Mel,Lal,Si,Mel,Do2,Si,Lal};
int length3[35]={l_16,l_16,l_16,l_16,l_16,l_16,l_16,l_16,l_4,l_16,l_16,l_16,l_4,l_16,l_16,l_16,l_4,l_16,l_16,l_16,l_16,l_16,l_16,l_16,l_16,l_16,l_4,l_16,l_16,l_16,l_4,l_16,l_16,l_16,l_4};

  int sw1_state = digitalRead(sw1);
  int sw2_state = digitalRead(sw2);
  int sw3_state = digitalRead(sw3);
  int sw4_state = digitalRead(sw4);
  
  
if(p==0){
  while(sw1_state==HIGH)
{
     for(int i=0; i<28; i++)     // sizeof(music)/sizeof(int) 뜻??
  {
    sw4_state = digitalRead(sw4); // 무조건 for문안에 위치.
    if(sw4_state==1)
    {
      p=1;
      break;
    }
    
    Number(1);
    
    tone(BUZ, music[i]*2); delay(length[i]); // *2의 이유 진폭 확대 (소리가 선명)
    noTone(A1);  delay(DELAY);
  }
 break;// 얘 없으면 겨우 한껍데기 나가는겨.
}

  while(sw2_state==HIGH)
  {
    for(int t=0; t<25; t++)
  {
    sw4_state = digitalRead(sw4); // 무조건 for문안에 위치.
    if(sw4_state==1)
    {
      p=1;
      break;
    }
    
    Number(2);
    
    tone(BUZ, music2[t]*2); delay(length2[t]);
    noTone(A1); delay(DELAY);   // 의문점 3. DELAY의 값을 줄이는 것이 맞나
  }
  break;
}

  while(sw3_state==HIGH)
  {
    for(int T=0; T<35; T++)
  {
    sw4_state = digitalRead(sw4); // 무조건 for문안에 위치.
    if(sw4_state==1)
    {
      p=1;
      break;
    }
    
    Number(3);
    
    tone(BUZ, music3[T]); delay(length3[T]);
    noTone(A1); delay(DELAY);
  }
  break;
}
}

while(p==1){
  int sw1_state = digitalRead(sw1);
  int sw2_state = digitalRead(sw2);
  int sw3_state = digitalRead(sw3);  

  if((sw1_state==1)||(sw2_state==1)||(sw3_state==1))
    {
      p=0;
      break;
    }
  
  Number(0);
  delay(500);
  clr(); 
}

clr();
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
  }
}

void clr()
{
    digitalWrite(ledA, LOW);
    digitalWrite(ledB, LOW);
    digitalWrite(ledC, LOW);
    digitalWrite(ledD, LOW);
    digitalWrite(ledE, LOW);
    digitalWrite(ledF, LOW);
    digitalWrite(ledG, LOW);
    digitalWrite(DOT, LOW);
    delay(500);
}

void set()
{
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledC, HIGH);
    digitalWrite(ledD, HIGH);
    digitalWrite(ledE, HIGH);
    digitalWrite(ledF, HIGH);
    digitalWrite(ledG, HIGH);
    digitalWrite(DOT, HIGH);
    delay(2000);
}
  
