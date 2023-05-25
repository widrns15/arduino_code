int POTEN_PIN = A0;
int LED_PIN1 = 3;
int LED_PIN2 = 5;


void setup() {
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
Serial.begin(9600);

}
 

void loop() {

int readVal= analogRead(POTEN_PIN);
readVal = map(readVal, 0, 1023, 0, 255);


analogWrite(LED_PIN1,readVal); //0~255~0 256
analogWrite(LED_PIN2,255-readVal); // 255~0~255
Serial.println(readVal);
delay(1000);
}

/*int out= readVal ;

if(readVal>127.5)
{
  out=255-readVal;
}
analogWrite(LED_PIN1,out); //0~255~0 256
analogWrite(LED_PIN2,255-out); // 255~0~255
Serial.println(readVal);
delay(1000);
}
*/
