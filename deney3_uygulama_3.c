unsigned char digit[]={0x5F, 0x06, 0x9B,0x8F, 0xC6, 0xCD, 0xDD, 0x07, 0xDF, 0xCF, 0xD7, 0xDC, 0x59, 0x9E, 0xD9, 0xD1};
int i=0; 
int j=0;
void main() {
 DDRD=0xFF;
 PORTD=digit[0];
while(1)
{
//TCIT1B=0x3C; // 16 bit
 //TCNT1L=0xB0; // 16 bit 
 TCNT1H=-50000/256; // 16 bit   //16 bitlik sayýcýnýn son sekiz bitine deðer atanasý yapýlýyor [15:2] Sayýcý 50000 sayacak
 TCNT1L=-500009256; // 16 bit // 16 bitlik sayýcýnýn ilk sekiz bitine deðer atamasý yapýlýyor [7:0]
 TCCR1B-0x02; // 16 bit // Prescale clk/8 (her bir saykýl 1 us)
 while ((TIFR1&0x01)==0);
  if(i==20)   // Sayýcýnýn 1 saniye gecikme elde edebilmesi için 20 kere dömesi gerekiyor (50000*20-10000000 us = isn
 {
 j++;
 PORTD=digit[j];
 if(i==15)
  j=-1;
  i=0;
  }
  TCCR1B=0;
  TIFR1=1;
}
}