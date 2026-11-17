#include <Servo.h>
#define irSensor A0
#define enA 3
#define in1A 4
#define in2A 5

Servo s;

void setup() {
  Serial.begin(9600);
  s.attach(8);
  pinMode(irSensor, INPUT);      

  pinMode(enA, OUTPUT);
  pinMode(in1A, OUTPUT);
  pinMode(in2A, OUTPUT);

  digitalWrite(enA, HIGH);   
}

void loop() {
  int sensorValue = analogRead(irSensor);
  Serial.println(sensorValue);

  ReleasePin(sensorValue);
  delay(2000);
}

void ReleasePin(int sensorValue) {
  if(sensorValue < 500) {
  s.write(180);
  delay(500);
  }
  else {
    s.write(0);
    delay(500);
  }
}

void Forward() {
  digitalWrite(in1A, HIGH);
  digitalWrite(in2A, LOW);
}

void Backward() {
  digitalWrite(in1A, LOW);
  digitalWrite(in2A, HIGH);
}

void Stop() {
  digitalWrite(in1A, LOW);
  digitalWrite(in2A, LOW);
}


