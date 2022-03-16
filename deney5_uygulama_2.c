sbit okuma at PINB.B4;
void degeroku ()
{
  ADMUX = 0x67; // ADC7 giriþinden veri okunacak ADLAR=1 (bitler sola dayalý olacak)
  ADCSRA = 0x8E ; // ADC Register ayarlanýyor 
  ADSC_bit=1; // ADC Ýþlemi baþlatýlýyor 
  PORTD=ADCh;
}
void main()
{
 DDRD = 0xFF ;
 okuma=1;
while (1)
{
if (okuma==0) 
 degeroku ();
 else
 PORTD=0;
}
}