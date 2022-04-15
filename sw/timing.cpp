#include"leds.hpp"
#include<avr/io.h>
#include<avr/interrupt.h>
#include"timing.hpp"
#include<avr/sleep.h>

namespace {
    static volatile unsigned char systick [[gnu::section(".noinit")]]; //TODO move to be a register variable

    void pwm(){
	static uint8_t tick [[gnu::section(".noinit")]];

	tick--;
	tick&=0x0f;
	if(tick==0) [[unlikely]] systick=systick+1;
	

	{
		uint8_t new_out = 0;

		for(uint8_t i = 0; i < number_of_leds; i++) 
			//if (leds[i] >  (  (tick+(3*i)) & 0x0f  )  ) new_out|=(1<<i);
			if (leds[i] > tick) new_out|=(1<<i);

		PORTB=new_out;
	}
    }

#pragma GCC push_options
#pragma GCC optimize ("no-inline") //This prevents the inharitance of the naked attribute burried under the ISR_NAKED macro
    void pwm_proxy(){
    	pwm();
    }
#pragma GCC pop_options
}

ISR(TIM0_OVF_vect, ISR_NAKED){ //NAKED is mandatory, otherwise the save of the whole register set would consume much memory (and CPU time)
	pwm_proxy();
	reti();
}

void wait_frame(const uint8_t delay){
    const auto start = systick;

    while( (systick - start) < delay );
}

void delay_iterations(uint16_t iterations){
	while(iterations--)
		wait_frame(200);
}
