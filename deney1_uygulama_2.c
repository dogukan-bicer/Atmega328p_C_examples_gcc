void main () {
   DDRD=0xEF;
   PORTD-0x0l; // D portuna Hexadecimal 0x0l (Desimal 1) de�eri y�kleniyor.
while (1)
 {
while (PORTD<128) // En soldaki bit (MSB) 1 olana kadar d�n (10000000 de�erine kadar)
  {
  Delay_ms (200); // 200 milisaniye gecikme
  PORTD= PORTD << 1; // D portundaki de�eri sola bir kayd�r
  }
while (PORTD>1) // En sa�daki bit (LSB) 1 olana kadar d�n (00000001 de�erine kadar)
  {
     Delay_ms (200);
     PORTD= PORTD >> 1; // D portundaki de�eri sa�a bir kayd�r
  }
 }
}