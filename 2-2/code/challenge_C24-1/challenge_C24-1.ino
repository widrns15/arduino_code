#define BUZ 9
#define DO 256
#define RE 288
#define MI 320
#define FA 341
#define SO 384
#define LA 427
#define TI 480
#define DELAY 300

#define l_4 800
#define l_8 400
#define l_8p 600
#define l_16 200



void setup() {
  while(1){
int music[] = {SO,MI,MI,FA,RE,RE,DO,RE,MI,FA,SO,SO,SO,SO,SO,MI,MI,MI,FA,RE,RE,DO,MI,SO,SO,MI,MI,MI};
int length[]={l_8,l_8,l_4,l_8,l_8,l_4,l_8,l_8,l_8,l_8,l_8,l_8,l_4,l_8,l_8,l_8,l_8,l_8,l_8,l_4,l_8,l_8,l_8,l_8,l_8,l_8,l_4};

pinMode(9,OUTPUT);

 for(int i=0; i<sizeof(music)/sizeof(int); i++)
  {
    tone(BUZ, music[i]); // *2의 이유 진폭 확대 (소리가 선명)
    noTone(3); delay(DELAY);
  // 여러 부저를 사용 시, noTone(9)를 사용해야 다른 부저 소리를 낼 수 있음
  }
  
}
}
void loop() {
}
  
