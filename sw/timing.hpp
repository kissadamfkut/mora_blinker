#pragma once
#include<cstdint>

void wait_100ms(uint8_t);

constexpr uint8_t ms_2_iterations(const unsigned ms){
	return ms < 100 ? 1 : ms/100; //TODO something like a static_warning???
}

static inline void delay_ms(const unsigned ms){
	wait_100ms(ms_2_iterations(ms));
}
