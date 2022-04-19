#include"timing.hpp"
#include"leds.hpp"

void bence(){
	uint8_t light;

	leds[BOTTOM_LEFT]=4; // bal átló kezdete
	delay_ms(500);
	leds[BOTTOM_LEFT]=0;
	leds[TOP_RIGHT]=4;
	delay_ms(500);
	leds[TOP_RIGHT]=0;
	delay_ms(250);
	leds[BOTTOM_LEFT]=8;
	leds[TOP_RIGHT]=8;
	delay_ms(500);
	leds[BOTTOM_LEFT]=0;
	leds[TOP_RIGHT]=0;
	delay_ms(250); // bal átló vége
	leds[BOTTOM_RIGHT]=4; // jobb átló kezdete
	delay_ms(500);
	leds[BOTTOM_RIGHT]=0;
	leds[TOP_LEFT]=4;
	delay_ms(250);
	leds[BOTTOM_RIGHT]=8;
	leds[TOP_LEFT]=8;
	delay_ms(500);
	leds[BOTTOM_RIGHT]=0;
	leds[TOP_LEFT]=0;
	delay_ms(250); // jobb átló vége
	leds[TOP_MIDDLE]=4; // TOP middle solo
	delay_ms(500);
	leds[TOP_MIDDLE]=0;
	delay_ms(250);
	leds[TOP_MIDDLE]=8;
	delay_ms(500);
	leds[TOP_MIDDLE]=0;
	delay_ms(250); // és most mindenki
	leds[TOP_LEFT]=4;
	leds[TOP_MIDDLE]=4;
	leds[TOP_RIGHT]=4;
	leds[BOTTOM_LEFT]=4;
	leds[BOTTOM_RIGHT]=4;
	delay_ms(500);
	leds[TOP_LEFT]=0;
	leds[TOP_MIDDLE]=8;
	leds[TOP_RIGHT]=0;
	leds[BOTTOM_LEFT]=0;
	leds[BOTTOM_RIGHT]=0;
	delay_ms(250);
	leds[TOP_MIDDLE]=0;
	delay_ms(250);
	leds[TOP_LEFT]=8;
	leds[TOP_MIDDLE]=8;
	leds[TOP_RIGHT]=8;
	leds[BOTTOM_LEFT]=8;
	leds[BOTTOM_RIGHT]=8;
	delay_ms(500);
	leds[TOP_LEFT]=0;
	leds[TOP_MIDDLE]=0;
	leds[TOP_RIGHT]=0;
	leds[BOTTOM_LEFT]=0;
	leds[BOTTOM_RIGHT]=0;
	delay_ms(250);
	leds[TOP_LEFT]=16;
	leds[TOP_MIDDLE]=16;
	leds[TOP_RIGHT]=16;
	leds[BOTTOM_LEFT]=16;
	leds[BOTTOM_RIGHT]=16;




	for(light = 0; light<max_light;light++){
		leds[BOTTOM_LEFT]=light;
		leds[BOTTOM_RIGHT]=light;
		delay_ms(100);
	}

	delay_ms(300);

	for(light = 0; light<max_light;light++){
		leds[BOTTOM_LEFT]=max_light-light;
		leds[BOTTOM_RIGHT]=max_light-light;
		leds[TOP_LEFT]=light;
		leds[TOP_RIGHT]=light;
		delay_ms(100);
	}

	leds[TOP_MIDDLE]=max_light;

	while(true);
}
