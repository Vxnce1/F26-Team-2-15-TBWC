#include <Servo.h>

#define irSensor 9
#define enA 3
#define in1A 4
#define in2A 5

Servo s;
const unsigned long PAST_TIME = 400; 

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
  delay(1000);              

  Stop();

  s.write(180);
  while (true) { }
}

void Forward() {
  digitalWrite(in1A, HIGH);
  digitalWrite(in2A, LOW);
}

void Stop() {
  digitalWrite(in1A, LOW);
  digitalWrite(in2A, LOW);
}
