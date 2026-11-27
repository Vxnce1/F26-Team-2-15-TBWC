#include <Servo.h>

#define irSensor 9
#define enA 3
#define in1A 4
#define in2A 5

const unsigned long BUFFER = 750;

Servo s;

void setup() {
  pinMode(irSensor, INPUT);
  pinMode(enA, OUTPUT);
  pinMode(in1A, OUTPUT);
  pinMode(in2A, OUTPUT);
  digitalWrite(enA, HIGH);
  Serial.begin(9600);
}

// void loop() {
//   Forward();
//   unsigned long startTime = millis();
//   // delay(1000);
//   // while (analogRead(irSensor) == 0) { }
//   int count = 0;
//   while (count < 2) {
//     if ((millis() - startTime > BUFFER && digitalRead(irSensor) == 1) {
//       count++;
//     } else {
//       count = 0;
//     }
//     delay(10);
//   }
//   Backward();
//   while (true) {}
// }


void loop() {
  Forward();
  unsigned long startTime = millis();

  int count = 0;
  while (count < 2) {
    // only look at the sensor after the buffer time is over
    if (millis() - startTime > BUFFER && digitalRead(irSensor) == 1) {
      count++;
    } else {
      count = 0;
    }
    delay(5);
  }

  Backward();
  while (true) {}
}

void Forward() {
  digitalWrite(in1A, HIGH);
  digitalWrite(in2A, LOW);
  // Serial.println("forwards");
  // delay(500);
}

void Backward() {
  digitalWrite(in1A, LOW);
  digitalWrite(in2A, HIGH);
  // Serial.println("going backwards");
  // delay(500);
}

void Stop() {
  digitalWrite(in1A, LOW);
  digitalWrite(in2A, LOW);
}
