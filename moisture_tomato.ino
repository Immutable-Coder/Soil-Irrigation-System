int soilMoistureValue = 0;
int percentage = 0;

void setup() {
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  soilMoistureValue = analogRead(A5);
  percentage = map(soilMoistureValue, 490, 1023, 100, 0);

  Serial.print("Soil Moisture (%): ");
  Serial.println(percentage);

  if (percentage < 40) {
    Serial.println("Very Dry (<40%) - Pump ON");
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
  }
  else if (percentage >= 40 && percentage < 60) {
    Serial.println("Dry (40–60%) - Pump ON");
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
  }
  else if (percentage >= 60 && percentage <= 80) {
    Serial.println("Optimal (60–80%) - Pump OFF");
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
  }
  else if (percentage > 80) {
    Serial.println("Too Wet (>80%) - Pump OFF");
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
  }

  delay(1000);
}
