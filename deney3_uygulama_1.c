sbit led at PORTD.B0; // PDO led ismiyle adlandýrýliyor
void main () {
  int i=0; // Sayma deðeri
  DDRD.B0=1; // PD0 çýkýþ olarak ayarlandý led=0;
while (1)
{
  TCNT0=-250;   // Baþlangýç deðeri 5 olarak ayarlnýyor, 250 kere saymasý için
  TCCR0B=0x02;  // Prescale clk/8 (16 Mhz / 8 = 2 Mhz… 1 saykil 0. 5us)
  while ( TIFR0&0x01==0);   // taþma bayraðý 1 olana kadar bekliyor
  i++; 
  if(i=8000)  // 1 saniye gecikme olnasý için 8000 kere saymasý gerekli (125*8000=10000000 us = 1 sn)
  {
  led=~led;
  i=0;
  }
  TCCR0B=0; // Sayýcý sýfýrlanýyor
  TIFR0=1; // // Yazýlýmsal olarak taþma bayraðý sýfýrlanýyor
}
}