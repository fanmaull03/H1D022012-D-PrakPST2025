#include <Arduino.h>

int echoPin = D2;
int trigPin = D4;
int ledWarning = D6; 
int ledSafe = D7;    

int distance;
long duration;

void setup() {
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(ledWarning, OUTPUT);
  pinMode(ledSafe, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  
  distance = duration * 0.034 / 2;

  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  
  if (distance <= 10) {
    digitalWrite(ledWarning, HIGH);
    digitalWrite(ledSafe, LOW);     
  } else {
    digitalWrite(ledWarning, LOW);  
    digitalWrite(ledSafe, HIGH);    
  }

  delay(1000); 
}