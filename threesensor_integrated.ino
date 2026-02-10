// Left Sensor
#define echoPinL 11
#define trigPinL 12

// Center Sensor
#define echoPinC 9
#define trigPinC 10

// Right Sensor
#define echoPinR 7
#define trigPinR 8

#define buzzerPin 3

long getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delay(2);
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  long distance = duration * 0.0343 / 2;

  return distance;
}

void setup() {
  Serial.begin(9600);

  pinMode(trigPinL, OUTPUT);
  pinMode(echoPinL, INPUT);

  pinMode(trigPinC, OUTPUT);
  pinMode(echoPinC, INPUT);

  pinMode(trigPinR, OUTPUT);
  pinMode(echoPinR, INPUT);

  pinMode(buzzerPin, OUTPUT);
}

void loop() {

  long distanceL = getDistance(trigPinL, echoPinL);
  delay(50);

  long distanceC = getDistance(trigPinC, echoPinC);
  delay(50);

  long distanceR = getDistance(trigPinR, echoPinR);
  delay(50);

  Serial.print("L: ");
  Serial.print(distanceL);
  Serial.print(" cm | ");

  Serial.print("C: ");
  Serial.print(distanceC);
  Serial.print(" cm | ");

  Serial.print("R: ");
  Serial.print(distanceR);
  Serial.println(" cm");

  


  if (distanceL > 0 && distanceL < 150) {
    digitalWrite(buzzerPin, HIGH);
    delay(100);
    digitalWrite(buzzerPin, LOW);

    delay(distanceL * 10);
  }
  if (distanceR > 0 && distanceR < 150) {
    digitalWrite(buzzerPin, HIGH);
    delay(100);
    digitalWrite(buzzerPin, LOW);

    delay(distanceR * 10);
  }
  if (distanceC > 0 && distanceC < 150) {
    digitalWrite(buzzerPin, HIGH);
    delay(100);
    digitalWrite(buzzerPin, LOW);

    delay(distanceC * 10);
  }

  delay(50);
}
