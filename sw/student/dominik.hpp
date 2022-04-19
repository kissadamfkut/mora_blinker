#pragma once
#include"leds.hpp"
#include"timing.hpp"

template<uint16_t speed> void dominik(){
	for(uint8_t i=0;i<number_of_leds;i++){
		uint8_t light=0;
		for(light = 0; light<8;light++){
			leds[i]=light;
			delay_ms(speed);
		}
	}

	delay_ms(3*speed);

	for(uint8_t i=0;i<number_of_leds;i++){
		uint8_t light=0;
		for(light = 0; light<8;light++){
			leds[number_of_leds-i]=7-light;
			delay_ms(speed);
		}
	}

	delay_ms(3*speed);
	delay_ms(3*speed);
}
