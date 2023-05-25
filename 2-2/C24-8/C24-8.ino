#define Me2 1318.510
#define Le2s 1244.508
#define Si 987.7666
#define Le2 1174.659
#define Do2 1046.502
#define Lal 880
#define Dol 523.2511
#define Mel 659.2551
#define Solls 830.6094
#define DELAY 300
#define Um 200
#define Umm2 800
#define sw1 2



void setup() {
  while(1){
  int melody[]={Me2,Le2s,Me2,Le2s,Me2,Si,Le2,Do2,Lal,Dol,Mel,Lal,Si,Mel,Solls,Si,Do2,Mel,Me2,Le2s,Me2,Le2s,Me2,Si,Le2,Do2,Lal,Dol,Mel,Lal,Si,Mel,Do2,Si,Lal};
  int length[]={Um,Um,Um,Um,Um,Um,Um,Um,Umm2,Um,Um,Um,Umm2,Um,Um,Um,Umm2,Um,Um,Um,Um,Um,Um,Um,Um,Um,Umm2,Um,Um,Um,Umm2,Um,Um,Um,Umm2};
  pinMode(2,INPUT);
  pinMode(9,OUTPUT);

  for(int i=0; i<35; i++)
  {
    tone(9, melody[i]); delay(length[i]);
    noTone(3); delay(100);
  }
}
}
void loop() {

 
}
