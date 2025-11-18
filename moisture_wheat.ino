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

  if (percentage < 15) {
    Serial.println("Extremely Dry (<15%) - Pump ON");
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
  }
  else if (percentage >= 15 && percentage < 30) {
    Serial.println("Dry (15–30%) - Pump ON");
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
  }
  else if (percentage >= 30 && percentage <= 50) {
    Serial.println("Optimal (30–50%) - Pump OFF");
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
  }
  else if (percentage > 50) {
    Serial.println("Too Wet (>50%) - Pump OFF");
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
  }

  delay(1000);
}
