// if > else if(한 줄 괄호 생략) > switch > 기존 switch 발전 

#include <Keypad.h>
int led1=10;
int led2=11;
int led3=12;
int led4=13;
char key;

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
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  
 char key = keypad.getKey(); // 눌려진 키 값 읽어오기
 if(key)
 { // 입력된 키가 있으면 시리얼 모니터에 키 값 출력
   Serial.println(key);
    
    digitalWrite(led1, LOW);    // 다음 키를 누를 때 초기화를 위해
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    
   switch(key)    // 기존 switch(n)을 key로 바로 넣는 활용 (문자형)
   { 
    case '1':
    digitalWrite(led1, HIGH);
    break;
    
    case '2': 
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    break;

    case '3': 
    digitalWrite(led1, HIGH);
    digitalWrite(led3, HIGH);
    break;

    case 'A': 
    digitalWrite(led1, HIGH);
    digitalWrite(led4, HIGH);
    break;

    case '4': 
    digitalWrite(led2, HIGH);
    break;

    case '5': 
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    break;

    case '6': 
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    break;

    case 'B': 
    digitalWrite(led2, HIGH);
    digitalWrite(led4, HIGH);
    break;

    case '7': 
    digitalWrite(led3, HIGH);
    break;

    case '8': 
    digitalWrite(led1, HIGH);
    digitalWrite(led3, HIGH);
    break;

    case '9':
    digitalWrite(led3, HIGH);
    digitalWrite(led2, HIGH);
    break;

    case 'C':
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    break;

    case '*':
    digitalWrite(led4, HIGH);
    break;

    case '0':
    digitalWrite(led1, HIGH);
    digitalWrite(led4, HIGH);
    break;

    case '#':
    digitalWrite(led4, HIGH);
    digitalWrite(led2, HIGH);
    break;

    case 'D':
    digitalWrite(led4, HIGH);
    digitalWrite(led3, HIGH);
    break;

    default:
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
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
