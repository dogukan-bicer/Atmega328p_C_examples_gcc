void main () {
   DDRD=0xFF;
   PORTD=0x0l; // D portuna Hexadecimal 0x0l (Desimal 1) değeri yükleniyor.
while (1)
 {
    PORTD=0B00000011;
while (PORTD<128) // En soldaki bit (MSB) 1 olana kadar dön (10000000 değerine kadar)
  {
   Delay_ms (200); // 200 milisaniye gecikme
   PORTD= PORTD << 1; // D portundaki değeri sola bir kaydır
  }
while (PORTD>1) // En sağdaki bit (LSB) 1 olana kadar dön (00000001 değerine kadar)
  {
     Delay_ms (200);
     PORTD= PORTD >> 1; // D portundaki değeri sağa bir kaydır
  }
 }
}
