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

  Serial.begin(9600); // Ganti dari 1000 ke 9600 agar standar dan lebih stabil
}

void loop() {
  // Kirim sinyal trigger ke sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Baca durasi pantulan dari echo
  duration = pulseIn(echoPin, HIGH);

  // Hitung jarak dalam cm
  distance = duration * 0.034 / 2;

  // Tampilkan di serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Nyalakan LED sesuai kondisi
  if (distance <= 10) {
    digitalWrite(ledWarning, HIGH);
    digitalWrite(ledSafe, LOW);     
  } else {
    digitalWrite(ledWarning, LOW);  
    digitalWrite(ledSafe, HIGH);    
  }

  delay(1000); 
}