int soilMoistureValue = 0;
int percentage = 0;

void setup() {
  pinMode(12, OUTPUT);   // Motor Driver IN2
  pinMode(13, OUTPUT);   // Motor Driver IN1
  Serial.begin(9600);    // Start Serial Monitor
}

void loop() {
  // Read moisture value from sensor
  soilMoistureValue = analogRead(A5);

  // Convert raw sensor value to moisture percentage
  percentage = map(soilMoistureValue, 490, 1023, 100, 0);

  // Display moisture reading
  Serial.print("Soil Moisture (%): ");
  Serial.println(percentage);

  // Cactus-specific moisture thresholds
  if (percentage < 10) {
    Serial.println("Extremely Dry (<10%) - Pump ON");
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
  }
  else if (percentage >= 10 && percentage <= 30) {
    Serial.println("Optimal Moisture (10–30%) - Pump OFF");
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
  }
  else if (percentage > 30) {
    Serial.println("Too Wet (>30%) - Pump OFF");
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
  }

  delay(1000);
}
