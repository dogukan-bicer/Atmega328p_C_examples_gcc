bit oncekidurum;// Onceki Durum Bayra��
void main () {
DDB4_bit = 0;// PortB 4 '� (PB4) giri� olarak ayarla
DDRD = 0xFF;
PORTD = 0xAA;// D Portu ��k�� olarak ayarland� // D portuna hexadesimal 0x55 (01010101 de�eri) y�kleniyor
oncekidurum = 0;
do{
if (Button(&PINB, 4, 1, 1)){// Lojik 1 tespiti
  oncekidurum = 1;// Bayrak g�ncellendi
  }
if (oncekidurum && Button(&PINB, 4, 1, 0)) { // Bir'den sifira ge�i� tespiti
 PORTD = ~PORTD;// D Portunu tersle
 oncekidurum= 0; // Bayrak g�ncellendi
 }
}while (1);// D�ng� bitti
}
