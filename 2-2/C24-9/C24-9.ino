#define cds_pin A3
int cds_value = 0;
int old_value = 0;


void setup() {
  Serial.begin(9600);
  pinMode(cds_pin, INPUT); // cds 연결
  pinMode(11,OUTPUT); // piezzo 연결
}
void loop() {
cds_value = analogRead(cds_pin); // CDS 연결
// cds sensor 현재의 값이 전에 입력받은 센서 값에서 +- 20 범위를 벗어나면

if((cds_value < old_value-20)|| (cds_value > old_value+20))
{
    tone(11, cds_value*3);    // cds sensor 값 * 3배의 소리를 낸다.
    old_value = cds_value;    // cds sensor 현재 값으로 전의 값을 새로 고쳐서 다음번에 비교 값으로 사용함.
    Serial.println(cds_value);
    delay(500);
    }
 
}
