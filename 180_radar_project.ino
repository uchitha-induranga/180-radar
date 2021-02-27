/*////////////HRTE PROJECTS RADAR////////////////////////////////////// */

#include <Servo.h>. 
int trigPin = 8;
int echoPin = 9;
long duration;
int distance;


Servo myServo; 

void setup() {

  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600);
  myServo.attach(2); 
 
}
void loop() {

  for(int i=0;i<=180;i++){  
  myServo.write(i);
  delay(30);

  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); 
  distance= duration*0.034/2;
  
  Serial.print(i); 
  Serial.print(","); 
  Serial.print(distance);
  Serial.print("."); 
 
  }
 
  for(int i=180;i>0;i--){  
  myServo.write(i);
  delay(30);
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); 
  distance= duration*0.034/2;
 
  Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  }
}
