#pragma once
#include<avr/interrupt.h>

struct flicker_guard{
	 flicker_guard(){ cli(); }
	~flicker_guard(){ sei(); }
};
