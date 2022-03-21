sbit led at PORTD.B0; // PDO led ismiyle adlandırıliyor
void main () {
  int i=0; // Sayma değeri
  DDRD.B0=1; // PD0 çıkış olarak ayarlandı 
  led=0;
while (1)
{
  TCNT0=-250;   // Başlangıç değeri 5 olarak ayarlnıyor, 250 kere sayması için
  TCCR0B=0x02;  // Prescale clk/8 (16 Mhz / 8 = 2 Mhz… 1 saykil 0. 5us)
  while ( TIFR0&0x01==0);   // taşma bayrağı 1 olana kadar bekliyor
  i++; 
  if(i==40000)  // 1 saniye gecikme olnası için 8000 kere sayması gerekli (125*8000=10000000 us = 1 sn)
  {
  led=~led;
  i=0;
  }
  TCCR0B=0; // Sayıcı sıfırlanıyor
  TIFR0=1; // // Yazılımsal olarak taşma bayrağı sıfırlanıyor
}
}
