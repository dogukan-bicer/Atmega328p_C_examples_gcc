void main () {
   DDRD=0xEF;
   PORTD-0x0l; // D portuna Hexadecimal 0x0l (Desimal 1) deðeri yükleniyor.
while (1)
 {
while (PORTD<128) // En soldaki bit (MSB) 1 olana kadar dön (10000000 deðerine kadar)
  {
  Delay_ms (200); // 200 milisaniye gecikme
  PORTD= PORTD << 1; // D portundaki deðeri sola bir kaydýr
  }
while (PORTD>1) // En saðdaki bit (LSB) 1 olana kadar dön (00000001 deðerine kadar)
  {
     Delay_ms (200);
     PORTD= PORTD >> 1; // D portundaki deðeri saða bir kaydýr
  }
 }
}