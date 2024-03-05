/*
 * GLCD.c
 *
 * Created: 05-Mar-24 14:11:52
 *  Author: diaag
 */ 

#include <stdint-gcc.h>
#ifndef F_CPU
#define F_CPU 8000000UL
#endif
#include <util/delay.h>

#include "Dio.h"
#include "GLCD_cfg.h"
#include "GLCD.h"

 void SELECTBOTH()	{Dio_Write_channel(CS1,!STD_HIGH) ;Dio_Write_channel(CS2,!STD_HIGH)		   ;  }
 void SELECTFIRST()	{Dio_Write_channel(CS1,!STD_HIGH) ;Dio_Write_channel(CS2,!STD_LOW)		   ;  }
 void SELECTSECOND()	{Dio_Write_channel(CS1,!STD_LOW) ;Dio_Write_channel(CS2,!STD_HIGH)		   ;  }


void GLCD_Command(char Command)		/* GLCD command function */
{
	Dio_Write_channel_group(dataport,8,Command);		/* Copy command on data pin */
	Dio_Write_channel(RS,STD_LOW) ;						/* Make RS LOW for command register*/
	Dio_Write_channel(RW,STD_LOW) ;						/* Make RW LOW for write operation */
	Dio_Write_channel(EN,STD_HIGH); 					/* Make HIGH-LOW transition on Enable */
	_delay_us(5);
	Dio_Write_channel(EN,STD_LOW);
	_delay_us(5);
}

void GLCD_Data(char Data)		/* GLCD data function */
{
	Dio_Write_channel_group(dataport,8,Data);		/* Copy command on data pin */
	Dio_Write_channel(RS,STD_HIGH) ;						/* Make RS LOW for command register*/
	Dio_Write_channel(RW,STD_LOW) ;						/* Make RW LOW for write operation */
	Dio_Write_channel(EN,STD_HIGH); 					/* Make HIGH-LOW transition on Enable */
	_delay_us(5);
	Dio_Write_channel(EN,STD_LOW);
	_delay_us(5);
}

void GLCD_Init()			/* GLCD initialize function */
{
	Dio_dir dataportdir[] ={STD_OUTPUT,STD_OUTPUT,STD_OUTPUT,STD_OUTPUT,STD_OUTPUT,STD_OUTPUT,STD_OUTPUT,STD_OUTPUT};
	Dio_init_channel_group(dataport,	8,	dataportdir);

	
	Dio_dir cmddir[] ={STD_OUTPUT,STD_OUTPUT,STD_OUTPUT,STD_OUTPUT,STD_OUTPUT,STD_OUTPUT};
	Dio_init_channel_group(cmd,	6,	cmddir);

	/* Select both left & right half of display & Keep reset pin high */
	SELECTBOTH();
	Dio_Write_channel(RST,STD_HIGH) ;
	
	_delay_ms(20);
	GLCD_Command(0x3E);		/* Display OFF */
	GLCD_Command(0x40);		/* Set Y address (column=0) */
	GLCD_Command(0xB8);		/* Set x address (page=0) */
	GLCD_Command(0xC0);		/* Set z address (start line=0) */
	GLCD_Command(0x3F);		/* Display ON */
}
void GLCD_PrintChar(char x,uint8_t row,uint8_t col)
{
	int i = col ;
	for(i = col; i < 5+col; i++)
	{
		if (64==i) {
			SELECTSECOND();
			GLCD_Command(0x40);		/* Set Y address (column=0) */
			GLCD_Command(0xB8+row);
		}
		GLCD_Data(font[x][i-col]);
	}
}
void Print_String(char* x,uint8_t row)
{
	int i = 0,col =0;
	SELECTFIRST();
	GLCD_Command(0x40);
	GLCD_Command((0xB8) + row);
	
	while (x[i])
	{
		GLCD_PrintChar(x[i],row,col);
		i++; col+=5;
	}
}
void GLCD_ClearAll()			/* GLCD all display clear function */
{
	int i,j;

	SELECTBOTH();
	for(i = 0; i < 8; i++)
	{
		
		GLCD_Command(0x40);
		GLCD_Command((0xB8) + i);

		for(j = 0; j < 64 ; j++)
		{
			GLCD_Data(0);	/* Write zeros to all 64 column */
			//delay_us(5000);
		}
	}
	GLCD_Command(0x40);		/* Set Y address (column=0) */
	GLCD_Command(0xB8);		/* Set x address (page=0) */


}
