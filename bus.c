#include "bus.h"
static u8 bus_index = 0;

Bus create_bus(u8 logical_bus)
{
    Bus b =  (Bus){
        .bus_index = bus_index++,
        .logical_bus = logical_bus,
    };
    FastLED.addLeds<WS2812B, logical_bus, RGB>(b.leds, 0, LEDs_per_strip * strips_per_bus);
    return b;
}

void destroy_bus(Bus b)
{
    (void)(b);
}


void light_bus_led(Bus b, u16 x, u16 y, CRGB color)
{
    x *= (LEDs_per_strip / 2)
    if (x % 2 == 1)
    {
        y = (LEDs_per_strip / 2) - y;
    }
    u16 index = (x * LEDs_per_strip / 2) + y;
    if (index > LEDs_per_bus)
    {
        printf("(%d, %d) is not a valid position. Index = %d", x, y, index);
    }
    if (index < 0)
    {
        printf("Index is less than zero good luck debugging this one buddy!");
    }
    b.leds[(x * LEDs_per_strip / 2) + y] = color;
}

void light_bus(Bus b, CRGB color)
{
    for (u8 i = 0; i < LEDs_per_bus; i++)
    {
        b.leds[i] = color;
    }
}