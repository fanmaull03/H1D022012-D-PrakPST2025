#include <Arduino.h>

//deklarasi variabel

int echoPin = D1;
int trigPin = D0;
int ledPin = D3;

//deklarasi variabel waktu dan jarak

long duration;
int distance;

void setup() {
 pinMode(echoPin, INPUT);
 pinMode(trigPin, OUTPUT);
 pinMode(ledPin, OUTPUT);

 Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin,LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  //untuk
  duration = pulseIn(echoPin,HIGH);

  // menghitung Jarak
  distance = duration*0.034/2;

  //Display
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print("cm");
  
  if(distance <= 10){
    digitalWrite(ledPin,HIGH);
  }else {
    digitalWrite(ledPin,LOW);
  }

  delay(1000);
}
