#include <Servo.h>

#define irSensor 9
#define enA 3
#define in1A 4
#define in2A 5

Servo s;

// Time to keep reversing AFTER leaving the black tape, to get back to the start.
const unsigned long RETURN_TIME = 10000;  

void setup() {
  s.attach(8);
  s.write(0);
  pinMode(irSensor, INPUT);
  pinMode(enA, OUTPUT);
  pinMode(in1A, OUTPUT);
  pinMode(in2A, OUTPUT);
  digitalWrite(enA, HIGH);
}

void loop() {
  int floorColour = digitalRead(irSensor);
  Forward();
  while (digitalRead(irSensor) == floorColour) { }
  delay(30);                

  Stop();
  delay(500);

  Backward();
  while (digitalRead(irSensor) != floorColour) { }
  delay(30);

  delay(RETURN_TIME);
  Stop();
  while (true) { }         
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
