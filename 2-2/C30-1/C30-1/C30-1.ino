int inputdata = 0;

void setup() {
  Serial.begin(9600);

}

void loop() {
  if(Serial.available()>0){
    inputdata=Serial.read(); // ASCII Code로 읽어 옴
    Serial.print("I received: ");
    Serial.println(inputdata, DEC); // 10진 ASCII Code로 출력
  }

}
