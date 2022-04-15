#pragma once
#include"leds.hpp"
#include"timing.hpp"

template<uint16_t period> void rotate [[noreturn]] (){
	uint8_t prev = 0;
	for(auto led = prev; true; led++){
		if(led>=number_of_leds)
			led=0;

		leds[prev]=0;
		leds[led]=10;
		prev=led;
		delay_ms(period);
	}
}
