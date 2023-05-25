#define IN1 22
#define IN2 24
#define IN3 26
#define IN4 28

int Steps = 0;
int steps_left=4095;  //현재 이동 할 Steps 값 저장

// 회전방향, true =정방향, false=역방향
boolean Direction = true;

unsigned long last_time;  // 이전 회전시의 시간 저장

unsigned long currentMillis;  // 현재 시간 저장

long time;  // 1바퀴 회전에 소요된 시간

void setup(){
  Serial.begin(9600);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
}

void loop(){
  while(steps_left>0)
  {
    currentMillis = micros();
    if(currentMillis-last_time>=1000)
    {
      stepper(1);
      time=time+micros()-last_time;
      last_time=micros();
      steps_left--;
    }
  }

  Serial.println(Steps);  // 정회전시 0출력, 역회전시 7 출력
  Serial.println("Wait...!");
  delay(2000);

  Direction=!Direction; //회전 방향 초기화
  steps_left=4095;
}

//Step motor step당 4개핀 제어 신호 출력 값 지정

void stepper(int xw)
{
  for(int x=0;x<xw;x++)
  {
    switch(Steps)
    {
      case 0: runStep(LOW, LOW, LOW, HIGH); break;
      case 1: runStep(LOW, LOW, HIGH, HIGH); break;
      case 2: runStep(LOW, LOW, HIGH, LOW); break;
      case 3: runStep(LOW, HIGH, HIGH, LOW); break;
      case 4: runStep(LOW, HIGH, LOW, LOW); break;
      case 5: runStep(HIGH, HIGH, LOW, LOW); break;
      case 6: runStep(HIGH, LOW, LOW, LOW); break;
      case 7: runStep(HIGH, LOW, LOW, HIGH); break;
      default: runStep(LOW, LOW, LOW, LOW); break;
    }
    SetDirection();
  }
}

// 4개핀 제어 신호 출력
void runStep(int value1,int value2,int value3,int value4)
{
  digitalWrite(IN1,value1);
  digitalWrite(IN2,value2);
  digitalWrite(IN3,value3);
  digitalWrite(IN4,value4);
}

// 방향 전환 및 스텝 변수 초기화
void SetDirection()
{
  if(Direction==1) { Steps++;}
  if(Direction==0) { Steps--;}
  if(Steps>7) {Steps=0;}
  if(Steps<0) {Steps=7;}
}
