void main() {
	DDRD=0xFF;
	PORTD=0x00;
	while (1)
	{
	// D Portunun tamamý çýkýþ olarak ayarlanýyor. // D Portuna Hexadecimal 0x00 (Desimal 0) deðeri yükleniyor.
	if(PORTD<256)
	{
	    // Portun deðeri alabileceði en yüksek deðere kadar sayacak
	    PORTD++; // Portun deðeri 1 arttirýliyor.
	    Delay_ms(500); // 500 milisaniyelik gecikme
	}
	else
	{
	    PORTD=0x00; // Sayma bitiminde tekrar 0 yükleniyor.
	}
} // while'in parantezi
}// main'in parantezi


