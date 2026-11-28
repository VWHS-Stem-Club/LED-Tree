#pragma once
#include "ints.h"
#include "FastLED.h"

typedef struct
{
    u16 x;
    u16 y;
    u16 radius;
    f64 starting_angle;
    f64 ending_angle;
    u8 thickness;
    CHSV color;
} Circle;

/**
 *  @brief Creates a usable circle centered around (x, y)
 *  @param x x
 *  @param y y
 *  @param starting_angle The arc angle in radians at which the circle exists
 *  @param ending_angle The arc angle in radians at which the circle exists
 *  @param thickness How thick the circle is
 *  @param color The color of the circle
 *
 */
Circle circle_create(u16 x, u16 y, u16 radius, f64 starting_angle, f64 ending_angle, u8 thickness, CHSV color);

