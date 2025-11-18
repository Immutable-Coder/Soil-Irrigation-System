# Soil-Irrigation-System
An automated soil-moisture-based irrigation system using Arduino Uno, a moisture sensor, and a water pump. It monitors real-time soil moisture and activates the pump when levels drop below a threshold, improving water efficiency. Low-cost, reliable, and ideal for smart farming and academic projects

🌱 Smart Soil Moisture Monitoring & Automated Irrigation System

A smart Arduino-based irrigation system that automatically waters plants according to real-time soil moisture levels. This project includes crop-specific moisture thresholds to optimize watering for different plants, reduce water wastage, and improve irrigation efficiency.

🚀 Features

🌡 Real-time soil moisture detection

🤖 Automatic water pump control

🌾 Crop-specific irrigation logic

💧 Prevents overwatering and underwatering

⚡ Low-cost, beginner-friendly setup

📉 Achieved up to 28% water savings in testing

🧪 Modular .ino files (one for each crop)

🧩 Hardware Components
Component	Description
Arduino Uno	ATmega328P microcontroller
Soil Moisture Sensor	Analog resistive sensor
L298N Motor Driver	Controls DC water pump
Mini DC Water Pump	5V/9V
9V Battery / Adapter	Power source
Jumper Wires + Breadboard	Connections
📁 Project Structure
├── moisture_generic.ino
├── moisture_wheat.ino
├── moisture_cactus.ino
├── moisture_rice.ino
├── moisture_potato.ino
└── moisture_tomato.ino


Each .ino file contains custom moisture thresholds for a specific crop.

🛠 How It Works

Soil moisture sensor sends analog value to Arduino

Arduino maps this value to a moisture percentage

Compares it with crop-specific moisture range

Turns pump ON/OFF using motor driver

Displays moisture level + pump status via Serial Monitor

💻 Example Code Snippet (Generic File)
soilMoistureValue = analogRead(A5);
percentage = map(soilMoistureValue, 490, 1023, 100, 0);

if (percentage < 40) {
  digitalWrite(13, HIGH); // Pump ON
} else {
  digitalWrite(13, LOW);  // Pump OFF
}

🔬 Testing & Results

Pump activates in < 3 seconds during low moisture

Field test showed 28% water savings

Stable performance in loamy soil

Occasional recalibration recommended for best accuracy

🔭 Future Enhancements

🌐 IoT integration (ESP8266/ESP32)

☀️ Solar-powered irrigation

📱 Mobile app for remote monitoring

🌦 Weather-based irrigation prediction

🧪 Capacitive sensors for more accurate readings

👨‍💻 Contributors

Harshit Chaudhary

(Add the rest of your team here)

📜 License

This project is licensed under the MIT License.
