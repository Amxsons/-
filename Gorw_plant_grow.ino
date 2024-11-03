#include <Arduino.h>

#define MOISTURE_PIN A0

void setup() {
  Serial.begin(9600);  // Initialize serial communication
}

void loop() {
  // Read the moisture level
  int moistureLevel = analogRead(MOISTURE_PIN);
  
  // Convert the moisture level to a percentage (0 to 100%)
  float moisturePercentage = map(moistureLevel, 0, 1023, 0, 100);

  // Determine the moisture category and send it to Serial
  if (moisturePercentage > 75) {
    Serial.println("Low");
  } else if (moisturePercentage > 50) {
    Serial.println("Medium");
  } else {
    Serial.println("High");
  }

  // Add a delay before the next reading
  delay(8000); // Wait 2 seconds
}
