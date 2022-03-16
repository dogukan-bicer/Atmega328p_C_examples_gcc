void ADC_ISR() org IVT_ADDR_ADC
{
  PORTD = ADCH ;
  ADCSRA |= (1 << ADSC );
}
void main ()
{
  DDRD = 0xFF; 
  SREG_I_bit = 1; // Kesmeler Aktif Ediliyor
  ADMUX = 0x60;  //ADCO giri�inden veri okunacak ADLAR=1 (bitler sola dayal� olacak) 
  ADCSRA = 0x8E ; // ADC Register ayarlan�yor 
  // ADCSRA | = (1 << ADSC ) ; 
  ADSC_bit=1; // ADC ��lemi ba�lat�l�yor 
  while (1);
}