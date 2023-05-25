char string[30];    // 문자열 배열의 선언

void setup() {
  Serial.begin(9600);
  Serial.println("String Input Program");
}

void loop() {
  if(Serial.readBytesUntil('.',string,30)){
    Serial.print("Input String: ");
    Serial.println(string);
    for(int i=0;i<30;i++) string[i]=0; // 배열의 초기화
  }
}
