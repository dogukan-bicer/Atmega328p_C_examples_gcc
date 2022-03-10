
void delay_ms(int delay)
     {
     	for(;delay>0;delay--)
	{
	int i;
	for(i=0; i< 1000;i++)
	{}
	}
     }

void main() {

	DDRB |= (1<<DDB5);
    while (1)
    {
	PORTB ^= (1<<PORTB5);
	delay_ms(1000);
	PORTB &= ~ (1<<PORTB5);
	delay_ms(1000);
//	PORTB ^= 0B100000;
    }

}
