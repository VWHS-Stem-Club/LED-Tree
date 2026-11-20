#pragma once
#include "bus.h"
#include "ints.h"

/**
 * @brief Sets global FastLED configuration & initializes LEDs
 */
void create_tree();

/**
 * @brief Destroys LEDs & Invalidates Tree
 */
void destroy_tree();

/**
 *  @brief Sets the global brightness (scalar value that all colors are mulitplied by) of the tree
 *  @param brightness The new brightness, 0 meaning off, 255 meaning max brightness
 */
void tree_set_brightness(u8 brightness);

/**
 *
 *  @brief Returns the current global brightness
 *  @return The current global brightness
 */
u8 tree_get_brightness();

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
 * @brief Lights an entire row of pixels at the specified y coordinate with the specified color.
 * @param y The y-coordinate of the LED.
 * @param color The color to set the LED to.
 */
void light_row(u8 y, CHSV color);

/**
 * @brief Lights an entire column of pixels at the specified x coordinate with the specified color.
 * @param x The x-coordinate of the LED.
 * @param color The color to set the LED to.
 */
void light_column(u8 x, CHSV color);

/**
 *  @brief Fills the entire tree with the specified color.
 *  @param color The color to set the LED to.
 */
void light_tree(CHSV color);
      
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

/**
 * @brief Sets the background color of the tree.
 * @param color The color to set as the background.
 */
void set_background_color(CHSV color);
