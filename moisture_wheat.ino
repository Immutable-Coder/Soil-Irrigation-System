int soilMoistureValue = 0;
int percentage = 0;

void setup() {
  pinMode(12, OUTPUT);   // Motor Driver IN2
  pinMode(13, OUTPUT);   // Motor Driver IN1
  Serial.begin(9600);    // Serial for monitoring
}

void loop() {
  // Read raw value from moisture sensor
  soilMoistureValue = analogRead(A5);

  // Convert sensor value into percentage (100 = wet, 0 = dry)
  percentage = map(soilMoistureValue, 490, 1023, 100, 0);

  Serial.print("Soil Moisture (%): ");
  Serial.println(percentage);

  // Wheat-specific moisture thresholds
  if (percentage < 15) {
    Serial.println("Extremely Dry (<15%) - Pump ON");
    digitalWrite(13, HIGH);  // Pump ON
    digitalWrite(12, LOW);
  }
  else if (percentage >= 15 && percentage < 30) {
    Serial.println("Dry (15–30%) - Pump ON");
    digitalWrite(13, HIGH);  // Pump ON
    digitalWrite(12, LOW);
  }
  else if (percentage >= 30 && percentage <= 50) {
    Serial.println("Optimal (30–50%) - Pump OFF");
    digitalWrite(13, LOW);   // Pump OFF
    digitalWrite(12, LOW);
  }
  else if (percentage > 50) {
    Serial.println("Too Wet (>50%) - Pump OFF");
    digitalWrite(13, LOW);   // Pump OFF
    digitalWrite(12, LOW);
  }

  delay(1000); // Repeat every 1 second
}
