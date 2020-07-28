#include <Servo.h>
#include <SimpleDHT.h>
#define MAX_DISTANCE 300
Servo myservo;  // create servo object to control a servo
int pos = 90,s = 0; 
 const int trigPin = 12;
const int echoPin = 8;
const int in1 = 4;
const int in2 = 6;
const int in3 = 3;
const int in4 = 5;
 int in5 = 7;//buzzer
long duration, distance ,distance1 ,distance2;
int naba();
String readdata;
void self();
void setup() {
  Serial.begin(9600);
  myservo.attach(9); 
  myservo.write(90);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(in5,OUTPUT);
  pinMode (in1, OUTPUT);
  pinMode (in2, OUTPUT);
  pinMode (in3, OUTPUT);
  pinMode (in4, OUTPUT);
      
}

void loop() {
  if (Serial.available())
     readdata="";
   while (Serial.available()){ 
    //Check if there is an available byte to read
delay(10); //Delay added to make thing stable
  char c = Serial.read(); //Conduct a serial read
readdata = c; //build the string- "forward", "reverse", "left" and "right"
  } 
if (readdata.length() > 0) {
Serial.println(readdata);
if(readdata == "A") //automode
 { distance=naba();
 self();
  delay(50);
}
else if (readdata == "s")//stop
 {
digitalWrite (in1, LOW);
digitalWrite (in2, LOW);
digitalWrite (in3, LOW);
digitalWrite (in4, LOW);
digitalWrite(in5,HIGH);
delay(100);
digitalWrite(in5,LOW);

delay (50);
 }
else if(readdata == "f") //forward
  {
digitalWrite(3, HIGH);
digitalWrite (4, HIGH);
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(7,HIGH);
delay(100);
digitalWrite(7,LOW);

delay(50);
  }
  // if data received as reverse move robot reverse

else if(readdata == "b")//backward
  {
digitalWrite(3, LOW);
digitalWrite(4, LOW);
digitalWrite(5, HIGH);
digitalWrite(6,HIGH);
digitalWrite(7,HIGH);
delay(50);
digitalWrite(7,LOW);

delay(50);
  }

else if (readdata == "r")//right
  {
digitalWrite (3,HIGH);
digitalWrite (4,LOW);
digitalWrite (5,LOW);
digitalWrite (6,HIGH);
digitalWrite(7,HIGH);
delay(50);
digitalWrite(7,LOW);

delay (50);

  }
else if ( readdata == "l")//left
 {
digitalWrite (3, LOW);
digitalWrite (4, HIGH);
digitalWrite (5, HIGH);
digitalWrite (6, LOW);
digitalWrite(7,HIGH);
delay(50);
digitalWrite(7,LOW);

delay (50);
 }


 else if(readdata=="g")//backward right
    {
    digitalWrite (3,LOW);
    digitalWrite (4,LOW);
    digitalWrite (5,HIGH);
    digitalWrite (6,LOW);
    digitalWrite(7,HIGH);
delay(50);
digitalWrite(7,LOW);

    delay (50);
    }
    else if(readdata=="e")//backward left
   {
    digitalWrite (3,LOW);
    digitalWrite (4,LOW);
    digitalWrite (5,LOW);
    digitalWrite (6,HIGH);
    digitalWrite(7,HIGH);
delay(50);
digitalWrite(7,LOW);

    delay (50);
   }
}
 if(readdata!="A")
   readdata="";
 }
 void self()
 {
  Serial.print(distance);
   if(distance<25)
    {
      digitalWrite(in1, LOW); 
      digitalWrite(in2, LOW); 
      digitalWrite(in3, LOW); 
      digitalWrite(in4, LOW);
      digitalWrite(in5,HIGH);
      delay(400);
      digitalWrite(in1,LOW);
      digitalWrite(in2,HIGH);
      digitalWrite(in3,LOW);
      digitalWrite(in4,HIGH);
      digitalWrite(in5,HIGH);
      delay(100);
      digitalWrite(in1, LOW); 
      digitalWrite(in2, LOW); 
      digitalWrite(in3, LOW); 
      digitalWrite(in4, LOW);
      digitalWrite(in5,LOW);
      delay(200);
     
  for(pos=90;pos>=0;pos-=5)
  {
        myservo.write(pos);
        delay(5);
  }
      delay(200);
      distance2=naba();
      delay(200);
   for(pos=0;pos<=180;pos+=5)
   { myservo.write(pos);
   delay(5);
   }
   delay(200);
       distance1=naba();
       delay(300);
   for(pos=180;pos>=90;pos-=5) 
   {myservo.write(pos);
   delay(5);
   } 

 if(distance1>distance2)
 {
   digitalWrite(in1,LOW);
      digitalWrite(in2,HIGH);
      digitalWrite(in3,LOW);
      digitalWrite(in4,HIGH);
      digitalWrite(in5,HIGH);
      delay(400);
   
      digitalWrite(in1,HIGH);
      digitalWrite(in2,LOW);
      digitalWrite(in3,LOW);
      digitalWrite(in4,HIGH);
      digitalWrite(in5,HIGH);
      delay(400);
      
 }
 else if(distance2>distance1)
 {
   
     digitalWrite(in1,LOW);
      digitalWrite(in2,HIGH);
      digitalWrite(in3,LOW);
      digitalWrite(in4,HIGH);
      digitalWrite(in5,HIGH);
      delay(400);
      digitalWrite(in1,LOW);
      digitalWrite(in2,HIGH);
      digitalWrite(in3,HIGH);
      digitalWrite(in4,LOW);
      digitalWrite(in5,HIGH);
      delay(400);
}

    }
    else
    {
    digitalWrite(in1, HIGH); 
      digitalWrite(in2, LOW); 
      digitalWrite(in3, HIGH); 
      digitalWrite(in4, LOW);
      digitalWrite(in5,LOW);
      delay(0);
}
distance= naba();
 }
 int naba()
{
   digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);  
  duration = pulseIn(echoPin, HIGH);
  distance = duration/58.2;
  if(distance>MAX_DISTANCE)
  distance=MAX_DISTANCE;
  return(distance);
  delay(100);
}//temperature and smoke sensor code is ready but circuit is yet to come.
