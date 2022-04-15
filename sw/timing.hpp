#pragma once
#include<cstdint>

void delay_iterations(const uint16_t);
void wait_frame(const uint8_t delay);

constexpr uint16_t ms_2_iterations(const uint16_t ms){
	return ms/4;
}

static inline void delay_ms(const uint16_t ms){
	delay_iterations(ms_2_iterations(ms));
}
