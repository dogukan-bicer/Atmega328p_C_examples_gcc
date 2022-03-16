unsigned char digit[]={0x5F, 0x06,0x9B, 0x3F, 0xC6,0xCD,0xDD, 0x07,0xDF, 0xCF}; 
sbit sag at PINB.B5; //deðiþken B portunun 5. pinine tanýnlanýyor.
sbit sol at PINB.B4; //deðiþken B portunun 4. pinine tanýnlanýyor. 
unsigned int i; 
int sayi; 
void main() {
  DDB4_bit = 1; //PORTB 4 onlar basamagi seçici olarak tanýmlandý
  DDB5_bit = 1; //PORTB 5 birler basamagi seçici olarak tanýmlandý
  DDRD  = 0xFF;  // D Portu çýkýþ ölarak ayarlandý
 while(1)
  {
    sayi=0; 
    while (sayi<99)
    {
       sayi++; 
       for (i=0;i<=3000;i++)
       {
        sag=0;                  // Birler Basamaðý Seçili
        PORTD=digit[sayi%10];   // Sayýnýn 10'a bölümünden kalaný yazdýrýlýyor
        sol=1;                  // Onlar basamaðý pasif
        Delay_us(200);          // Bekleme süresinin sonuna kadar Birler basamaðý ekranda
        sol=0;                  // Onlar Basamagi Seçili
        PORTD=digit[sayi/10];   // Sayýnýn 10'a bölümü yazdýrýlýyor
        sag=1;                  // Birler basamaðý pasif
        Delay_us(200);          // Bekleme süresinin sonuna kadar Onlar basamaðý ekranda
       }
    }
   }
  }
