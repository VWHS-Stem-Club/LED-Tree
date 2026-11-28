#pragma once
#include "ints.h"
#include "FastLED.h"

typedef struct
{
    u16 x1;
    u16 y1;
    u16 x2;
    u16 y2;
    u8 thickness;
    CHSV color;
} Line;

/**
 *  @brief Creates a usable line going from (x1, y1) -> (x2, y2)
 *  @param x1 x1
 *  @param y1 y1
 *  @param x2 x2
 *  @param y2 y2
 *  @param thickness How thick the line is
 *  @param color The color of the line
 *
 */
Line line_create(u16 x1, u16 y1, u16 x2, u16 y2, u8 thickness, CHSV color);

