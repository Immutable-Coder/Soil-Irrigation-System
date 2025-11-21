int soilMoistureValue = 0;
int percentage = 0;

void setup() {
  pinMode(12, OUTPUT);   // Motor Driver IN2
  pinMode(13, OUTPUT);   // Motor Driver IN1
  Serial.begin(9600);    // Start Serial Monitor
}

void loop() {
  // Read the raw moisture value
  soilMoistureValue = analogRead(A5);

  // Convert raw value (490–1023) to moisture percentage (100–0)
  percentage = map(soilMoistureValue, 490, 1023, 100, 0);

  // Display moisture reading
  Serial.print("Soil Moisture (%): ");
  Serial.println(percentage);

  // Tomato-specific moisture conditions
  if (percentage < 45) {
    Serial.println("Dry (<45%) - Pump ON");
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
  }
  else if (percentage >= 45 && percentage < 70) {
    Serial.println("Needs Water (45–70%) - Pump ON");
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
  }
  else if (percentage >= 70 && percentage <= 85) {
    Serial.println("Optimal (70–85%) - Pump OFF");
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
  }
  else if (percentage > 85) {
    Serial.println("Too Wet (>85%) - Pump OFF");
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
  }

  delay(1000);
}
