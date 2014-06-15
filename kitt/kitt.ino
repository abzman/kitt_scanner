#include "FastLED.h"

// How many leds in your strip?
#define NUM_LEDS 8

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806, define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 11
#define CLOCK_PIN 13
#define time 70
// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() { 
  FastLED.addLeds<TM1803, DATA_PIN, GBR>(leds, NUM_LEDS);
}

void loop() { 
  // First slide the led in one direction
  for(int i = 1; i < NUM_LEDS; i++) {
    // Set the i'th led to red 
    leds[i].r = 255;
    if(i!=0)
    {
      leds[i-1].r = 15;
    }
    // Show the leds
    FastLED.show();
    // now that we've shown the leds, reset the i'th led to black
    leds[i] = CRGB::Black;
    if(i!=0)
    {
      leds[i-1].r = 0;
    }
    // Wait a little bit before we loop around and do it again
    delay(time);
  }

  // Now go in the other direction.  
  for(int i = NUM_LEDS-2; i >= 0; i--) {
    // Set the i'th led to red 
    leds[i].r = 255;
    if(i!=(NUM_LEDS -1))
    {

      leds[i+1].r = 15;
    }
    // Show the leds
    FastLED.show();
    // now that we've shown the leds, reset the i'th led to black
    leds[i] = CRGB::Black;
    if(i!=(NUM_LEDS -1))
    {

      leds[i+1].r = 0;
    }
    // Wait a little bit before we loop around and do it again
    delay(time);
  }
}

