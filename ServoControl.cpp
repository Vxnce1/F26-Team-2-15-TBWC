#include <Servo.h>
#define button 7

int pos = 0;

Servo servo_9;

void setup()
{
  pinMode(button, INPUT);
  servo_9.attach(9, 500, 2500);

  Serial.begin(9600);
}

void loop()
{
  if (digitalRead(button) == HIGH) {
   pos = 180;
   servo_9.write(pos);
   Serial.println("pressed");
 }
  else {
    pos = 0;
    servo_9.write(pos);
  }
}


#include <Servo.h>

Servo s;

void setup() {
  Serial.begin(9600);
  s.attach(9);         
}

void loop() {

  s.write(0);
  Serial.println("0");
  delay(2000);

  s.write(100);
  Serial.println("180");
  delay(2000);
}
