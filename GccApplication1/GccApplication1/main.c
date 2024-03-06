/*
 * segsu.c
 *
 * Created: 5/27/2023 1:41:43 PM
 * Author : diaag
 */ 



#include <avr/interrupt.h>
#include <time.h>
#ifndef F_CPU
#define F_CPU 8000000UL
#endif
#include <util/delay.h>


#include "GLCD.h"
#include "MCAL/DIO/Dio.h"




int main(void)
{
	GLCD_Init();
	GLCD_ClearAll();
	Print_String("PWM Signal ", 1);

	int pwmvalue = 0;
	int timefactor = 2; //min:2 max: 25
	char duty[] = "Duty Cycle = 00 %";
	char freq[] = "Frequency = 320 KHZ";

	while (1)
	{
		SELECTFIRST();
		GLCD_Command(0x40);        /* Set Y address (column=0) */
		GLCD_Command(0xB8 + 2);     /* Set x address (page=0) */

		int dc = pwmvalue * 100 / 256;
		duty[13] = dc/10+'0';
		duty[14] = dc%10+'0';

		Print_String(duty, 2);
		Print_String(freq, 3);

		SELECTFIRST();
		GLCD_Command(0x40);        /* Set Y address (column=0) */
		GLCD_Command(0xB8 + 5);

		int x = pwmvalue / timefactor;
		int nextk = 256 / timefactor;
		int k = 0;

		for (int i = 0; i < 128; i++)
		{
			if (i == 64)
			{
				SELECTSECOND();
				GLCD_Command(0x40); /* Set Y address (column=0) */
				GLCD_Command(0xB8 + 5);
			}

			if (i == nextk || i == x + k)
			{
				GLCD_Data(CHANGEVOLT);
				if (i == nextk)
				{
					k = nextk;
					nextk = 256 / timefactor + i;
				}
			}
			else if (i > x + k)
			{
				GLCD_Data(LOWVOLT);
			}
			else
			{
				GLCD_Data(HIGHVOLT);
			}
		}

		pwmvalue += 20;
		if (pwmvalue > 255)
		{
			pwmvalue = 0;
		}

		_delay_ms(100);
	}
}