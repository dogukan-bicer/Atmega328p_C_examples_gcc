const char asmadegeri0 = 300; 
const char asmadegeril = 30;
char sayicil;
char sayici3;
void Timer0kesmesi_ISR() org IVT_ADDR_TIMER0_OVF // Timer0 Kesmesi tanýmlanýyor
{
   if (sayicil >= asmadegeri0)
   {
      PORTC.B4 = ~PORTC.B4; 
      sayicil = 0;
   }
   else
     sayicil++;
}
void Timer1kesmesi_ISR() org IVT_ADDR_TIMER1_OVF // Timerl kesmesi tanýmlanýyor
{
if (sayici3 >= asmadegeril) {
  PORTC.B5 = ~PORTC.B5; 
  sayici3 = 0;
  }
else
  sayici3++;
}
void main()
{
  DDRC.B4 - 1;
  DDRD=0XFF; 
  DDRC.B5=1; 
  PORTC.B4 = 0; 
  PORTC.B5 = 0; 
  PORTD = 0X00; 
  SREG_I_bit = 1; // Kesmeler Aktif
  TIMSK0=0x01;    // Timerü aþým kesmesi aktif
  // TOIEO_bit=1;
  TIMSK1=0x01;   // Timeri aþým kesmesi aktif
  // TOIE1_bit=1; 
  TCCR0B=0x02;   // Timer0 prescale clk /8… 256 kere sayma baþlýyor
  TCCR1B=2;      // Timeri prescale clk /8… 65536 kere sayma baþlýyor
  while (1)
 {
PORTD=PORTD+1; 
if(PORTD==16)
PORTD=0x00; 
delay_ms (1000);
 }
}