int pin[17]={-1,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37};

int col[8]={pin[9],pin[10],pin[11],pin[12],pin[13],pin[14],pin[15],pin[16]};

int row[8]={pin[1],pin[2],pin[3],pin[4],pin[5],pin[6],pin[7],pin[8]};

void setup() {
  for(int i=1; i<=16; i++)
  pinMode(pin[i], OUTPUT);
}

void loop() { 
  for(int j=0; j<8; j++)
  {
    for(int k=0; k<8; k++)
    {
      dot_led(7-j,7-k);
      delay(500);
    }
  }
}

void dot_led(int row_led, int col_led){
  for(int m=0; m<8; m++){
    digitalWrite(row[m],HIGH);
    digitalWrite(col[m],LOW);
  }
  digitalWrite(row[row_led],LOW);
  digitalWrite(col[col_led],HIGH);
}
