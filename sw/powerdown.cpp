#include"powerdown.hpp"
#include<avr/sleep.h>
#include<avr/interrupt.h>
#include<avr/io.h>

void powerdown [[noreturn]](){
	cli(); //No more interrupts
	PORTB=0; //Turn off all the leds, disable pull-ups
	DDRB=0; //Switch every pin to high Z
	TCCR0B=0; //Stop the timer
	set_sleep_mode(SLEEP_MODE_PWR_DOWN); //Settig the mode of sleep for total power down
	sleep_mode(); //Shutting down the whole setup, until reset button is pressed
	__builtin_unreachable(); //Hint the compiler that this code won't ever be reached 
}

/* if _exit would be weak function....
extern "C" void _exit(){
	powerdown();
}*/
