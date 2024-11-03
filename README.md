# Plant Hydration Monitor with Arduino and TTS

## Overview
This project uses an Arduino and a Python script to monitor plant soil moisture levels and provide feedback using text-to-speech (TTS) notifications. It helps keep plants hydrated by informing you of their moisture level in real-time through an audio message.

## Components
- **Arduino** (e.g., Arduino Uno or similar)
- **Soil Moisture Sensor**
- **Python Libraries**:
  - `serial`: For communication with Arduino
  - `pyttsx3`: For TTS functionality
  - `time`: To manage loop intervals
  - `random`: For message selection

## Project Structure
### 1. **Arduino Code**
   - Reads moisture level from the sensor and categorizes it into "Low," "Medium," or "High" based on moisture percentage.
   - Sends the moisture category via serial communication to the Python script.

### 2. **Python Script**
   - Connects to the Arduino over serial.
   - Reads the moisture category sent from the Arduino.
   - Uses TTS to deliver a random message based on the moisture category.

### Usage
1. **Upload the Arduino code** to your Arduino board.
2. **Run the Python script** on your computer.
3. Place the soil moisture sensor in the plant's soil, and the Python script will audibly notify you of the moisture status every 8 seconds.

## Code Explanation

### Arduino Code
The Arduino code reads the analog moisture level, converts it to a percentage, and categorizes it:
- **Low**: Moisture > 75%
- **Medium**: Moisture between 50% and 75%
- **High**: Moisture < 50%

### Python Code
The Python script:
1. Initializes TTS and serial connection.
2. Receives moisture levels from Arduino.
3. Reads the category, picks a random message, and speaks it.

## 🎥 Video Documentation: The Journey of **Grow Plant Grow** 🌱

Watch the full video documentation of the project here:

[![Grow Plant Grow Video](https://img.youtube.com/vi/16ox4b0THG-eBKAacoZPVBqhGLeGxxGDM/0.jpg)](https://drive.google.com/file/u/0/d/16ox4b0THG-eBKAacoZPVBqhGLeGxxGDM/view?usp=drivesdk&pli=1)

> Click on the image above or [this link](https://drive.google.com/file/u/0/d/16ox4b0THG-eBKAacoZPVBqhGLeGxxGDM/view?usp=drivesdk&pli=1) to view the video documentation.



## Example Messages
- **High**: "Congratulations, dear plant! You are fully hydrated and thriving!"
- **Medium**: "You're halfway to being fully hydrated! Balance is key."
- **Low**: "Oh dear plant, it appears you’re feeling a bit thirsty! Resilience is your middle name!"

## Requirements
- Arduino IDE for uploading code.
- Python 3 with `pyserial` and `pyttsx3` libraries.

## Notes
- Adjust the serial port in the Python code based on your system.
- Ensure the moisture sensor is calibrated if readings are inaccurate.
