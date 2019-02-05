#include <avr/io.h>
#include <util/delay.h>

int main() {
	DDRB |= (1 << PINB1);
	
	while(1) {
		PORTB ^= 0b00000010;
		_delay_ms(100);
	}

}
