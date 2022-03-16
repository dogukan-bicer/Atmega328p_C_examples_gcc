void harici0_ISR() org IVT_ADDR_INT0 // Harici kesme 0 tanýmlanmasý
{
PORTB=~PORTB;   // Kesme geldiðinde B portu tersleniyor
}
void main()
{
DDRB = 0xFF;
PORTB = 0x00; 
SREG_I_bit = 1;   // Kesmeler aktif ediliyor
EICRA=0x02;       // INTO ucu düþen kenar tetiklemesi aktif ediliyor
EIMSK=0x01;       // INTO ucu aktif ediliyor
while (1);        // Sonsuz Döngü, Kesme gelene kadar sürekli döner
}

