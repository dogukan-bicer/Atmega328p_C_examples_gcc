void ADC_ISR() org IVT_ADDR_ADC
{
  PORTD = ADCH ;
  ADCSRA |= (1 << ADSC );
}
void main ()
{
  DDRD = 0xFF; 
  SREG_I_bit = 1; // Kesmeler Aktif Ediliyor
  ADMUX = 0x60;  //ADCO giriþinden veri okunacak ADLAR=1 (bitler sola dayalý olacak) 
  ADCSRA = 0x8E ; // ADC Register ayarlanýyor 
  // ADCSRA | = (1 << ADSC ) ; 
  ADSC_bit=1; // ADC Ýþlemi baþlatýlýyor 
  while (1);
}