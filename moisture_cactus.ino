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

  if (percentage < 70) {
    Serial.println("Dry (<70%) - Pump ON");
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
  }
  else if (percentage >= 70 && percentage <= 90) {
    Serial.println("Optimal (70–90%) - Pump OFF");
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
  }
  else if (percentage > 90) {
    Serial.println("Too Wet (>90%) - Pump OFF");
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
  }

  delay(1000);
}
