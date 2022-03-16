bit oncekidurum;// Onceki Durum Bayraðý
void main () {
DDB4_bit = 0;// PortB 4 'ü (PB4) giriþ olarak ayarla
DDRD = 0xFF;
PORTD = 0xAA;// D Portu çýkýþ olarak ayarlandý // D portuna hexadesimal 0x55 (01010101 deðeri) yükleniyor
oncekidurum = 0;
do{
if (Button(&PINB, 4, 1, 1)){// Lojik 1 tespiti
  oncekidurum = 1;// Bayrak güncellendi
  }
if (oncekidurum && Button(&PINB, 4, 1, 0)) { // Bir'den sifira geçiþ tespiti
 PORTD = ~PORTD;// D Portunu tersle
 oncekidurum= 0; // Bayrak güncellendi
 }
}while (1);// Döngü bitti
}
