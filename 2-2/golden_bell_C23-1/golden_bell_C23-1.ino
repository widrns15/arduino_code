#define flame A1
int buzzer = 13;
int red = 3;
int green = 5;
int blue = 6;

void setup() {
  Serial.begin(9600);
  pinMode(flame,INPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);

}

void loop() {
  int flamesensor = analogRead(flame);
  Serial.print("Flame Sensor Value : ");
  Serial.println(flamesensor);
  delay(1000);


  if(flamesensor > 1000)
  {
    Color(0,0,0);
    digitalWrite(buzzer,LOW);
  }

  if(flamesensor < 1000)
  {
    digitalWrite(buzzer,HIGH);
    delay(1000);                    
    digitalWrite(buzzer,LOW);       // LOW 빼지말기.

    Color(255,0,0);
    delay(500);
    Color(0,255,0);
    delay(500);
    Color(0,0,255);
    delay(500);
  }
}

void Color(int r, int g, int b)
{
  analogWrite(red,r);
  analogWrite(green,g);
  analogWrite(blue,b);
}
