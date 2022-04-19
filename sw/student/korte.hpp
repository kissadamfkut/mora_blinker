#pragma once
#include"leds.hpp"
#include"timing.hpp"

void korte(){
	for(uint8_t i = min_light; i<=max_light; i+=2){
		leds[BOTTOM_LEFT] = i;
		leds[BOTTOM_RIGHT] = i;
		leds[TOP_LEFT] = max_light - i;
		leds[TOP_RIGHT] = max_light - i;

		delay_ms(1000);
	}

	leds[TOP_MIDDLE] = max_light;

	return;
/*
	for(uint8_t i = min_light; i<=max_light; i+=2){
		delay_ms(1000);

		leds[BOTTOM_LEFT] = leds[BOTTOM_RIGHT] = max_light - i;
		leds[TOP_LEFT] = leds[TOP_RIGHT] = i;

	}
	*/

}
