#define BUZ 9
#define DO 256
#define RE 288
#define MI 320
#define FA 341
#define SO 384
#define LA 427
#define TI 480
#define DELAY 300

int music[] = {SO,SO,LA,LA,SO,SO,MI,SO,SO,MI,MI,RE,SO,SO,LA,LA,SO,SO,MI,SO,MI,RE,MI,DO};


void setup() {

}

void loop() {
  music_play();
}

void music_play()
{
  for(int i=0; i<sizeof(music)/sizeof(int); i++)
  {
    tone(BUZ, music[i]*2, 5000); // *2의 이유 진폭 확대 (소리가 선명)
    delay(DELAY);
  // 여러 부저를 사용 시, noTone(9)를 사용해야 다른 부저 소리를 낼 수 있음
  }
}
  
  
