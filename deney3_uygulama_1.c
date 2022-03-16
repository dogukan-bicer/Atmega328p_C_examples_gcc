sbit led at PORTD.B0; // PDO led ismiyle adland�r�liyor
void main () {
  int i=0; // Sayma de�eri
  DDRD.B0=1; // PD0 ��k�� olarak ayarland� led=0;
while (1)
{
  TCNT0=-250;   // Ba�lang�� de�eri 5 olarak ayarln�yor, 250 kere saymas� i�in
  TCCR0B=0x02;  // Prescale clk/8 (16 Mhz / 8 = 2 Mhz� 1 saykil 0. 5us)
  while ( TIFR0&0x01==0);   // ta�ma bayra�� 1 olana kadar bekliyor
  i++; 
  if(i=8000)  // 1 saniye gecikme olnas� i�in 8000 kere saymas� gerekli (125*8000=10000000 us = 1 sn)
  {
  led=~led;
  i=0;
  }
  TCCR0B=0; // Say�c� s�f�rlan�yor
  TIFR0=1; // // Yaz�l�msal olarak ta�ma bayra�� s�f�rlan�yor
}
}