#include "Ultrasonic.h"
#define trigger 5
#define echo 4
#define Relay_1 6
#define Relay_2 7


float time=0,distance;
Ultrasonic ultrasonic(5,4);
int ledPin=10;
int ledPin1=9;
int ledPin2=8;
void setup()
{	
	Serial.begin(9600);
	pinMode(trigger,OUTPUT);
	pinMode(echo,INPUT);
	pinMode(Relay_1,OUTPUT);
  pinMode(Relay_2,OUTPUT);
  pinMode(ledPin,OUTPUT);
   pinMode(ledPin1,OUTPUT);
    pinMode(ledPin2,OUTPUT);
	
	delay(2000);
}
void loop()
{
 measure_distance();
 
 if(distance>0 && distance<10)
 {
	digitalWrite(Relay_1,LOW);
  digitalWrite(Relay_2,HIGH);  
  digitalWrite(ledPin,LOW);
  digitalWrite(ledPin1,HIGH); 
  digitalWrite(ledPin2,LOW); 
}
else if(distance>14 && distance<20)
 {
	digitalWrite(Relay_1,HIGH);
  digitalWrite(Relay_2,LOW);
  digitalWrite(ledPin,LOW);
   digitalWrite(ledPin1,LOW);
   digitalWrite(ledPin2,HIGH); 
   //digitalWrite(ledPin1,HIGH);  
 }
 else 
 {
	digitalWrite(Relay_1,HIGH);
  digitalWrite(Relay_2,HIGH);
  digitalWrite(ledPin,HIGH);
   digitalWrite(ledPin1,LOW);
   digitalWrite(ledPin2,LOW);
 }


 delay(500);
}
void measure_distance()
{
  distance = ultrasonic.read(CM);
  Serial.print("Object found at: ");
  Serial.print(distance);
  Serial.println("cm");
}