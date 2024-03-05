/*
 * Dio.c
 *
 * Created: 6/20/2023 12:28:17 AM
 *  Author: diaag
 */ 
#include <stdint-gcc.h>
#include <avr/io.h>
#include "DIO_cfg.h"
#include "Dio.h"

void Dio_init_channel(uint8_t ch, Dio_dir DIR)
{
	if (ch>=NUMBER_OF_CHANNELS) 
	{	// error detection
	}
	else {
			switch(Channel_CFG[ch-1].port)
			{
				case(PA):
					if (DIR)	DDRA |=		(1<<Channel_CFG[ch-1].pin);
					else		DDRA &= ~	(1<<Channel_CFG[ch-1].pin);
					break;
				case(PB):
					if (DIR)	DDRB |=		(1<<Channel_CFG[ch-1].pin);
					else		DDRB &= ~	(1<<Channel_CFG[ch-1].pin);
					break;
				case(PC):
					if (DIR)	DDRC |=		(1<<Channel_CFG[ch-1].pin);
					else		DDRC &= ~	(1<<Channel_CFG[ch-1].pin);
					break;
				case(PD):
					if (DIR)	DDRD |=		(1<<Channel_CFG[ch-1].pin);
					else		DDRD &= ~	(1<<Channel_CFG[ch-1].pin);
					break;
			}
	}

	
	
	
	
}

void Dio_Write_channel(uint8_t ch,Dio_level level)
{
	if (ch>=NUMBER_OF_CHANNELS)
	{	// error detection
	}
	else {
		switch(Channel_CFG[ch-1].port)
		{
			case(PA):
			if (level)	PORTA |=		(1<<Channel_CFG[ch-1].pin);
			else		PORTA &= ~		(1<<Channel_CFG[ch-1].pin);
			break;
			case(PB):
			if (level)	PORTB |=		(1<<Channel_CFG[ch-1].pin);
			else		PORTB &= ~		(1<<Channel_CFG[ch-1].pin);
			break;
			case(PC):
			if (level)	PORTC |=		(1<<Channel_CFG[ch-1].pin);
			else		PORTC &= ~		(1<<Channel_CFG[ch-1].pin);
			break;
			case(PD):
			if (level)	PORTD |=		(1<<Channel_CFG[ch-1].pin);
			else		PORTD &= ~		(1<<Channel_CFG[ch-1].pin);
			break;
		}
	}
	
}

Dio_level Dio_Read_channel(uint8_t ch)
{	
	Dio_level RETURN_VALUE = STD_LOW;
	if (ch>=NUMBER_OF_CHANNELS)
	{	// error detection
	}
	else {
		switch(Channel_CFG[ch-1].port)
		{
			case(PA):
			RETURN_VALUE = ( PINA & (1<<Channel_CFG[ch-1].pin) )?STD_HIGH:STD_LOW;
			break;
			case(PB):
			RETURN_VALUE = ( PINB & (1<<Channel_CFG[ch-1].pin)  )?STD_HIGH:STD_LOW;
			break;
			case(PC):
			RETURN_VALUE = ( PINC & (1<<Channel_CFG[ch-1].pin) )?STD_HIGH:STD_LOW;
			break;
			case(PD):
			RETURN_VALUE = ( PIND & (1<<Channel_CFG[ch-1].pin) )?STD_HIGH:STD_LOW;
			break;
		}
	}
	
	return RETURN_VALUE;
	
	
	
	
}

void Dio_Write_channel_group(uint8_t* ch,uint8_t size,uint8_t data)
{
	for(int i = 0; i<size;i++)
	{
		Dio_Write_channel(ch[i],(data & (1<<i) ) >> i);
	}
}

uint8_t Dio_Read_channel_group(uint8_t* ch,uint8_t size){	uint8_t data = 0;
	for(int i = 0; i<size;i++)
	{
		data |= (Dio_Read_channel(ch[i])<<i);
	}
	return data;
}

 void	Dio_init_channel_group	(	uint8_t* ch	,	uint8_t size	,	Dio_dir* DIR		)
 {
	 for(int i = 0; i<size;i++)
	 {
	 Dio_init_channel(ch[i],DIR[i]);
	 }
 }