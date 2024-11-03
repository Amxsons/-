import serial
import pyttsx3
import time
import random

# Initialize TTS engine
engine = pyttsx3.init()
engine.setProperty('rate', 150)  # Set speech rate
engine.setProperty('volume', 1)  # Set volume to maximum (1 is max, 0 is min)

# Define messages for each category
messages = {
    "High": [
        "Congratulations, dear plant! You are fully hydrated and thriving! Keep up the excellent work!",
        "Your leaves are shining bright, and your roots are happy! Remember, in this jungle of life, you are a true champion of growth!",
        "You're a fantastic plant, and your potential is limitless! Keep reaching for the sky!"
    ],
    "Medium": [
        "Hello, wonderful plant! You're halfway to being fully hydrated! Remember, just like life, balance is key.",
        "Stay positive and keep reaching for that sunlight! You’ve got the strength to pull through this.",
        "A little more water, and you’ll be back to your glorious self in no time! Let’s aim for those high humidity goals together!"
    ],
    "Low": [
        "Oh dear plant, it appears you’re feeling a bit thirsty! Don’t lose hope! Remember, resilience is your middle name!",
        "Take a deep breath and visualize that cool, refreshing water coming your way. This too shall pass!",
        "You are stronger than you think! Every drop of water is a step towards your dreams!"
    ]
}

# Connect to Arduino's serial port (adjusted to the specified port on your Mac)
ser = serial.Serial('/dev/cu.usbserial-120', 9600)
time.sleep(2)  # Wait for the serial connection to initialize

def speak_message(category):
    if category in messages:
        message = random.choice(messages[category])
        print(f"Speaking: {message}")  # Debug print
        engine.say(message)
        engine.runAndWait()  # Ensure the message is spoken immediately

try:
    while True:
        if ser.in_waiting > 0:
            # Read moisture category from the Arduino
            moisture_category = ser.readline().decode('utf-8').strip()
            print(f"Moisture Category: {moisture_category}")  # Debug print
            speak_message(moisture_category)
        time.sleep(2)  # Delay to avoid rapid looping
except KeyboardInterrupt:
    print("Exiting...")
finally:
    ser.close()
