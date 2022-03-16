void main() {
unsigned char dizi[]={0x00,0x81,0xC3,0xE7,0xFF,0xE7,0xC3,0x81,0x00};
unsigned int i;
DDRD = 0xFF;    // D Portu çýkýþ olarak ayarlandý
while (1)
{
for(i=0;i<7; i++)
 {
  PORTD=dizi[i];
  Delay_ms (100);
 }
 }
}