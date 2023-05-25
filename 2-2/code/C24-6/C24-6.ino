#define c_4 261
#define d_4 293
#define e_4 329
#define f_4 349
#define g_4 392
#define a_4 440
#define b_4 493
#define c_5 523

void setup() {
  pinMode(3,OUTPUT);
}

void loop() {

 tone(3,c_4); delay(800);
 tone(3,d_4); delay(800);
 tone(3,e_4); delay(800);
 tone(3,f_4); delay(800);
 tone(3,g_4); delay(800);
 tone(3,a_4); delay(800);
 tone(3,b_4); delay(800);
 tone(3,c_5); delay(800);
 
}
