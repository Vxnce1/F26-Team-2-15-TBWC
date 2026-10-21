
#define enA 3
#define in1A 4
#define in2A 5
#define irSensor 2

void setup() {
  Serial.begin(9600);

  pinMode(enA, OUTPUT);
  pinMode(in1A, OUTPUT);
  pinMode(in2A, OUTPUT);
  pinMode(irSensor, INPUT);

  digitalWrite(enA, HIGH);
}

void loop() {
  int sensorValue = digitalRead(irSensor);

  if (sensorValue == LOW) {
    // Object detected (common for IR obstacle sensors)
    digitalWrite(in1A, HIGH);
    digitalWrite(in2A, LOW);

    Serial.println("Object detected - spinning one way");
  } 
  else {
    // No object detected
    digitalWrite(in1A, LOW);
    digitalWrite(in2A, LOW);

    Serial.println("No object detected - stopped");
  }

  delay(100);
}
