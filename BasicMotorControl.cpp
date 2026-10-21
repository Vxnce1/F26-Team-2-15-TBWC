#define enA 3
#define in1A 4
#define in2A 5

void setup (){
  Serial.begin(9600);

  pinMode(enA, OUTPUT);
  pinMode(in1A, OUTPUT);
  pinMode(in2A, OUTPUT);

  digitalWrite(enA, HIGH);
}

void loop (){
  digitalWrite(in1A, HIGH);
  digitalWrite(in2A, LOW);
  Serial.println("spinning one way")

  delay(1500)
  digitalWrite(in1A, LOW);
  digitalWrite(in2A, LOW);
  Serial.println("stopped")
  delay(1500)
}
