#include <QueueArray.h>
#include <Servo.h>



Servo myServo;

Servo myServo1;

Servo myServo2;

Servo myServo3;

Servo myServo4;

int timer_counter = 0;

int left = 1000;

int center = 1500;

int center2 = 1400;

int center3 = 1400;

int right = 2000;

int bags = 0;

int tagData = 0;

int counter1 = 200;
int counter2 = 200;
int counter3 = 200;
int counter4 = 200;
int start =0;

int Belt_ACE_Counter1=0;
int Belt_ACE_Counter2=0;
int Belt_ACE_Counter3=0;
int Belt_ACE_Counter4=0;

QueueArray<int> motor1;
QueueArray<int> motor2;
QueueArray<int> motor3;

void setup()
{
  //Serial.print(Serial.available());
  Serial.print(Serial);
  Serial.begin(9600);
  Serial.print(Serial); 

 cli();//stop interrupts

//set timer2 interrupt at 8kHz
  TCCR2A = 0;// set entire TCCR2A register to 0
  TCCR2B = 0;// same for TCCR2B
  TCNT2  = 0;//initialize counter value to 0
  // set compare match register for 8khz increments
  OCR2A = 249;// = (16*10^6) / (8000*8) - 1 (must be <256)
  // turn on CTC mode
  TCCR2A |= (1 << WGM21);
  // Set CS21 bit for 8 prescaler
  TCCR2B |= (1 << CS21);   
  // enable timer compare interrupt
  TIMSK2 |= (1 << OCIE2A);

sei();//allow interrupts

 
  
 

 pinMode(9, OUTPUT); // Redirectional Motor #2

 pinMode(10, OUTPUT); // Redirectional Motor #1

 pinMode(11, OUTPUT); // Redirectional Motor #0

 pinMode(5, OUTPUT); // Redirectional Motor #1

 pinMode(6, OUTPUT); // Redirectional Motor #0
 
 digitalWrite(7,HIGH);

 digitalWrite(12,HIGH);
 
 //3rd Motor
 myServo.attach(11);
 myServo.writeMicroseconds(center);

 //2nd Motor
 myServo1.attach(10);
 myServo1.writeMicroseconds(center);

 //1st Motor
 myServo2.attach(9);
 myServo2.writeMicroseconds(center); 

 myServo3.attach(3);
 myServo3.writeMicroseconds(center);

 myServo4.attach(6);
 myServo4.writeMicroseconds(center); 

}

ISR(TIMER2_COMPA_vect){//timer1 interrupt 1Hz toggles pin 13 (LED)
//generates pulse wave of frequency 1Hz/2 = 0.5kHz (takes two cycles for full wave- toggle high then toggle low)
  timer_counter++;
  if(timer_counter == 800){
    OneSecTimer();
    timer_counter = 0;
  }
}

void OneSecTimer()
{
  if (bags != 0){
    
    //----------------START OF 1ST COUNTER---------------
    if(counter1 == 10)
    {
      myServo.writeMicroseconds(motor1.front());
      motor1.dequeue();
      counter1++;
    }
    else if(counter1 == 25)
    {
      myServo.writeMicroseconds(center);
      counter1++;
    }
    else if(counter1 == 35 && Belt_ACE_Counter1 == 0)
    {
      myServo1.writeMicroseconds(motor2.front());
      motor2.dequeue();
      counter1++;
      
    }
    else if(counter1 == 50 && Belt_ACE_Counter1 == 1)
    {
      myServo1.writeMicroseconds(motor2.front());
      motor2.dequeue();
      counter1++;
       
    }
    else if(counter1 == 60 && Belt_ACE_Counter1 == 0)
    {
      myServo1.writeMicroseconds(center);
      counter1++;
    }
     else if(counter1 == 75 && Belt_ACE_Counter1 == 1)
    {
      myServo1.writeMicroseconds(center);
      counter1++;
    }
    else if(counter1 == 45 && Belt_ACE_Counter1 == 0)
    {
      myServo2.writeMicroseconds(motor3.front());
      motor3.dequeue();
      counter1++;
    }
    else if(counter1 == 55 && Belt_ACE_Counter1 == 1)
    {
      myServo2.writeMicroseconds(motor3.front());
      motor3.dequeue();
      counter1++;
    }
    else if(counter1 == 70 && Belt_ACE_Counter1 == 0)
    {
      myServo2.writeMicroseconds(center);
      counter1 = 200;
      bags--;
    }
    else if(counter1 == 80 && Belt_ACE_Counter1 == 1)
    {
      myServo2.writeMicroseconds(center);
      counter1 = 200;
      bags--;
      Belt_ACE_Counter1 = 0;
    }
    else if(counter1 != 200)
    {
     counter1++; 
    }
    //----------------END OF 1ST COUNTER---------------
    
    //----------------START OF 2ND COUNTER---------------
    if(counter2 == 10)
    {
      myServo.writeMicroseconds(motor1.front());
      motor1.dequeue();
      counter2++;
    }
    else if(counter2 == 25)
    {
      myServo.writeMicroseconds(center);
      counter2++;
    }
    else if(counter2 == 35 && Belt_ACE_Counter2 == 0)
    {
      myServo1.writeMicroseconds(motor2.front());
      motor2.dequeue();
      counter2++;
    }
    else if(counter2 == 50 && Belt_ACE_Counter2 == 1)
    {
      myServo1.writeMicroseconds(motor2.front());
      motor2.dequeue();
      counter2++;
    }
    else if(counter2 == 60 && Belt_ACE_Counter2 == 0)
    {
      myServo1.writeMicroseconds(center);
      counter2++;
    }
     else if(counter2 == 75 && Belt_ACE_Counter2 == 1)
    {
      myServo1.writeMicroseconds(center);
      counter2++;
    }
    else if(counter2 == 45 && Belt_ACE_Counter2 == 0)
    {
      myServo2.writeMicroseconds(motor3.front());
      motor3.dequeue();
      counter2++;
    }
    else if(counter2 == 55 && Belt_ACE_Counter2 == 1)
    {
      myServo2.writeMicroseconds(motor3.front());
      motor3.dequeue();
      counter2++;
    }
    else if(counter2 == 70 && Belt_ACE_Counter2 == 0)
    {
      myServo2.writeMicroseconds(center);
      counter2 = 200;
      bags--;
    }
    else if(counter2 == 80 && Belt_ACE_Counter2 == 1)
    {
      myServo2.writeMicroseconds(center);
      counter2 = 200;
      bags--;
      Belt_ACE_Counter2 = 0;
    }
    else if(counter2 != 200)
    {
     counter2++; 
    }
    //----------------END OF 2ND COUNTER---------------
              
    
    //----------------START OF 3RD COUNTER---------------    
    if(counter3 == 10)
    {
      myServo.writeMicroseconds(motor1.front());
      motor1.dequeue();
      counter3++;
    }
    else if(counter3 == 25)
    {
      myServo.writeMicroseconds(center);
      counter3++;
    }
    else if(counter3 == 35 && Belt_ACE_Counter3 == 0)
    {
      myServo1.writeMicroseconds(motor2.front());
      motor2.dequeue();
      counter3++;
    }
    else if(counter3 == 50 && Belt_ACE_Counter3 == 1)
    {
      myServo1.writeMicroseconds(motor2.front());
      motor2.dequeue();
      counter3++;
    }
    else if(counter3 == 60 && Belt_ACE_Counter3 == 0)
    {
      myServo1.writeMicroseconds(center);
      counter3++;
    }
     else if(counter3 == 75 && Belt_ACE_Counter3 == 1)
    {
      myServo1.writeMicroseconds(center);
      counter3++;
    }
    else if(counter3 == 45 && Belt_ACE_Counter3 == 0)
    {
      myServo2.writeMicroseconds(motor3.front());
      motor3.dequeue();
      counter3++;
    }
    else if(counter3 == 55 && Belt_ACE_Counter3 == 1)
    {
      myServo2.writeMicroseconds(motor3.front());
      motor3.dequeue();
      counter3++;
    }
    else if(counter3 == 70 && Belt_ACE_Counter3 == 0)
    {
      myServo2.writeMicroseconds(center);
      counter3 = 200;
      bags--;
    }
    else if(counter3 == 80 && Belt_ACE_Counter3 == 1)
    {
      myServo2.writeMicroseconds(center);
      counter3 = 200;
      bags--;
      Belt_ACE_Counter3 = 0;
    }
    else if(counter3 != 200)
    {
     counter3++; 
    }
    //----------------END OF 3RD COUNTER---------------
    
    
    //----------------START OF 4TH COUNTER---------------    
    if(counter4 == 10)
    {
      myServo.writeMicroseconds(motor1.front());
      motor1.dequeue();
      counter4++;
    }
    else if(counter4 == 25)
    {
      myServo.writeMicroseconds(center);
      counter4++;
    }
    else if(counter4 == 35 && Belt_ACE_Counter4 == 0)
    {
      myServo1.writeMicroseconds(motor2.front());
      motor2.dequeue();
      counter4++;
    }
    else if(counter4 == 50 && Belt_ACE_Counter4 == 1)
    {
      myServo1.writeMicroseconds(motor2.front());
      motor2.dequeue();
      counter4++;
    }
    else if(counter4 == 60 && Belt_ACE_Counter4 == 0)
    {
      myServo1.writeMicroseconds(center);
      counter4++;
    }
     else if(counter4 == 75 && Belt_ACE_Counter4 == 1)
    {
      myServo1.writeMicroseconds(center);
      counter4++;
    }
    else if(counter4 == 45 && Belt_ACE_Counter4 == 0)
    {
      myServo2.writeMicroseconds(motor3.front());
      motor3.dequeue();
      counter4++;
    }
    else if(counter4 == 55 && Belt_ACE_Counter4 == 1)
    {
      myServo2.writeMicroseconds(motor3.front());
      motor3.dequeue();
      counter4++;
    }
    else if(counter4 == 70 && Belt_ACE_Counter4 == 0)
    {
      myServo2.writeMicroseconds(center);
      counter4 = 200;
      bags--;
    }
    else if(counter4 == 80 && Belt_ACE_Counter4 == 1)
    {
      myServo2.writeMicroseconds(center);
      counter4 = 200;
      bags--;
      Belt_ACE_Counter4 = 0;
    }
    else if(counter4 != 200)
    {
     counter4++; 
    }
    //----------------END OF 4TH COUNTER---------------
    
    
  }
}


void SetCounter(int Belt_ACE)
{
       
	if (counter1 == 200)
	{
            if(Belt_ACE==1)
            {
              Belt_ACE_Counter1=1;
              counter1 = 0;
              
	      return;
            }
            else
            {
              Belt_ACE_Counter1=0;
	      counter1 = 0;
              
	      return;
            }
	}

	else if (counter2 == 200)
	{
	    if(Belt_ACE==1)
            {
              Belt_ACE_Counter2=1;
              counter2 = 0;
	      return;
            }
            else
            {
              Belt_ACE_Counter2=0;
	      counter2 = 0;
	      return;
            }
	}

	else if (counter3 == 200)
	{
	    if(Belt_ACE==1)
            {
              Belt_ACE_Counter3=1;
              counter3 = 0;
	      return;
            }
            else
            {
              Belt_ACE_Counter3=0;
	      counter3 = 0;
	      return;
            }
	}

	else if (counter4 == 200)
	{
	    if(Belt_ACE==1)
            {
              Belt_ACE_Counter4=1;
              counter4 = 0;
	      return;
            }
            else
            {
              Belt_ACE_Counter4=0;
	      counter4 = 0;
	      return;
            }
	}
      
}

void loop()
{
  //Serial.write(Serial);
 if(Serial == 0)
   {
     myServo3.writeMicroseconds(center);
     myServo4.writeMicroseconds(center);
   }
 
 if(Serial.available() == 1)
 {
   
   tagData = Serial.read();
   
   
   switch (tagData)

   {
     case '1':
       
       myServo3.writeMicroseconds(left);
       myServo4.writeMicroseconds(left); 
       
       break;
     
     case 'x':
       
       myServo3.writeMicroseconds(center);
       myServo4.writeMicroseconds(center);
       
       break;
       
     case 'X':
       
       myServo3.writeMicroseconds(center);
       myServo4.writeMicroseconds(center); 
       
       break;
       
     case 'A': 
        
        motor1.enqueue(center);
        motor2.enqueue(center);
        motor3.enqueue(center);
        
        bags++;              
        SetCounter(1);
        
                
        break;

     case 'B':         
        
        motor1.enqueue(right);
        motor2.enqueue(center);
        motor3.enqueue(center);
        
        bags++;              
        SetCounter(0); 
        
        
        break;   //Move on       

     case 'C':         
        
        motor1.enqueue(center);
        motor2.enqueue(center);
        motor3.enqueue(left-25);
        //motor3.enqueue(1000);
        
        bags++;
        SetCounter(1); 
     
        
        break;   //Move on       

     case 'D':         
        
        motor1.enqueue(right);
        motor2.enqueue(center);
        motor3.enqueue(right+30);
                      
        bags++;
        SetCounter(0);
        
        
        break;       

     case 'E':           
        
        motor1.enqueue(center);
        motor2.enqueue(left);
        motor3.enqueue(center);
                      
        bags++;
        SetCounter(1);
        
        
        break;   //Move on     

     case 'F':        
        
        motor1.enqueue(right);
        motor2.enqueue(right);
        motor3.enqueue(center);
                      
        bags++;
        SetCounter(0);
        
        
        break; 
   }  
 }
 

}
