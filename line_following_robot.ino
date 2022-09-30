/*
Developer: Karthik
Purpose:   To make a robot follow a white/black line based upon 
           the data coming from two attached IR sensors
*/

//left motor
const int leftPin1  = 5;  //pin on the H-Bridge

const int leftPin2  = 6;  //pin on the H-Bridge

//right motor
const int rightPin1  = 10; //pin on the H-Bridge

const int rightPin2  = 9;  //pin on the H-Bridge

//name for sensor pins
int irL = 2;
int irR = 3;

//name for possible sensor values
int line = 1;
int noLine = 0;

void setup() 
{
  //initiating signal communication
  Serial.begin(9600);
  
  //initiating sensor pins
  pinMode(irR, INPUT);
  pinMode(irL, INPUT);
  
  //initiating motor pins
  pinMode(leftPin1, OUTPUT);
  pinMode(leftPin2, OUTPUT);
  pinMode(rightPin1, OUTPUT);
  pinMode(rightPin2, OUTPUT);
}

//function to control the movement of the robot
void Move(char dir, char axis)
{

  if(dir=='right' && axis=='wheel')
  {
    digitalWrite(leftPin1, HIGH);
    digitalWrite(leftPin2, LOW);
    digitalWrite(rightPin1, LOW);
    digitalWrite(rightPin2, LOW);
  }
  else if(dir=='left' && axis=='wheel')
  {
    digitalWrite(leftPin1, LOW);
    digitalWrite(leftPin2, LOW);
    digitalWrite(rightPin1, HIGH);
    digitalWrite(rightPin2, LOW);
  }
  else if(dir=='right' && axis=='center')
  {
    digitalWrite(leftPin1, HIGH);
    digitalWrite(leftPin2, LOW);
    digitalWrite(rightPin1, LOW);
    digitalWrite(rightPin2, HIGH);
  }
  else if(dir=='left' && axis=='center')
  {
    digitalWrite(leftPin1, LOW);
    digitalWrite(leftPin2, HIGH);
    digitalWrite(rightPin1, HIGH);
    digitalWrite(rightPin2, LOW);
  }
  else if(dir=='forwad' && axis=='none')
  {
    digitalWrite(leftPin1, HIGH);
    digitalWrite(leftPin2, LOW);
    digitalWrite(rightPin1, HIGH);
    digitalWrite(rightPin2, LOW);
  }
  else if(dir=='Stop' && axis=='none')
  {
    digitalWrite(leftPin1, HIGH);
    digitalWrite(leftPin2, HIGH);
    digitalWrite(rightPin1, HIGH);
    digitalWrite(rightPin2, HIGH);
  }
}

void loop() 
{
  
  //variabes to store data from the sensors
  int lVal = digitalRead(irL);
  int rVal = digitalRead(irR);
  
 //print sensor data on the serial monitor
  Serial.println("Left sensor: ");
  Serial.println(irL);
  Serial.println("\t");
  Serial.println("right sensor: ");
  Serial.println(irR);
  delay(100);
  
  //condition for motor control based upon
  //data coming from the sensors

  //if neither sensor detects line
  if(lVal==noLine && rVal==noLine)
  {
    Move('forwad', 'none');
  }
  
  //if left sensor detects line
  else if(lVal==line && rVal==noLine)
  {
    Move('right', 'wheel');
  }
  
  //if right sensor detects line
  else if(lVal==noLine && rVal==line)
  {
    Move('left', 'wheel');
  }
  
  //to prevent abnormal behaviour of the robot
  else
  {
    Move('stop', 'wheel');
  }
//loop starts agin...
}
