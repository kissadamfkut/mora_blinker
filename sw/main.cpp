#include <avr/io.h>
#include "leds.hpp"
#include <avr/interrupt.h>
#include "timing.hpp"

#include "onoff.hpp"
#include "powerdown.hpp"
#include "fade.hpp"
#include "rotate.hpp"

#include <array>
#include <eeprom_var.hpp>

std::array<volatile uint8_t, number_of_leds> leds = {0};

[[noreturn]] static inline void program(){
	static const avr::eeprom_array anim [[gnu::section(".eeprom")]] = {fade, onoff<1000>, onoff<500>, rotate<1000>, powerdown};

	static volatile uint8_t anim_index [[gnu::section(".noinit")]];
	anim_index = (anim.size()-1) <= anim_index ? 0 : anim_index+1;

	const decltype(anim)::value_type act_anim = anim[anim_index];
label:
	act_anim();
	goto label;
}

static inline void hwinit(){
	TCCR0B=(1<<CS00);
	TIMSK0=(1<<TOIE0);
	DDRB=0b00011111; //PB0 -- PB4
	sei();
}

int main (){
	hwinit();
	delay_ms(100); //Debouncing the reset button
	program();
}

