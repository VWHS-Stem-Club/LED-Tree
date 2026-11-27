#pragma once
#include "ints.h"

typedef struct
{
    u16 x;
    u16 y;
    u16 width;
    u16 height;
    u8 thickness;
    CHSV color;
} Rect;

Rect rect_create(u16 x, u16 y, u16 width, u16 height, u8 thickness, CHSV color);
#define square_create(u16 x, u16 y, u16 side, u8 thickness, CHSV color) ((rect_create(x, y, side, side, thickness, color)))
