unsigned char digit[]={0x5F, 0x06,0x9B, 0x3F, 0xC6,0xCD,0xDD, 0x07,0xDF, 0xCF}; 
sbit sag at PINB.B5; //de�i�ken B portunun 5. pinine tan�nlan�yor.
sbit sol at PINB.B4; //de�i�ken B portunun 4. pinine tan�nlan�yor. 
unsigned int i; 
int sayi; 
void main() {
  DDB4_bit = 1; //PORTB 4 onlar basamagi se�ici olarak tan�mland�
  DDB5_bit = 1; //PORTB 5 birler basamagi se�ici olarak tan�mland�
  DDRD  = 0xFF;  // D Portu ��k�� �larak ayarland�
 while(1)
  {
    sayi=0; 
    while (sayi<99)
    {
       sayi++; 
       for (i=0;i<=3000;i++)
       {
        sag=0;                  // Birler Basama�� Se�ili
        PORTD=digit[sayi%10];   // Say�n�n 10'a b�l�m�nden kalan� yazd�r�l�yor
        sol=1;                  // Onlar basama�� pasif
        Delay_us(200);          // Bekleme s�resinin sonuna kadar Birler basama�� ekranda
        sol=0;                  // Onlar Basamagi Se�ili
        PORTD=digit[sayi/10];   // Say�n�n 10'a b�l�m� yazd�r�l�yor
        sag=1;                  // Birler basama�� pasif
        Delay_us(200);          // Bekleme s�resinin sonuna kadar Onlar basama�� ekranda
       }
    }
   }
  }
