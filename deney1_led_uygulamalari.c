void main() {
	DDRD=0xFF;
	PORTD=0x00;
	while (1)
	{
	// D Portunun tamam� ��k�� olarak ayarlan�yor. // D Portuna Hexadecimal 0x00 (Desimal 0) de�eri y�kleniyor.
	if(PORTD<256)
	{
	    // Portun de�eri alabilece�i en y�ksek de�ere kadar sayacak
	    PORTD++; // Portun de�eri 1 arttir�liyor.
	    Delay_ms(500); // 500 milisaniyelik gecikme
	}
	else
	{
	    PORTD=0x00; // Sayma bitiminde tekrar 0 y�kleniyor.
	}
} // while'in parantezi
}// main'in parantezi


