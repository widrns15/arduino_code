int pin[17]={-1,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37};

int col[8]={pin[9],pin[10],pin[11],pin[12],pin[13],pin[14],pin[15],pin[16]};

int row[8]={pin[1],pin[2],pin[3],pin[4],pin[5],pin[6],pin[7],pin[8]};

void setup() {
  for(int i=1; i<=16; i++)
  pinMode(pin[i], OUTPUT);
}

void loop() { 

  digitalWrite(row[0],LOW);
  for(int i=1; i<8; i++)
  digitalWrite(row[i],HIGH);
  for(int k=0; k<8; k++)
  digitalWrite(col[k],HIGH);
}
