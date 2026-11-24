#include <Servo.h>

#define irSensor A0
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
  int irValue = analogRead(irSensor);
  Serial.println(irValue);
  delay(1000);

  // Forward();
  // while (analogRead(irSensor) == 0) { }

  // delay(30);                 

  // Stop();
  // delay(500);
  // Backward();


  // while (true) {}
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
