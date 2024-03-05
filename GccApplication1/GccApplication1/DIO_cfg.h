/*
 * DIO_cfg.h
 *
 * Created: 6/20/2023 12:35:27 AM
 *  Author: diaag
 */ 


#ifndef DIO_CFG_H_
#define DIO_CFG_H_


#define  NUMBER_OF_CHANNELS 32

typedef struct{
	uint8_t port;
	uint8_t pin;
	} channel;

	
channel Channel_CFG[NUMBER_OF_CHANNELS]=
{
	{0,0},	 //PORTA PIN 0
	{0,1},	 //PORTA PIN 1
	{0,2},	 //PORTA PIN 2
	{0,3},	 //PORTA PIN 3
	{0,4},	 //PORTA PIN 4
	{0,5},	 //PORTA PIN 5
	{0,6},	 //PORTA PIN 6
	{0,7},	 //PORTA PIN 7
	{1,0},	 //PORTB PIN 0
	{1,1},	 //PORTB PIN 1
	{1,2},	 //PORTB PIN 2
	{1,3},	 //PORTB PIN 3
	{1,4},	 //PORTB PIN 4
	{1,5},	 //PORTB PIN 5
	{1,6},	 //PORTB PIN 6
	{1,7},	 //PORTB PIN 7
	{2,0},	 //PORTC PIN 0
	{2,1},	 //PORTC PIN 1
	{2,2},	 //PORTC PIN 2
	{2,3},	 //PORTC PIN 3
	{2,4},	 //PORTC PIN 4
	{2,5},	 //PORTC PIN 5
	{2,6},	 //PORTC PIN 6
	{2,7},	 //PORTC PIN 7
	{3,0},	 //PORTD PIN 0
	{3,1},	 //PORTD PIN 1
	{3,2},	 //PORTD PIN 2
	{3,3},	 //PORTD PIN 3
	{3,4},	 //PORTD PIN 4
	{3,5},	 //PORTD PIN 5
	{3,6},	 //PORTD PIN 6
	{3,7},	 //PORTD PIN 7
}





#endif /* DIO_CFG_H_ */