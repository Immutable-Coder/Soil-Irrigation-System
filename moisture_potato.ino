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

  if (percentage < 35) {
    Serial.println("Very Dry (<35%) - Pump ON");
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
  }
  else if (percentage >= 35 && percentage < 55) {
    Serial.println("Dry (35–55%) - Pump ON");
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
  }
  else if (percentage >= 55 && percentage <= 75) {
    Serial.println("Optimal (55–75%) - Pump OFF");
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
  }
  else if (percentage > 75) {
    Serial.println("Too Wet (>75%) - Pump OFF");
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
  }

  delay(1000);
}
