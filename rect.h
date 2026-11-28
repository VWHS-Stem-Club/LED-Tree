#pragma once
#include "ints.h"
#include "FastLED.h"

typedef struct
{
    u16 x;
    u16 y;
    u16 width;
    u16 height;
    u8 thickness;
    CHSV color;
} Rect;

/**
 *  @brief Creates a usable rectangle with its bottom-left located at (x, y)
 *  @param x x
 *  @param y y
 *  @param width The width of the rectangle
 *  @param height The height of the rectangle
 *  @param thickness How thick the rectangle is
 *  @param color The color of the rectangle
 */
Rect rect_create(u16 x, u16 y, u16 width, u16 height, u8 thickness, CHSV color);
#define square_create(u16 x, u16 y, u16 side, u8 thickness, CHSV color) ((rect_create(x, y, side, side, thickness, color)))
