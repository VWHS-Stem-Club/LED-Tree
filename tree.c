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
    tree.busses[0] = create_bus(PIN_1);
    tree.busses[1] = create_bus(PIN_2);
    tree.busses[2] = create_bus(PIN_3);
    tree.busses[3] = create_bus(PIN_4);
}

void destroy_tree()
{
    for (u8 i = 0; i < 4; i++)
    {
        destroy_bus(tree[i]);
    }
    tree = (Tree){0};
}

void light_led(u8 x, u8 y, CHSV color)
{
    u8 bus_relative_x = x % (strips_per_bus * 2);
    CRGB col = color;
    light_bus_led(tree.busses[x % 4], x, y, col);
}
