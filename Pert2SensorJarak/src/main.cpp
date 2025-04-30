#include <Arduino.h>

int echoPin = D2;
int trigPin = D4;
int ledPin = D6;

int distance;
long duration;

void setup() {
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(7);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(8);
  digitalWrite(trigPin, LOW);

  //untuk menghitung waktu sinyal diterima kembali
  duration = pulseIn(echoPin, HIGH);

  //menghitung jarak
  distance = duration * 0.034 / 2;

  //Display serial number
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  //Set LED berdasarkan kondisi
  if (distance <= 10) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(700);
}