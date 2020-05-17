#include "Arduino.h"

#include <Adafruit_NeoPixel.h>

#define PIN        3 // On Trinket or Gemma, suggest changing this to 1

#define NUMPIXELS 30 // Popular NeoPixel ring size

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels

void setup() {
  Serial.begin(9600);         //start the serial communication
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  for (int i = 0; i < NUMPIXELS; i++) { // For each pixel...
    pixels.setPixelColor(i, pixels.Color(0, 150, 0));
    pixels.show();   // Send the updated pixel colors to the hardware.
  }
}

void loop() {


  if (Serial.available() >= 3) {         //if some data is available of in the serial port
    byte r = Serial.read();
    byte g = Serial.read();
    byte b = Serial.read();

    for (int i = 0; i < NUMPIXELS; i++) { // For each pixel...
      pixels.setPixelColor(i, pixels.Color(int(r), int(g), int(b)));
    }
    pixels.show();   // Send the updated pixel colors to the hardware.
    Serial.flush();
  }


}
