double ch2=2;  //for left motor
int a=4; int b=5;
 
double ch3=3; //for right motor
int c=6; int d=7;


void setup()
{
  Serial.begin(9600);
  
  pinMode(2,INPUT);
  pinMode(4,OUTPUT); pinMode(5,OUTPUT);
  
  pinMode(3,INPUT);
  pinMode(6,OUTPUT); pinMode(7,OUTPUT);
  
}

void loop()
{
ch2 = pulseIn(2,HIGH);
ch3 = pulseIn(3,HIGH);

if((ch2==0)&&(ch3==0)) //NO output
{     
 digitalWrite(a,LOW); digitalWrite(b,LOW);
 digitalWrite(c,LOW);digitalWrite(d,LOW);
}

else if((ch2>1530)&&(ch3>1530)) // FORWARD
{     
digitalWrite(a,HIGH); digitalWrite(b,LOW);
 digitalWrite(c,LOW);digitalWrite(d,HIGH);    
}

else if((ch2>1530)&&(ch3<1460)) //RIGHT
{ 
   digitalWrite(a,HIGH); digitalWrite(b,LOW);
 digitalWrite(c,HIGH);digitalWrite(d,LOW);    

}

else if((ch2<1460)&&(ch3>1530)) //LEFT
{     
  digitalWrite(a,LOW); digitalWrite(b,HIGH);
 digitalWrite(c,LOW);digitalWrite(d,HIGH);
}

else if((ch2<1460)&&(ch3<1460)) // BACKWARD
{  digitalWrite(a,LOW); digitalWrite(b,HIGH);
 digitalWrite(c,HIGH);digitalWrite(d,LOW);
 
}

else if((ch2>1530)&&(ch3==0)) //ONLY LEFT WHEEL FORWARD
{
  digitalWrite(a, HIGH); digitalWrite(b, LOW);
  digitalWrite(c, LOW);digitalWrite(d, LOW);
}

else if((ch2<1460)&&(ch3==0)) //ONLY LEFT WHEEL BACKWARD
{
  digitalWrite(a, LOW); digitalWrite(b, HIGH);
  digitalWrite(c, LOW);digitalWrite(d, LOW);
}

else if((ch2==0)&&(ch3>1530)) //ONLY RIGHT WHEEL FORWARD
{
  digitalWrite(a, LOW); digitalWrite(b, LOW);
  digitalWrite(c, LOW);digitalWrite(d, HIGH);
}

else if((ch2==0)&&(ch3<1460)) //ONLY RIGHT WHEEL BACKWARD
{
  digitalWrite(a, LOW); digitalWrite(b, LOW);
  digitalWrite(c, HIGH);digitalWrite(d, LOW);
}

}
