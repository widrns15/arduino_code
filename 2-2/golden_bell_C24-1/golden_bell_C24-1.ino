#define BUZ A1
#define DO 256
#define RE 288
#define MI 320
#define FA 341
#define SO 384

#define DELAY 300

#define sw1 2
#define sw2 3
#define sw3 4
#define sw4 5
#define sw5 6



void setup() {
//int music[] = {SO,MI,MI,FA,RE,RE,DO,RE,MI,FA,SO,SO,SO,SO,SO,MI,MI,MI,FA,RE,RE,DO,MI,SO,SO,MI,MI,MI};
//int length[]={l_8,l_8,l_4,l_8,l_8,l_4,l_8,l_8,l_8,l_8,l_8,l_8,l_4,l_8,l_8,l_8,l_8,l_8,l_8,l_4,l_8,l_8,l_8,l_8,l_8,l_8,l_4};

pinMode(A1,OUTPUT);
pinMode(sw1,INPUT);
pinMode(sw2,INPUT);
pinMode(sw3,INPUT);
pinMode(sw4,INPUT);
pinMode(sw5,INPUT);

}
/* for(int i=0; i<sizeof(music)/sizeof(int); i++)
  {
    tone(BUZ, music[i]); // *2의 이유 진폭 확대 (소리가 선명)
    noTone(3); delay(DELAY);
  // 여러 부저를 사용 시, noTone(9)를 사용해야 다른 부저 소리를 낼 수 있음
  }
}*/

void loop() {

int music[]={DO,RE,MI,FA,SO};

  int sw1_state = digitalRead(sw1);
  int sw2_state = digitalRead(sw2);
  int sw3_state = digitalRead(sw3);
  int sw4_state = digitalRead(sw4);
  int sw5_state = digitalRead(sw5);

  if(sw1_state==HIGH)
  {
     tone(BUZ, music[0]); 
  }

  else if(sw2_state==HIGH)
  {
     tone(BUZ, music[1]);
  }

  else if(sw3_state==HIGH)
  {
     tone(BUZ, music[2]);
  }

  else if(sw4_state==HIGH)
  {
     tone(BUZ, music[3]);
  }

  else if(sw5_state==HIGH)
  {
     tone(BUZ, music[4]);
  }

  else
  {
    noTone(A1);
  }
  
}

  
