#include "tree.h"
#include "config.h"
#include "bus.h"
#include <FastLED.h>

typedef struct
{
    Bus busses[4];
    CHSV background_color;
    u8 brightness;
} Tree;

static Tree tree = (Tree){0};
static b8 initialized;

void create_tree()
{
    if (initialized)
    {
        printf("Tree already initialized. Call 'destroy_tree()' first.");
        return;
    }
    initialized = true;
    tree.brightness = brightness_scalar;
    FastLED.setBrightness(brightness_scalar);
    // ignore this for now because we don't know the numbers
//    FastLED.setMaxPowerInVoltsAndMilliamps(LED_max_volts, LED_max_amps);

    // busses 0, 1, and 3 are going to be unused for now, since we don't have the physical hardware hooked up yet.
    tree.busses[0] = create_bus(PIN_1);
    tree.busses[1] = create_bus(PIN_2);
    tree.busses[2] = create_bus(PIN_3);
    tree.busses[3] = create_bus(PIN_4);
    FastLED.show();

    tree.background_color = CHSV(0, 0, 0);
}

void destroy_tree()
{
    if (!initialized)
    {
        printf("Cannot destroy uninitialized tree. Call 'create_tree()' first.");
        return;
    }
    initialized = false;
    for (u8 i = 0; i < 4; i++)
    {
        destroy_bus(&tree.busses[i]);
    }
    tree = (Tree){0};
}

void tree_set_brightness(u8 brightness)
{
    if (!initialized)
    {
        printf("Cannot configure brightness of uninitialized tree. Call 'create_tree()' first.");
        return;
    }
    FastLED.setBrightness(brightness);
    tree.brightness = brightness;
}

u8 tree_get_brightness()
{
    if (!initialized)
    {
        printf("Cannot retrieve brightness of uninitialized tree. Call 'create_tree()' first.");
        return 0;
    }
    return tree.brightness;
}

void light_led(u8 x, u8 y, CHSV color)
{
    if (!initialized)
    {
        printf("Cannot light LEDs on an uninitialized tree. Call 'create_tree()' first.");
        return;
    }
    u8 bus_relative_x = x % (strips_per_bus * 2);
    CRGB col = color;
    // light_bus_led(&tree.busses[x % 4], bus_relative_x, y, col);
    light_bus_led(&tree.busses[2], bus_relative_x, y, col);
}

void light_row(u8 y, CHSV color)
{
    if (!initialized)
    {
        printf("Cannot light LEDs for a row on an uninitialized tree. Call 'create_tree()' first.");
        return;
    }
    if (y > LEDs_per_strip / 2)
    {
        printf("Invalid y for light_row. y must be < %d", (u16)(LEDs_per_strip / 2));
        return;
    }

    for (u8 x = 0; x < strips_per_bus * 2 * 4; x++)
    {
        light_led(x, y, color);
    }
}

void light_column(u8 x, CHSV color)
{

    if (!initialized)
    {
        printf("Cannot light LEDs for a column on an uninitialized tree. Call 'create_tree()' first.");
        return;
    }
    if (x > strips_per_bus * 2 * 4)
    {
        printf("Invalid x for light_column. x must be < %d", (u16)(strips_per_bus * 2 * 4));
        return;
    }

    for (u8 y = 0; y < LEDs_per_strip / 2; y++)
    {
        light_led(x, y, color);
    }
}

void light_tree(CHSV color)
{
    if(!initialized)
    {
        printf("Cannot light an led uninitialized tree. Call 'create_tree()' first.");
        return;
    }

    for (u8 i = 0; i < 4; i++)
    {
        light_bus(&tree.busses[i], color);
    }
}

Bus* get_bus(u8 bus_num)
{
    if (!initialized)
    {
        printf("Cannot give busses to an uninitialized tree. Call 'create_tree()' first.");
        return (Bus*){0};
    }

    if (bus_num != 2)
    { return nullptr; }
    return &tree.busses[bus_num];
}

void tree_show()
{
    if (!initialized)
    {
        printf("Cannot show uninitialized tree. Call 'create_tree()' first.");
        return 0;
    }

    FastLED.show();
}

void set_background_color(CHSV color)
{
    if (!initialized)
    {
        printf("Cannot get background color of an uninitialized tree. Call 'create_tree()' first.");
        return;
    }
    tree.background_color = color;
}
