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

#include "MCAL/DIO/Dio.h"
#include "GLCD_cfg.h"
#include "GLCD.h"

void SELECTBOTH()   { Dio_WriteChannel(CS1, DIO_LOW); Dio_WriteChannel(CS2, DIO_LOW); }

void SELECTFIRST()  { Dio_WriteChannel(CS1, DIO_LOW); Dio_WriteChannel(CS2, DIO_HIGH); }

void SELECTSECOND() { Dio_WriteChannel(CS1, DIO_HIGH); Dio_WriteChannel(CS2, DIO_LOW); }



void GLCD_Command(char Command)
{
	Dio_WriteChannelGroup(dataPort, 8, Command);    /* Copy command on data Pin */
	Dio_WriteChannel(RS, DIO_LOW);                  /* Make RS LOW for command register */
	Dio_WriteChannel(RW, DIO_LOW);                  /* Make RW LOW for write operation */
	Dio_WriteChannel(EN, DIO_HIGH);                 /* Make HIGH-LOW transition on Enable */
	_delay_us(5);
	Dio_WriteChannel(EN, DIO_LOW);
	_delay_us(5);
}


void GLCD_Data(char Data)
{
	Dio_WriteChannelGroup(dataPort, 8, Data);   /* Copy data on data Pin */
	Dio_WriteChannel(RS, DIO_HIGH);             /* Make RS HIGH for data register */
	Dio_WriteChannel(RW, DIO_LOW);              /* Make RW LOW for write operation */
	Dio_WriteChannel(EN, DIO_HIGH);             /* Make HIGH-LOW transition on Enable */
	_delay_us(5);
	Dio_WriteChannel(EN, DIO_LOW);
	_delay_us(5);
}


void GLCD_Init()
{
	Dio_DirectionType dataPortdir[] = {DIO_OUTPUT, DIO_OUTPUT, DIO_OUTPUT, DIO_OUTPUT, DIO_OUTPUT, DIO_OUTPUT, DIO_OUTPUT, DIO_OUTPUT};
	Dio_InitChannelGroup(dataPort, 8, dataPortdir);

	Dio_DirectionType cmddir[] = {DIO_OUTPUT, DIO_OUTPUT, DIO_OUTPUT, DIO_OUTPUT, DIO_OUTPUT, DIO_OUTPUT};
	Dio_InitChannelGroup(cmd, 6, cmddir);

	/* Select both left & right half of display & Keep reset Pin high */
	SELECTBOTH();
	Dio_WriteChannel(RST, DIO_HIGH);

	_delay_ms(20);
	GLCD_Command(0x3E); /* Display OFF */
	GLCD_Command(0x40); /* Set Y address (column=0) */
	GLCD_Command(0xB8); /* Set x address (page=0) */
	GLCD_Command(0xC0); /* Set z address (start line=0) */
	GLCD_Command(0x3F); /* Display ON */
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
