
int motorL[]={3,2};  
int motorR[]={5,4}; 
int VT=7;
int Q4=8;       
int Q3=9;       
int Q2=10;      
int Q1=11;      
int r1;         
int r2;
int r3;
int r4;
void setup()                                              
{   Serial.begin(9600);
    for(int i=0;i<2;i++)
    {   pinMode(motorL[i],OUTPUT);
        pinMode(motorR[i],OUTPUT);
    }
    pinMode(Q4,INPUT); 
    pinMode(Q3,INPUT);
    pinMode(Q2,INPUT);
    pinMode(Q1,INPUT);
    r1=0;
    r2=0;
    r3=0;
    r4=0;
}        
void loop()                                                                                   
{   int read[]={digitalRead(Q4),digitalRead(Q3),digitalRead(Q2),digitalRead(Q1)};                
    //r2=digitalRead(Q3);
    //r3=digitalRead(Q2);
    //r4=digitalRead(Q1);   
   
            if(read[0]==0&&read[1]==0&&read[2]==1&&read[3]==0)       
            { Serial.println("Moving Forward");
              fwd();
            }
           else if(read[0]==0&&read[1]==1&&read[2]==0&&read[3]==0)        
            { Serial.println("Moving Left");
              left();
            }
            else if(read[0]==0&&read[1]==1&&read[2]==0&&read[3]==1)      
            { Serial.println("Not moving");
              nomove();
            }
            else if(read[0]==0&&read[1]==1&&read[2]==1&&read[3]==0)    
            { Serial.println("Moving Right");
              right();
            }
            else if(read[0]==1&&read[1]==0&&read[2]==0&&read[3]==0)      
            { Serial.println("Moving Backward");
              bck();
            }
              
}              
void fwd()

{ 
  digitalWrite(motorR[0],HIGH);
  digitalWrite(motorR[1],LOW);
  digitalWrite(motorL[0],HIGH);
  digitalWrite(motorL[1],LOW);

}
void bck()
{ 
  digitalWrite(motorR[0],LOW);
  digitalWrite(motorR[1],HIGH);
  digitalWrite(motorL[0],LOW);
  digitalWrite(motorL[1],HIGH);

}
void left()
{
  digitalWrite(motorR[0],HIGH);
  digitalWrite(motorR[1],LOW);
  digitalWrite(motorL[0],LOW);
  digitalWrite(motorL[1],HIGH);

}

void right()
{
  digitalWrite(motorR[0],LOW);
  digitalWrite(motorR[1],HIGH);
  digitalWrite(motorL[0],HIGH);
  digitalWrite(motorL[1],LOW);

}

void nomove()
{
  digitalWrite(motorR[0],LOW);
  digitalWrite(motorR[1],LOW);
  digitalWrite(motorL[0],LOW);
  digitalWrite(motorL[1],LOW);
}
