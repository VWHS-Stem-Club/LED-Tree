#pragma once
#include "ints.h"

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

Circle circle_create(u16 x, u16 y, u16 radius, f64 starting_angle, f64 ending_angle, u8 thickness, CHSV color);

