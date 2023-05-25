int i = 0;
int j = 0;
int k = 0;

void setup() {
  Serial.begin(9600);
  Serial.print("i, j =");
}

void loop() {
  while(Serial.available() > 0){
    i = Serial.parseInt();
    j = Serial.parseInt();

    Serial.print(i);
    Serial.print(",");
    Serial.print(j);
    Serial.print("\n");

    k = i + j;
    Serial.print("i + j = ");
    Serial.println(k);

    k = i - j;
    Serial.print("i - j = ");
    Serial.println(k);

    Serial.print("i, j = ");  // 다시 입력 받음 대기
  }
}
