void main() {
DDRD=0xEF; // PD4 giri� di�erleri ��k�� olarak ayarland� 
PORTD=0x00; // D portuna ilk de�er atamas� yap�l�yor
while (1)
{
  //TCNT0=1; // 1 saymas� i�in gerekli y�kleme yap�l�yor.
  TCNT0=0xFE; // 1 saymas� i�in gerekli y�kleme yap�l�yor.
  TCCR0B=0x06; // Harici osilat�r T0 (PD4) ucundan gelen d��en kenar tetikleme ayarlan�yor.
while ((TIFR0&0x01)==0);
 PORTD=PORTD+1; // D portunun de�eri 1 arttir�l�yor
 if (PORTD==16) // 15 sayd�ktan sonra s�fira d�nmesi sa�lan�yor. 
 {
 PORTD=0x00; 
 TCCR0B=0; // Say�c� s�f�rlan�yor 
 TIFR0=1; // Ta�ma bayra�� s�f�rlan�yor
 }
}
}