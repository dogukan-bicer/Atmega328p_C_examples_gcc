void harici1_ISR() org IVT_ADDR_INT1 // Harici i kesmesi tan�mlan�yor
{
  if(PORTB==0x80)
  PORTB=0x10;
  else
  PORTB=PORTB<<1;
}
void main()
{
 DDRB = 0xFF;
 PORTB = 0x10; // PORTB = 00010000 de�eri y�kleniyor 
 SREG_I_bit = 1; // Kesmeler Aktif
 EICRA=0x08; // INTi kesmesi y�kselen kenar tetiklemeli aktif ediliyor 
 EIMSK=0x02; // INT1 ucu (PD1) aktif ediliyor
while (1);// Sonsuz D�ng� (Kesme bekleniyor)
}