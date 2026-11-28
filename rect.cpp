#include "rect.h"

Rect rect_create(u16 x, u16 y, u16 width, u16 height, u8 thickness, CHSV color)
{
    return (Rect){
        .x = x,
        .y = y,
        .width = width,
        .height = height,
        .thickness = thickness,
        .color = color
    }
}
