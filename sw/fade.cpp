#include"timing.hpp"
#include"leds.hpp"

void fade(){
	uint8_t light;

	for(light = 0; light<(max_light*3/5);light++){
		for(int i=0;i<number_of_leds;i++)
			leds[i]=light;

		delay_ms(100);
	}

	delay_ms(300);

	while(light>0){
		light--;
		for(int i=0;i<number_of_leds;i++)
			leds[i]=light;

		delay_ms(100);
	}

	delay_ms(300);
}
