#include <avr/io.h>
#include <util/delay.h>

//PIND7 is input
//PINB3 is output

int debounce(int last, int pin) {
	// this function only works on the portd for other ports rewrite the function to support it
	int current = bit_is_clear(PIND, pin);
	if(current != last) {
		_delay_ms(10);
		current = bit_is_clear(PIND, pin);
	}
	return current;
}

int main() {
	DDRB |= (1 << PINB3);
	DDRD &= ~(1 << PIND7);
	PORTD |= (1 << PIND7); //enable internal pull-up resistor

	int lastButton = 0;
	int currentButton;

	while(1) {
		currentButton = debounce(lastButton, 7);
		if(currentButton == 0 && lastButton != 0) PORTB ^= (1 << PINB3);
		lastButton = currentButton;
	}
}
