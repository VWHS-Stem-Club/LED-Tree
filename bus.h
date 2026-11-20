#pragma once
#include <FastLED.h>
#include "config.h"
#include "ints.h"

typedef struct
{
    u8 bus_index;
    u8 logical_bus;
    CRGB* leds;
} Bus;

Bus create_bus(u8 logical_bus);
void destroy_bus(Bus* b);
// bus relative (x, y) coordinate
void light_bus_led(Bus* b, u16 x, u16 y, CRGB color);
void light_bus(Bus* b, CRGB color);
