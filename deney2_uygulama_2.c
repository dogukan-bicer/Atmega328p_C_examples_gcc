unsigned char digit[]={0x5E,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F};
sbit asagi at PINB.B4; //deðiþken E portunun 4. pinine tanýmlanýyor.
sbit yukari at PINB.B5;   //deðiþken B portunun 5. pinine tanýnlanýyor.
int sayi=0; 
void main () {
  DDRD = 0xFF; 
  DDB4_bit = 0; //PORTB_4 giriþ olarak ayarlandý
  DDB5_bit = 0; //PORTB_5 giriþ olarak ayarlandý
  PORTD=digit[0]; 
  asagi=0; 
  yukari=0;
  while (1)
  {
    if (asagi)
    {
     if (sayi>0)
     {
       sayi--;
     }
     else
      {
      sayi=15;
      }
     PORTD=digit[sayi]; 
     Delay_ms(1000);
}
if (yukari)
{
  if (sayi<16)
  {
  sayi++;
  }
  else
  {
    sayi=0;
  }
  PORTD=digit[sayi]; 
  Delay_ms(1000);
}
}
}
