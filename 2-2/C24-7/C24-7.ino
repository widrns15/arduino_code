#include<arduino.h>

#define f_4 349
#define g_4 392
#define a_4 440

#define l_4 800
#define l_8 400
#define l_8p 600
#define l_16 200


void setup() {
  int melody[]={a_4,g_4,f_4,g_4,a_4,a_4,a_4,g_4,g_4,g_4,a_4,a_4,a_4};
  int length[]={l_8p,l_16,l_8,l_8,l_8,l_8,l_4,l_8,l_8,l_4,l_8,l_8,l_4};
  
  pinMode(3,OUTPUT);

  for(int i=0; i<13; i++)
  {
    tone(3, melody[i]); delay(length[i]);
   
  }
}

void loop() {

 
}
