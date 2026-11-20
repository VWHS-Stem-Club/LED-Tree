#pragma once
#include "bus.h"
#include "ints.h"

/**
 * @brief Sets brightness and initializes the busses.
 */
void create_tree();

/**
 * @brief Destroys the busses and resets the tree struct.
 */
void destroy_tree();

/**
 * @brief Lights an LED at a specific position with a given color.
 * @param x The x-coordinate of the LED.
 * @param y The y-coordinate of the LED.
 * @param color The color to set the LED to.
 * 
 * @note This assumes the LEDs are arranged in a 2D grid with strands being x coordinates.
 */
void light_led(u8 x, u8 y, CHSV color);

/**
 * @brief Gets a pointer to a specific bus.
 * @param bus_num The index of the bus to retrieve.
 * @return A pointer to the requested bus.
 */
Bus* get_bus(u8 bus_num);

/**
 * @brief Displays the current state of the tree.
 */
void tree_show();