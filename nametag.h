
; 8048 LCD nametag
; Jeff Weisberg
; Jun. 1993

;;;; $Id: nametag.h,v 1.1 1993/07/18 21:30:16 jaw Exp jaw $
;;;; nametag board description
;;;;

#define B(x)	(1<<(x))


;;; declare port bits
	;; P1
.enum P1.LCD.ADRS = 0
.enum P1.LCD.RW
.enum P1.LCD.ENABLE
.enum P1.JUMPER0
.enum P1.LCD.DATA ; 4-7

	;; P2
;; P2.0-3 is address bus
.enum P2.LED = 4
.enum P2.PIEZO
.enum P2.JUMPER1
.enum P2.JUMPER2

	;; mode bits
.enum mode.beep = 0


	;; RAM locations
.enum clock = 0x20		; some clockage
.enum clock1, clock2, clock3
#define clockend clock3
.enum c_ptr, c_page		; ptr (offset,page) of string
.enum stack.begin		; some additional stackage

#define gp	R0	/* GP pointer */
#define sp	R1	/* stack pointer */
#define param	R2	/* GP parameter passing */
#define tmp	R3	/* tmp var */
#define mdelay	R4	/* delay register in approx millisecs */
#define mdelay4	R5	/* delay register in approx 1/4 secs */
#define modes	R6	/* dev modes */
#define p2image R7	/* P2 image */

.enum LCDC_CONTROL	= 0x80
.enum LCDC_CLS		= LCDC_CONTROL | 1
.enum LCDC_HOME		= LCDC_CONTROL | 2
.enum LCDC_ADV_REV	= LCDC_CONTROL | 4
.enum LCDC_ADV_NORM	= LCDC_CONTROL | 6
.enum LCDC_SCROLL_R	= LCDC_CONTROL | 5
.enum LCDC_SCROLL_L	= LCDC_CONTROL | 7
.enum LCDC_DISP_ON	= LCDC_CONTROL | %1100
.enum LCDC_DISP_OFF	= LCDC_CONTROL | %1000
.enum LCDC_CUR_ON	= LCDC_CONTROL | %1110
.enum LCDC_CUR_OFF	= LCDC_CONTROL | %1100
.enum LCDC_MOV_CUR_R	= LCDC_CONTROL | %10100
.enum LCDC_MOV_CUR_L	= LCDC_CONTROL | %10000
.enum LCDC_MOV_DISP_R	= LCDC_CONTROL | %11100
.enum LCDC_MOV_DISP_L	= LCDC_CONTROL | %11000

#define SET_CUR(x,y)	mov param,#($80|(x+$40*y)) call lcd_cmd
#define PUTS(x) 	mov gp, #c_ptr mov @gp,# x call lcd_puts
#define PUTCHAR(x) 	mov param, # x call lcd_char
#define CMD(x)		mov param, # x call lcd_cmd
#define WAIT(x) 	mov mdelay4, # x call lwait
#define SLEEP(x)	WAIT( (x*4) )


;;; data memory map
;
; ff : (8050)
; 7f : (8049)
; 3f : (8048)
;           |
;          RAM
; 20 :  ___/

; 1f : r'7 \
;          rb1
; 18 : r'0 /

; 17 :    \
;        stack
; 08 :    /

; 07 : r7 \
;         rb0
; 00 : r0 /



