#define echoPin 11
#define trigPin 12
#define buzzerPin 3

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delay(2);
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  long distance = duration * 0.0343 / 2;
  String disp = String(distance);

  if (distance > 0 && distance < 150) {
    digitalWrite(buzzerPin, HIGH);
    delay(100); 
    digitalWrite(buzzerPin, LOW);
    
    delay(distance * 10); 
  }

  Serial.print("Distance: ");
  Serial.print(disp);
  Serial.print(" cm\n");
  delay(50);
}
