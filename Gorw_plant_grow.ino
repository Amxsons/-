#include <Arduino.h>

// Define the pin where the soil moisture sensor is connected
#define MOISTURE_PIN A0

// Messages for each category
const char* highMessages[] = {
  "Congratulations, dear plant! You are fully hydrated and thriving! Keep up the excellent work!",
  "Your leaves are shining bright, and your roots are happy! Remember, in this jungle of life, you are a true champion of growth!",
  "You're a fantastic plant, and your potential is limitless! Keep reaching for the sky!"
};

const char* mediumMessages[] = {
  "Hello, wonderful plant! You're halfway to being fully hydrated! Remember, just like life, balance is key.",
  "Stay positive and keep reaching for that sunlight! You’ve got the strength to pull through this.",
  "A little more water, and you’ll be back to your glorious self in no time! Let’s aim for those high humidity goals together!"
};

const char* lowMessages[] = {
  "Oh dear plant, it appears you’re feeling a bit thirsty! Don’t lose hope! Remember, resilience is your middle name!",
  "Take a deep breath and visualize that cool, refreshing water coming your way. This too shall pass!",
  "You are stronger than you think! Every drop of water is a step towards your dreams!"
};

void setup() {
  Serial.begin(9600);  // Initialize serial communication
}

void loop() {
  // Read the moisture level
  int moistureLevel = analogRead(MOISTURE_PIN);
  
  // Convert the moisture level to a percentage (0 to 100%)
  float moisturePercentage = map(moistureLevel, 0, 1023, 0, 100);

  // Determine the moisture category
  String moistureCategory;
  const char* message = "";
  
  if (moisturePercentage > 75) {
    moistureCategory = "High";
    message = highMessages[random(0, 3)];
  } else if (moisturePercentage > 50) {
    moistureCategory = "Medium";
    message = mediumMessages[random(0, 3)];
  } else {
    moistureCategory = "Low";
    message = lowMessages[random(0, 3)];
  }

  // Print the results to the Serial Monitor
  Serial.print("Soil Moisture Level: ");
  Serial.print(moisturePercentage);
  Serial.print(" %\t");
  Serial.print("Category: ");
  Serial.print(moistureCategory);
  Serial.print("\tMessage: ");
  Serial.println(message);

  // Add a delay before the next reading
  delay(2000); // Wait 2 seconds
}
