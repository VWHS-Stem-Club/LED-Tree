#include "circle.h"

Circle circle_create(u16 x, u16 y, u16 radius, f64 starting_angle, f64 ending_angle, u8 thickness, CHSV color)
{
    return (Circle){
        .x = x,
        .y = y,
        .radius = radius,
        .starting_angle = starting_angle,
        .ending_angle = ending_angle,
        .thickness = thickness,
        .color = color
    }
}
