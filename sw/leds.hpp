#pragma once

#include <cstdint>
#include <array>

constexpr const static uint8_t number_of_leds = 5;
extern std::array<volatile uint8_t, number_of_leds> leds;

constexpr const static uint8_t max_light = 16;
constexpr const static uint8_t min_light = 0;

enum leds{
	BOTTOM_LEFT=0,
	TOP_LEFT=1,
	TOP_MIDDLE=2,
	TOP_RIGHT=3,
	BOTTOM_RIGHT=4,
};
