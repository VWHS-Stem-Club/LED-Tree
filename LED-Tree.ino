#include <FastLED.h>
#include "bus.h"
#include "tree.h"
#include "config.h"

// CHSV(0,   255, 255);  // Red
// CHSV(32,  255, 255);  // Orange
// CHSV(64,  255, 255);  // Yellow
// CHSV(96,  255, 255);  // Green
// CHSV(160, 255, 255);  // Cyan-ish
// CHSV(192, 255, 255);  // Blue
// CHSV(224, 255, 255);  // Purple

static u8 x = 0;
static u8 y = 0;
static u8 t = 0;
static CHSV color = CHSV(0, 255, 255);

// f32 lerp(f32 a, f32 b, f32 t)
// {
//     return a + (b - a) * t;
// }

void stripes()  
{
    for (u8 y = 0; y < LEDs_per_strip / 2; y++)
    {
        if (x == 0)
        {
          light_led(strips_per_bus * 2 - 1, y, CHSV(0, 0, 0));
        }
        else
        {
          light_led(x - 1, y, CHSV(0, 0, 0));
        }

        light_led(x, y, color);
    }
    tree_show();
    delay(30);
    x++;
    x %= (strips_per_bus * 2);
}

void spiral()
{
    const u8 snake_length = 25;
    for (u8 i = 0; i < snake_length; i++)
    {
      u8 renderx = (x + i) % (strips_per_bus * 2);
      u8 rendery = (y + i) % (LEDs_per_strip / 2);

      if (i == 0)
      {
        u8 clearx = x - 1;
        u8 cleary = y - 1;
        if (x == 0)
        {
          clearx = strips_per_bus * 2 - 1;
        }
        if (y == 0)
        {
          cleary = LEDs_per_strip / 2 - 1;
        }
        light_led(clearx, cleary, CHSV(0, 0, 0));
      }
      light_led(renderx, rendery, color);
    }
    x++;
    y++;
    x %= (strips_per_bus * 2);
    y %= (LEDs_per_strip / 2);
    tree_show();
    delay(30);
}

void setup() {
    create_tree();
    t = 0;
}

void loop() {
    t += 1;
    color = CHSV((u8)(lerp(0.0f, 255.0f, t)), 255, 255);
    // put your main code here, to run repeatedly:
// stripes();
    spiral();
    // Bus* b = get_bus(2);
    // light_bus(b, CRGB::Red);
//    tree_show();
}
