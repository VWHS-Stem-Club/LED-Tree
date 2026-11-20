#pragma once
#include "bus.h"
#include "ints.h"

void create_tree();
void destroy_tree();
void light_led(u8 x, u8 y, CHSV color);
Bus* get_bus(u8 bus_num);
void tree_show();