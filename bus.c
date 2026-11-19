#include "bus.h"
#include <stdlib.h>
#include <string.h>

static u8 bus_index = 0;

static b8 is_bus(Bus* b)
{
    return b && b->leds;
}

Bus create_bus(u8 logical_bus)
{
    Bus b =  (Bus){
        .bus_index = bus_index++,
        .logical_bus = logical_bus,
        .leds = malloc(sizeof(CRGB) * LEDs_per_bus)
    };
    memset(leds, 0, sizeof(CRGB) * LEDs_per_bus);
    if (!b.leds)
    {
        printf("LED allocation failed.");
        return (Bus){0};
    }
    FastLED.addLeds<WS2811, logical_bus, RGB>(b.leds, 0, LEDs_per_bus);
    return b;
}

void destroy_bus(Bus* b)
{
    if (!is_bus(b))
    {
        printf("Cannot destroy empty bus, ignoring call to destroy_bus");
        return;
    }
    free(b->leds);
    *b = (Bus){0};
}


void light_bus_led(Bus* b, u16 x, u16 y, CRGB color)
{
    if (!is_bus(b))
    {
        printf("Cannot light LED on empty bus.");
        return;
    }

    if (x % 2 == 1)
    {
        y = (LEDs_per_strip / 2) - y;
    }
    u16 index = (x * (LEDs_per_strip / 2)) + y;
    if (index >= LEDs_per_bus)
    {
        printf("(%d, %d) is not a valid position. Index = %d", x, y, index);
    }
    b->leds[(x * LEDs_per_strip / 2) + y] = color;
}

void light_bus(Bus* b, CRGB color)
{
    if (!is_bus(b))
    {
        printf("Cannot light LED on empty bus.");
        return;
    }

    for (u16 i = 0; i < LEDs_per_bus; i++)
    {
        b->leds[i] = color;
    }
}
