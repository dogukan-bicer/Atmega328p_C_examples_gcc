/*
 * TIMER_INTERRUPT_C.c
 *
 * Created: 7.03.2022 22:48:27
 * Author : dogukan 1mhz
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
DDRB |= 0B100000;
// TIMER 2 for interrupt frequency 1000000 Hz:
cli(); // stop interrupts
TCCR2A = 0; // set entire TCCR2A register to 0
TCCR2B = 0; // same for TCCR2B
TCNT2  = 0; // initialize counter value to 0
// set compare match register for 1000000 Hz increments
OCR2A = 15; // = 16000000 / (1 * 1000000) - 1 (must be <256)
// turn on CTC mode
TCCR2B |= (1 << WGM21);
// Set CS22, CS21 and CS20 bits for 1 prescaler
TCCR2B |= (0 << CS22) | (0 << CS21) | (1 << CS20);
// enable timer compare interrupt
TIMSK2 |= (1 << OCIE2A);
sei(); // allow interrupts



	while (1)
	{
	}
}

ISR(TIMER2_COMPA_vect){
	PORTB ^= 0B100000; 
}
