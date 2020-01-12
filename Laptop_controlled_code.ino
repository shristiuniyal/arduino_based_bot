#include <Servo.h>


int motorL[]={3,2};  
int motorR[]={5,4};
int movement;
int flag=0;
int angle;
Servo upDownServo;
Servo clawServo;

void setup() 
{
  Serial.begin(9600);
  upDownServo.attach(9);
  clawServo.attach(10); 
  pinMode(motorL[0],OUTPUT);
  pinMode(motorL[1],OUTPUT);
  pinMode(motorR[0],OUTPUT);
  pinMode(motorR[1],OUTPUT); 
  Serial.println("How to use:-\nW-Forward \tS-Backwards\tA-Left\tD-Right\tQ-Arm Up\tZ-Arm Down\tE-Claw Open\tC-Claw Close");
}   



void loop() 
{   
    
     if (Serial.available())

      {      movement= Serial.read();
      
            if(movement== int('W')||movement==int('w'))
               flag=1;
             
            else if(movement== int('A')||movement==int('a'))
               flag=2;
            
            else if(movement== int('D')||movement==int('d'))
               flag=3;
            
            else if(movement== int('S')||movement==int('s'))
               bck();
            else if(movement== int('Q')||movement==int('q'))
               up();
            else if(movement== int('Z')||movement==int('z'))
               down();
            else if(movement== int('E')||movement==int('E'))
               clawOpen();
            else if(movement== int('C')||movement==int('C'))
               clawClose();
            else
               nomove();
      }
}  

    



void fwd()

{ 
  Serial.println("Moving Forward");
  digitalWrite(motorR[0],HIGH);
  digitalWrite(motorR[1],LOW);
  digitalWrite(motorL[0],HIGH);
  digitalWrite(motorL[1],LOW);

}
void bck()
{ 
  Serial.println("Moving Backward");
  digitalWrite(motorR[0],LOW);
  digitalWrite(motorR[1],HIGH);
  digitalWrite(motorL[0],LOW);
  digitalWrite(motorL[1],HIGH);

}
void right()
{
  Serial.println("Moving Right");
  digitalWrite(motorR[0],HIGH);
  digitalWrite(motorR[1],LOW);
  digitalWrite(motorL[0],LOW);
  digitalWrite(motorL[1],HIGH);

}

void left()
{
  Serial.println("Moving left");
  digitalWrite(motorR[0],LOW);
  digitalWrite(motorR[1],HIGH);
  digitalWrite(motorL[0],HIGH);
  digitalWrite(motorL[1],LOW);

}

void up(){
  Serial.println("Moving arm up");
  upDownServo.write(120);
}

void down(){
  Serial.println("Moving arm down");
  upDownServo.write(180);
}

void clawClose(){
  Serial.println("Closing the claw");
  clawServo.write(90);
}

void clawOpen(){
  Serial.println("Open the claw");
  clawServo.write(30);
}

void nomove()
{
  digitalWrite(motorR[0],LOW);
  digitalWrite(motorR[1],LOW);
  digitalWrite(motorL[0],LOW);
  digitalWrite(motorL[1],LOW);
}
