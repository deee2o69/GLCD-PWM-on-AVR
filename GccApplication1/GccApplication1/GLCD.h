/*
 * GLCD.h
 *
 * Created: 05-Mar-24 14:12:15
 *  Author: diaag
 */ 


#ifndef GLCD_H_
#define GLCD_H_


#define LOWVOLT		(0b10000000)
#define HIGHVOLT	(0b00000001)
#define CHANGEVOLT	(0b11111111)
#define ZEROVOLT	(0b00010000)



extern void GLCD_Command(char Command);		/* GLCD command function */
extern void GLCD_Data(char Data)	;	/* GLCD data function */
extern void GLCD_Init()		;	/* GLCD initialize function */
extern void GLCD_PrintChar(char x,uint8_t row,uint8_t col);
extern void Print_String(char* x,uint8_t row);
extern void GLCD_ClearAll()		; /* GLCD all display clear function */
extern inline void SELECTBOTH();
extern inline void SELECTFIRST();
extern inline void SELECTSECOND();





#endif /* GLCD_H_ */