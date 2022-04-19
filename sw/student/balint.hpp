#include"timing.hpp"
#include"leds.hpp"

void balint(){
	while(1){
	for(uint8_t light = 0; light<max_light;light++){
		leds[BOTTOM_LEFT]=light;
		leds[BOTTOM_RIGHT]=light;
		delay_ms(100);
	}

	delay_ms(300);

	for(uint8_t light = 0; light<max_light;light++){
		leds[BOTTOM_LEFT]=max_light-light;
		leds[BOTTOM_RIGHT]=max_light-light;
		leds[TOP_LEFT]=light;
		leds[TOP_RIGHT]=light;
		delay_ms(100);
	}

	leds[TOP_MIDDLE]=max_light;
	}
}
