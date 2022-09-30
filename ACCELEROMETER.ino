int leftmotor_p=13;     //left motor pin 1
int leftmotor_n=12;     //left motor pin 2
int rightmotor_p=11;    //right motor pin 1
int rightmotor_n=10;    // right motor pin 2
int sensor = A0;        //accelerometer sensor pin to analog pin in arduino



void setup() {
  pinMode(leftmotor_p, OUTPUT);
  pinMode(leftmotor_n, OUTPUT);
  pinMode(rightmotor_p, OUTPUT);
  pinMode(rightmotor_n, OUTPUT); //Set all motor pins to give output
}
 
void loop() 
{
  
  int sensorValue = analogRead(A0);  // read the input on analog 
  
  if(sensorValue<850 && sensorValue > 650)  //conditional statement for moving forward when the sensor tilts forward
  {
    forward() ;
  }
  if(sensorValue<1020 && sensorValue>850)   //conditional statement for moving back when the sensor tilts backwards
  {
    backward();
  }
  if(sensorValue<500 && sensorValue>250)   //conditional statement for moving turns left when the sensor tilts left
  {
    turn_left();
  }
  if (sensorValue<250 && sensorValue>10)   //conditional statement for moving turns right when the sensor tilts right
  {
    turn_right();
  }
  if (sensorValue == 1023)                 //conditional statement to stand still 
  {
    halt();
  }
 }

 void backward() 
 {
  digitalWrite(leftmotor_p,LOW );
  digitalWrite(leftmotor_n,HIGH);
  digitalWrite(rightmotor_p,LOW);
  digitalWrite(rightmotor_n,HIGH);
 return;
 }
 void forward() {                         
  digitalWrite(leftmotor_p,HIGH );
  digitalWrite(leftmotor_n,LOW);
  digitalWrite(rightmotor_p,HIGH);
  digitalWrite(rightmotor_n,LOW);
  return;
 }
 void turn_left() {
  digitalWrite(leftmotor_p,LOW );
  digitalWrite(leftmotor_n,HIGH);
  digitalWrite(rightmotor_p,HIGH);
  digitalWrite(rightmotor_n,LOW);
  delay(500);
  digitalWrite(leftmotor_p,HIGH );
  digitalWrite(leftmotor_n,LOW);
  digitalWrite(rightmotor_p,HIGH);
  digitalWrite(rightmotor_n,LOW);
 
 }
 void turn_right() {                         
  digitalWrite(leftmotor_p,HIGH );
  digitalWrite(leftmotor_n,LOW);
  digitalWrite(rightmotor_p,LOW);
  digitalWrite(rightmotor_n,HIGH);
  delay(500);
  digitalWrite(leftmotor_p,HIGH );
  digitalWrite(leftmotor_n,LOW);
  digitalWrite(rightmotor_p,HIGH);
  digitalWrite(rightmotor_n,LOW);
 }
 void halt()
 {
  digitalWrite(leftmotor_p,HIGH );
  digitalWrite(leftmotor_n,HIGH);
  digitalWrite(rightmotor_p,HIGH);
  digitalWrite(rightmotor_n,HIGH);
 }

