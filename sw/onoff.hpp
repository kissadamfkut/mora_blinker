#pragma once
#include"leds.hpp"
#include"timing.hpp"

template<uint16_t period> void onoff(){
		for (int i=0;i<number_of_leds;i++)
			leds[i]=max_light;
		delay_ms(period/2);

		for (int i=0;i<number_of_leds;i++)
			leds[i]=min_light;
		delay_ms(period/2);
}
