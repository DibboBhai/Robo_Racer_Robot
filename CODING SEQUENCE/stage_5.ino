int ch2;  //for left motor
int enA = 5;
int a=4; int b=6; 
int X;
 
int ch3; //for right motor
int enB = 9;
int c=8; int d=10; 
int Y;


void setup()
{
  Serial.begin(9600);
 
  pinMode(2,INPUT);
  pinMode(enA, OUTPUT);
  pinMode(a,OUTPUT); pinMode(b,OUTPUT);
 
  pinMode(3,INPUT);
  pinMode(enB, OUTPUT);
  pinMode(c,OUTPUT); pinMode(d,OUTPUT);
 
}

void loop() {
  ch3 = map(pulseIn(2,HIGH), 1200, 1700, -254, 254);
  ch2 = map(pulseIn(3,HIGH), 1200, 1800, -254, 254);

  if(ch2>254){
    ch2=254;
    }
  if(ch3>254){
    ch3=254;
    }
  if(ch2< -254){
    ch2=-254;
    }
  if(ch3< -254){
    ch3=-254;
    }

  // Serial.println(pulseIn(3, HIGH));
  // Serial.println(ch2);

  // SETTING UP THE DIRECTIONSSS

  if(ch2>0 && ch3>0){                                    //  FORWARD MOVEMENT
    digitalWrite(a, HIGH);digitalWrite(b, LOW);
    digitalWrite(c, LOW);digitalWrite(d, HIGH);
  }
  else if(ch2<0 && ch3<0){                                // BACKWARD MOTION
    digitalWrite(a, LOW);digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);digitalWrite(d, LOW);
  }

  else if(ch2>0 && ch3<0){                                // RIGHTWARD MOTION
    digitalWrite(a, HIGH);digitalWrite(b, LOW);
    digitalWrite(c, HIGH);digitalWrite(d, LOW);
  }

  else if (ch2<0 && ch3>0){                               //LEFTWARD MOTION
    digitalWrite(a, LOW);digitalWrite(b, HIGH);
    digitalWrite(c, LOW);digitalWrite(d, HIGH);
  }

  else{                                                 // STABLE
    digitalWrite(a, LOW);digitalWrite(b, LOW);
    digitalWrite(c, LOW);digitalWrite(d, LOW);    
  }
  
  // X = map(pulseIn(2,HIGH), 1200, 1700, 0, 255);  //  DEFINING THE VALUE OF X AND MAPPING IT FOR 0 TO 255__________FOR enA

  
  // if(X>255){
  //   X = 255;
  // }

  // else if(X<0){
  //   X = 0;
  // } 

  // Y = map(pulseIn(3,HIGH), 1200, 1800, 0, 255);  //  DEFINING THE VALUE OF Y AND MAPPING IT FOR 0 TO 255 ______________ for enB
 
  // if(Y>255){
  //   Y = 255;
  // }
  // else if (Y<0){
  //   Y = 0;
  // }

  analogWrite(enA , abs(ch2));
  analogWrite(enB , abs(ch3));

}