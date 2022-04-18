blink.elf: $(wildcard *.cpp)
	avr-gcc -Wall -Wextra -g -ffixed-2 -ffixed-3 -Os -I libavrpp/include -isystem avr-libstdcpp/include -mmcu=attiny13a -std=c++20 -o $@ $^

.PHONY: program size clean reset

all: blink.elf

clean:
	rm -rf *o *elf

size: blink.elf
	avr-size --mcu=attiny13 -C $<

program: blink.elf
	avrdude -p attiny13 -c stk500v2 -U flash:w:$<:e -P /dev/ttyUSB0 -B100000 -U lfuse:w:$<:e -U hfuse:w:$<:e -U eeprom:w:$<:e

reset:
	avrdude -p attiny13 -c stk500v2 -P /dev/ttyUSB0 -B100000 
