#include <Keypad.h>

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
byte colPins[COLS] = {8, 9, 10, 11}; // 행(COL) 연결 핀

// 키패드 초기화
Keypad keypad = Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS);

void setup() {
  Serial.begin(9600);
}

void loop() {
  
 char key = keypad.getKey(); // 눌려진 키 값 읽어오기
 if(key){ // 입력된 키가 있으면 시리얼 모니터에 키 값 출력
  Serial.println(key);
 }
  
}
