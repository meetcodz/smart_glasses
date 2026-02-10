#define echoPindown 7
#define trigPindown 8

#define buzzerPin 3

long baselineDistance = 0;   
long threshold = 20;         

long getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  long distance = duration * 0.0343 / 2;

  return distance;
}

void setup() {
  Serial.begin(9600);

  pinMode(trigPindown, OUTPUT);
  pinMode(echoPindown, INPUT);
  pinMode(buzzerPin, OUTPUT);

  delay(2000);

  long sum = 0;
  for (int i = 0; i < 5; i++) {
    sum += getDistance(trigPindown, echoPindown);
    delay(100);
  }

  baselineDistance = sum / 5;

  Serial.print("Baseline Ground Distance: ");
  Serial.println(baselineDistance);
}

void loop() {

  long distancedown = getDistance(trigPindown, echoPindown);

  Serial.print("Current Distance: ");
  Serial.println(distancedown);

  if (distancedown > baselineDistance + threshold) {

    Serial.println("POTHOLE DETECTED!");

    digitalWrite(buzzerPin, HIGH);
    delay(300);
    digitalWrite(buzzerPin, LOW);
    delay(300);
  }

  delay(100);
}
