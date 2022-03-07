#include<avr/io.h>


int main (void)
{
  DDRB |= 0B000110;//d9 d10
TCCR1A = 0;// TCCR1A 0
TCCR1B = 0;// TCCR1B 0
TCCR1A |=(1<<WGM11) |(1<<COM1A1)|(1<<COM1B1);
TCCR1B |=(1<<CS10) |(1<<WGM12)|(1<<WGM13);//fast pwm mode

 while (1)
 {
	 ICR1=7;//8MHZ =1 2mhz=7
 }
}
