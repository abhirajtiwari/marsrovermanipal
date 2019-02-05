#include <avr/io.h>
#include <util/delay.h>

//This code needs hardware debouncing for the button to work correctly
//PINB1 input
//PINB2 output

int main() {
	DDRB |= (1 << PINB2);
	DDRB &= ~(1 << PINB1);
	PORTB |= (1 << PINB1); //check if this is correct what is the difference between port and pin and write the code

	while(1) {
		if(bit_is_clear(PINB, 1)) PORTB ^= (1 << PINB2);
	}
}
