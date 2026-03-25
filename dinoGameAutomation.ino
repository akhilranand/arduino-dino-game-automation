#include <Servo.h>
Servo myservo; // create servo object

int led1 = 6; // LED pin 1
int led2 = 7; // LED pin 2
int ldr=22;   // LDR threshold value

void setup()
{
  pinMode(A0,INPUT);    // LDR analog input
  pinMode(led1,OUTPUT); // LED 1 output
  pinMode(led2,OUTPUT); // LED 2 output
  myservo.attach(5);    // attach servo to pin 5
   
  Serial.begin(9600);   // start serial communication
  myservo.write(0);     // set servo to initial position (0°)
}

void loop() 
{  
   digitalWrite(led1,HIGH); // turn LED 1 ON
   digitalWrite(led2,HIGH); // turn LED 2 ON
   Serial.println(analogRead(A0)); // print LDR value
   if(analogRead(A0)>ldr)          // check if LDR value exceeds threshold
   { 
      myservo.write(0);    // set servo to 0°
      delay(100);          // wait 100ms
      myservo.write(45);   // move servo to 45° (jump)
      delay(100);          // wait 100ms
   }
   delay(10); // small delay for loop stability
}