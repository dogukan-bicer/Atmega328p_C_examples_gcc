
_main:
	LDI        R27, 255
	OUT        SPL+0, R27
	LDI        R27, 0
	OUT        SPL+1, R27
	IN         R28, SPL+0
	IN         R29, SPL+1
	SBIW       R28, 11
	OUT        SPL+0, R28
	OUT        SPL+1, R29
	ADIW       R28, 1

;deney1_uygulama_4.c,1 :: 		void main() {
;deney1_uygulama_4.c,2 :: 		unsigned char dizi[]={0x00,0x81,0xC3,0xE7,0xFF,0xE7,0xC3,0x81,0x00};
	LDI        R30, #lo_addr(?ICSmain_dizi_L0+0)
	LDI        R31, hi_addr(?ICSmain_dizi_L0+0)
	MOVW       R26, R28
	ADIW       R26, 2
	LDI        R24, 9
	LDI        R25, 0
	CALL       ___CC2DW+0
;deney1_uygulama_4.c,4 :: 		DDRD = 0xFF;    // D Portu çýkýþ olarak ayarlandý
	LDI        R27, 255
	OUT        DDRD+0, R27
;deney1_uygulama_4.c,5 :: 		while (1)
L_main0:
;deney1_uygulama_4.c,7 :: 		for(i=0;i<7; i++)
	LDI        R27, 0
	STD        Y+0, R27
	STD        Y+1, R27
L_main2:
	LDD        R16, Y+0
	LDD        R17, Y+1
	CPI        R17, 0
	BRNE       L__main8
	CPI        R16, 7
L__main8:
	BRLO       L__main9
	JMP        L_main3
L__main9:
;deney1_uygulama_4.c,9 :: 		PORTD=dizi[i];
	MOVW       R18, R28
	SUBI       R18, 254
	SBCI       R19, 255
	LDD        R16, Y+0
	LDD        R17, Y+1
	MOVW       R30, R16
	ADD        R30, R18
	ADC        R31, R19
	LD         R16, Z
	OUT        PORTD+0, R16
;deney1_uygulama_4.c,10 :: 		Delay_ms (100);
	LDI        R18, 9
	LDI        R17, 30
	LDI        R16, 229
L_main5:
	DEC        R16
	BRNE       L_main5
	DEC        R17
	BRNE       L_main5
	DEC        R18
	BRNE       L_main5
	NOP
;deney1_uygulama_4.c,7 :: 		for(i=0;i<7; i++)
	LDD        R16, Y+0
	LDD        R17, Y+1
	SUBI       R16, 255
	SBCI       R17, 255
	STD        Y+0, R16
	STD        Y+1, R17
;deney1_uygulama_4.c,11 :: 		}
	JMP        L_main2
L_main3:
;deney1_uygulama_4.c,12 :: 		}
	JMP        L_main0
;deney1_uygulama_4.c,13 :: 		}
L_end_main:
L__main_end_loop:
	JMP        L__main_end_loop
; end of _main
