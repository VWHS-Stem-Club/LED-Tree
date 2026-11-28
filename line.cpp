#include "line.h"

Line line_create(u16 x1, u16 y1, u16 x2, u16 y2, u8 thickness, CHSV color)
{
    return (Line){
        .x1 = x1,
        .y1 = y1,
        .x2 = x2,
        .y2 = y2,
        .thickness = thickness,
        .color = color
    };
}
