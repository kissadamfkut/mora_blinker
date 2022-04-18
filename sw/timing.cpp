#include"leds.hpp"
#include<avr/io.h>
#include<avr/interrupt.h>
#include"timing.hpp"
#include<avr/sleep.h>

namespace {
    register uint8_t tick asm("r2");
    register uint8_t systick asm("r3");

    constexpr const bool multiphase_pwm = true;

    void wait_frame(uint8_t delay){
        delay += systick;
        do{
		asm volatile("":"=r" (systick));
	}while( systick != delay );
    }

}

ISR(TIM0_OVF_vect){
	tick--;
	tick&=0x0f;
	if(tick==0) [[unlikely]] systick++;

	{
		uint8_t new_out = 0;

		for(uint8_t i = 0; i < number_of_leds; i++) {
			if constexpr (multiphase_pwm){
				if (leds[i] >  (  (tick+(3*i)) & 0x0f  )  ) new_out|=(1<<i);
			}
			else{
				if (leds[i] > tick) new_out|=(1<<i);
			}
		}

		PORTB=new_out;
	}
}


void wait_100ms(uint8_t iterations){
	while(iterations--)
		wait_frame(6);
}
