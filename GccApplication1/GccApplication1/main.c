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

#define ADC_CHANNEL 0

#include "GLCD.h"
#include "MCAL/DIO/Dio.h"

void ADC_Init() {
	// Configure reference voltage and enable ADC
	Dio_InitChannel(1,DIO_INPUT);
	Dio_InitChannel(2,DIO_INPUT);
	ADMUX = (1 << REFS0);  // AVCC as reference voltage
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}

uint16_t ADC_Read(uint8_t channel) {
	// Select ADC channel
	ADMUX = (ADMUX & 0xF0) | (channel & 0x0F);
    //ADMUX = (1 << REFS0);

	// Start ADC conversion
	ADCSRA |= (1 << ADSC);

	// Wait for conversion to complete
	while (ADCSRA & (1 << ADSC));

	// Return ADC result
	return ADC;
}


int main(void)
{
	GLCD_Init();
	ADC_Init();
	GLCD_ClearAll();
	Print_String("PWM Signal ", 1);

	int pwmvalue = 0;
	int timefactor = 10; //min:2 max: 25
	char duty[] = "Duty Cycle = 000 %";
	char freq[] = "Frequency = 320 KHZ";
	uint16_t adcValue;

	while (1)
	{
		SELECTFIRST();
		GLCD_Command(0x40);        /* Set Y address (column=0) */
		GLCD_Command(0xB8 + 2);     /* Set x address (page=0) */

		int dc = pwmvalue * 100 / 256;
		if (dc == 100){
			duty[13] = '1';
			duty[14] = '0';
			duty[15] = '0';
			}
			else {
		duty[13] = '0';	
		duty[14] = dc/10+'0';
		duty[15] = dc%10+'0';
}
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
		adcValue = ADC_Read(ADC_CHANNEL)*(256.0/1023.0);
		pwmvalue = adcValue;

		_delay_ms(10);
	}

	return 0;
}