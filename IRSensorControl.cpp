#define irSensor A3
#define wheel A2
#define trigger 8

void setup() {
  pinMode(irSensor, INPUT);
  pinMode(wheel, INPUT);
  pinMode(trigger, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int wheelValue = analogRead(wheel);

  //Serial.println(wheelValue);
  
  int sensorValue = analogRead(irSensor);

  int distance = sensorValue - wheelValue;
  

  Serial.println(distance);
  
  if (distance >= 500){
  	digitalWrite(trigger, HIGH);
  }
  
  else {
  	digitalWrite(trigger, LOW);
  }
  
  delay(200);
}
