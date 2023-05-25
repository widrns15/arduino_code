#define POTEN_PIN A0
#define LED_PIN 3

void setup() {
  pinMode(LED_PIN, OUTPUT);
Serial.begin(9600);

}

 

void loop() {

int POTEN_PIN= analogRead(A0)/4;
analogWrite(LED_PIN,POTEN_PIN);
Serial.println(POTEN_PIN);
delay(1000);
 
  

}
