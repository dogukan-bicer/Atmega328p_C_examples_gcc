
_main:
	LDI        R27, 255
	OUT        SPL+0, R27
	LDI        R27, 0
	OUT        SPL+1, R27

;deney1_led_uygulamalari.c,1 :: 		void main() {
;deney1_led_uygulamalari.c,2 :: 		DDRD=0xFF;
	LDI        R27, 255
	OUT        DDRD+0, R27
;deney1_led_uygulamalari.c,3 :: 		PORTD=0x00;
	LDI        R27, 0
	OUT        PORTD+0, R27
;deney1_led_uygulamalari.c,4 :: 		while (1)
L_main0:
;deney1_led_uygulamalari.c,7 :: 		if(PORTD<256)
	IN         R16, PORTD+0
	MOV        R18, R16
	LDI        R19, 0
	LDI        R16, 0
	LDI        R17, 1
	CP         R18, R16
	CPC        R19, R17
	BRLT       L__main7
	JMP        L_main2
L__main7:
;deney1_led_uygulamalari.c,10 :: 		PORTD++; // Portun deðeri 1 arttirýliyor.
	IN         R16, PORTD+0
	SUBI       R16, 255
	OUT        PORTD+0, R16
;deney1_led_uygulamalari.c,11 :: 		Delay_ms(500); // 500 milisaniyelik gecikme
	LDI        R18, 41
	LDI        R17, 150
	LDI        R16, 128
L_main3:
	DEC        R16
	BRNE       L_main3
	DEC        R17
	BRNE       L_main3
	DEC        R18
	BRNE       L_main3
;deney1_led_uygulamalari.c,12 :: 		}
	JMP        L_main5
L_main2:
;deney1_led_uygulamalari.c,15 :: 		PORTD=0x00; // Sayma bitiminde tekrar 0 yükleniyor.
	LDI        R27, 0
	OUT        PORTD+0, R27
;deney1_led_uygulamalari.c,16 :: 		}
L_main5:
;deney1_led_uygulamalari.c,17 :: 		} // while'in parantezi
	JMP        L_main0
;deney1_led_uygulamalari.c,18 :: 		}// main'in parantezi
L_end_main:
L__main_end_loop:
	JMP        L__main_end_loop
; end of _main
