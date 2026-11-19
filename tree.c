#include "tree.h"
#include "config.h"
#include "bus.h"
#include <FastLED.h>

typedef struct
{
    Bus busses[4];
} Tree;

static Tree tree = (Tree){0};

void create_tree()
{
    FastLED.setBrightness(brightness_scalar);
    // ignore this for now because we don't know the numbers
//    FastLED.setMaxPowerInVoltsAndMilliamps(LED_max_volts, LED_max_amps);

    // busses 0, 1, and 3 are going to be unused for now, since we don't have the physical hardware hooked up yet.
    tree.busses[0] = create_bus(PIN_1);
    tree.busses[1] = create_bus(PIN_2);
    tree.busses[2] = create_bus(PIN_3);
    tree.busses[3] = create_bus(PIN_4);
    FastLED.show();
}


void destroy_tree()
{
    // temporarily comment out the for loop and only remove bus 2.
    for (u8 i = 0; i < 4; i++)
    {
        destroy_bus(&tree.busses[i]);
    }
    destroy_bus(&tree.busses[2]);
    tree = (Tree){0};
}

void light_led(u8 x, u8 y, CHSV color)
{
    u8 bus_relative_x = x % (strips_per_bus * 2);
    CRGB col = color;
    // force calls to go to pin 18
    // light_bus_led(&tree.busses[x % 4], bus_relative_x, y, col);
    light_bus_led(&tree.busses[2], bus_relative_x, y, col);
}

Bus* get_bus(u8 bus_num)
{
    if (bus_num > 3)
    { return NULL; }
    return &tree.busses[bus_num];
}
