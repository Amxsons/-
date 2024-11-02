// Define the pin where the soil moisture sensor is connected
#define MOISTURE_PIN A0

void setup() {
  Serial.begin(9600);  // Initialize serial communication
}

void loop() {
  // Read the moisture level
  int moistureLevel = analogRead(MOISTURE_PIN);
  
  // Convert the moisture level to a percentage (0 to 100%)
  // Assuming 0 = dry and 1023 = wet (adjust these values if necessary)
  float moisturePercentage = map(moistureLevel, 0, 1023, 0, 100);

  // Determine the moisture category
  String moistureCategory;
  if (moisturePercentage > 75) {
    moistureCategory = "High";
  } else if (moisturePercentage > 50) {
    moistureCategory = "Medium";
  } else {
    moistureCategory = "Low";
  }

  // Print the results to the Serial Monitor
  Serial.print("Soil Moisture Level: ");
  Serial.print(moisturePercentage);
  Serial.print(" %\t");
  Serial.print("Category: ");
  Serial.println(moistureCategory);

  // Add a delay before the next reading
  delay(2000); // Wait 2 seconds
}
