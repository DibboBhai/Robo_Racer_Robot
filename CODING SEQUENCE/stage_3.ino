double ch2;  //for left motor
int a=5; int b=6;
 
double ch3; //for right motor
int c=9; int d=10;


void setup()
{
  Serial.begin(9600);
 
  pinMode(2,INPUT);
  pinMode(a,OUTPUT); pinMode(b,OUTPUT);
 
  pinMode(3,INPUT);
  pinMode(c,OUTPUT); pinMode(d,OUTPUT);
 
}

void loop() {
  ch2 = map(pulseIn(2,HIGH), 1240, 1650, 0, 255);
  ch3 = map(pulseIn(3,HIGH), 1240, 1910, 0, 255);

  Serial.println(pulseIn(ch2, HIGH));

  if(ch3>255){
    ch3 = 255;
  }

  else if(ch3<0){
    ch3 = 0;
  }

  else if(ch2>255){
    ch2 = 255;
  }

  else if(ch2<0){
    ch2 = 0;
  }

  analogWrite(a, ch2); analogWrite(b,255-ch2);
  analogWrite(c, ch3); analogWrite(d, 255-ch3);
}
