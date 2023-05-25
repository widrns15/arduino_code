#include <Keypad.h>
int BUZ= 11;
char key;

#define DO 256
#define RE 288
#define MI 320
#define FA 341
#define SO 384
#define LA 427
#define TI 480
#define Me2 1318.510
#define Le2s 1244.508
#define Si 987.7666
#define Le2 1174.659
#define Do2 1046.502
#define Lal 880
#define Dol 523.2511
#define Mel 659.2551
#define Solls 830.6094


//키패드 행, 열 크기
const byte ROWS = 4;
const byte COLS = 4;

// 키패드의 각 키별 값 설정
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

// 아두이노와 연결된 핀
byte rowPins[ROWS] = {5, 4, 3, 2}; // 열(ROW) 연결 핀
byte colPins[COLS] = {6, 7, 8, 9}; // 행(COL) 연결 핀

// 키패드 초기화
Keypad keypad = Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS);

void setup() {
  pinMode(11, OUTPUT);
}

void loop() {

 int music[]={DO,RE,MI,FA,SO,LA,TI,Me2,Le2s,Si,Le2,Do2,Lal,Dol,Mel,Solls};
 char key = keypad.getKey(); // 눌려진 키 값 읽어오기
 if(key)
 {
   switch(key)    // 기존 switch(n)을 key로 바로 넣는 활용 (문자형)
   { 
    case '1':
    tone(BUZ, music[0]);
    delay(150);noTone(11);
    break;
    
    case '2': 
    tone(BUZ, music[1]);
    delay(150);noTone(11);
    break;

    case '3': 
    tone(BUZ, music[2]);
    delay(150);noTone(11);
    break;

    case 'A': 
    tone(BUZ, music[3]);
    delay(150);noTone(11);
    break;

    case '4': 
    tone(BUZ, music[4]);
    delay(150);noTone(11);
    break;

    case '5': 
    tone(BUZ, music[5]);
    delay(150);noTone(11);
    break;

    case '6': 
    tone(BUZ, music[6]);
    delay(150);noTone(11);
    break;

    case 'B': 
    tone(BUZ, music[7]);
    delay(150);noTone(11);
    break;

    case '7': 
    tone(BUZ, music[8]);
    delay(150);noTone(11);
    break;

    case '8': 
    tone(BUZ, music[9]);
    delay(150);noTone(11);
    break;

    case '9':
    tone(BUZ, music[10]);
    delay(150);noTone(11);
    break;

    case 'C':
    tone(BUZ, music[11]);
    delay(150);noTone(11);
    break;

    case '*':
    tone(BUZ, music[12]);
    delay(150);noTone(11);
    break;

    case '0':
    tone(BUZ, music[13]);
    delay(150);noTone(11);
    break;

    case '#':
    tone(BUZ, music[14]);
    delay(150);noTone(11);
    break;

    case 'D':
    tone(BUZ, music[15]);
    delay(150);noTone(11);
    break;

    default:
    noTone(11);
    break;
  }
}
} 

/* 기존 방식 - 
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

    default:
    digitalWrite(ledA, LOW);
    digitalWrite(ledB, LOW);
    digitalWrite(ledC, LOW);
    digitalWrite(ledD, LOW);
    digitalWrite(ledE, LOW);
    digitalWrite(ledF, LOW);
    digitalWrite(ledG, LOW);
    digitalWrite(DOT, LOW);
    break;
  }
} */
