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

Line line_create(u16 x1, u16 y1, u16 x2, u16 y2, u8 thickness, CHSV color);

