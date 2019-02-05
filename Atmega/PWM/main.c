#include <avr/io.h>
#include <util/delay.h>

//PINB3 led pwm timer0

int main() {
	DDRB = (1 << PINB3);
	PORTB = 0b00000000;
	TCCR0 |= (1 << CS00) | (1 << WGM01) | (1 << WGM00) | (1 << COM01); //TIMER 0 	no pre scaling, fast mode, oc0 enable
	TCCR0  &= ~(1 << COM00); //in non-inverting mode
	while(1) {
		for (int i=0; i<256; ++i) {
			OCR0 = i;
			_delay_ms(5);
		}
		for(int i = 255; i>=0; --i) {
			OCR0 = i;
			_delay_ms(5);
		}
	}
}
