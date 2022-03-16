void main() {
DDRD=0xEF; // PD4 giriþ diðerleri çýkýþ olarak ayarlandý 
PORTD=0x00; // D portuna ilk deðer atamasý yapýlýyor
while (1)
{
  //TCNT0=1; // 1 saymasý için gerekli yükleme yapýlýyor.
  TCNT0=0xFE; // 1 saymasý için gerekli yükleme yapýlýyor.
  TCCR0B=0x06; // Harici osilatör T0 (PD4) ucundan gelen düþen kenar tetikleme ayarlanýyor.
while ((TIFR0&0x01)==0);
 PORTD=PORTD+1; // D portunun deðeri 1 arttirýlýyor
 if (PORTD==16) // 15 saydýktan sonra sýfira dönmesi saðlanýyor. 
 {
 PORTD=0x00; 
 TCCR0B=0; // Sayýcý sýfýrlanýyor 
 TIFR0=1; // Taþma bayraðý sýfýrlanýyor
 }
}
}