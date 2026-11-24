#include <Servo.h>

#define irSensor 9
#define enA 3
#define in1A 4
#define in2A 5

Servo s;

void setup() {
  pinMode(irSensor, INPUT);
  pinMode(enA, OUTPUT);
  pinMode(in1A, OUTPUT);
  pinMode(in2A, OUTPUT);
  digitalWrite(enA, HIGH);
  Serial.begin(9600);
}

void loop() {
  Forward();
  // while (analogRead(irSensor) == 0) { }
  int count = 0;
  while (count < 30) {
    if (digitalRead(irSensor) == 1) {
      count++;
    } else {
      count = 0;
    }
    delay(10);
  }
  // delay(30);                 

  // Stop();
  // delay(500);
  Backward();
  while (true) {}
}

void Forward() {
  digitalWrite(in1A, HIGH);
  digitalWrite(in2A, LOW);
  Serial.println("forwards");
  delay(500);
}

void Backward() {
  digitalWrite(in1A, LOW);
  digitalWrite(in2A, HIGH);
  Serial.println("going backwards");
  delay(500);
}

void Stop() {
  digitalWrite(in1A, LOW);
  digitalWrite(in2A, LOW);
}
