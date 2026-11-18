#include <FastLED.h>
#include "config.h"

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
	// put your setup code here, to run once:
	FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
	FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
	// put your main code here, to run repeatedly:
	leds[0][0] = CRGB::Red;
	FastLED.show();
}
