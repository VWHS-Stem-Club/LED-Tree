#include <FastLED.h>
#include "tree.h"

#define LED_PIN error
#define NUM_LEDS_PER_STRIP 150
#define NUM_STRIPS 4

// CHSV(0,   255, 255);  // Red
// CHSV(32,  255, 255);  // Orange
// CHSV(64,  255, 255);  // Yellow
// CHSV(96,  255, 255);  // Green
// CHSV(160, 255, 255);  // Cyan-ish
// CHSV(192, 255, 255);  // Blue
// CHSV(224, 255, 255);  // Purple


static CRGB leds[NUM_STRIPS][NUM_LEDS_PER_STRIP] = { 0 };

void setup() {
    create_tree();
    light_led(0, 0, CHSV(0, 255, 255));
}

void loop() {
    // put your main code here, to run repeatedly:
    FastLED.show();
}
