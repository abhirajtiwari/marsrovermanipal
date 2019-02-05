#include <avr/io.h>
#include <util/delay.h>

int main() {
	//adc settings
	ADMUX &= ~(1 << MUX0);// the below 5 bits set the channel for adc
	ADMUX &= ~(1 << MUX1);
	ADMUX &= ~(1 << MUX2);
	ADMUX &= ~(1 << MUX3);
	ADMUX &= ~(1 << MUX4);
	ADMUX |= (1 << ADLAR); //adlar
	ADMUX = (1 << REFS0); //get the internal vcc as the reference for adc
	ADCSRA |= (1 << ADEN) | (1 << ADPS1) | (1 << ADPS0); //enable adc and set the prescaling to 8
	//ADCSRA |= (1 << ADPS2);

	//pwm settings
	DDRB = (1 << PINB3);
	PORTB = 0b00000000;
	TCCR0 |= (1 << CS00) | (1 << WGM01) | (1 << WGM00) | (1 << COM01); //TIMER 0 	no pre scaling, fast mode, oc0 enable
	TCCR0  &= ~(1 << COM00); //in non-inverting mode
	while (1) {
		ADCSRA |= (1 << ADSC);
		while(ADCSRA & (1<<ADSC));
		uint8_t l = ADCL >> 6;
		uint8_t h = ADCH << 2;
		uint16_t val = h | l;
		val = (val*255)/1023;
		OCR0 = val;
	}
}
