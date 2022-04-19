#pragma once
#include"leds.hpp"
#include"timing.hpp"

void alma(){
	uint8_t i=0;

	while(i<5){
		leds[i]=16;
		delay_ms(1000);

		i++;
	}
	i=5;
	do{
		i--;
		leds[i]=0;
		delay_ms(1000);
	} while(i!=0);
}
