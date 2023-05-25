int red = 11;
int green = 10;
int blue = 9;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);

}

 

void loop() {
  Color(255,0,0); // Red On
  delay(1000);
  Color(0,255,0); // Green On
  delay(1000);
  Color(0,0,255); // Blue On
  delay(1000);

}

void Color(int r, int g, int b)
{
  analogWrite(red,r);
  analogWrite(green,g);
  analogWrite(blue,b);
}
