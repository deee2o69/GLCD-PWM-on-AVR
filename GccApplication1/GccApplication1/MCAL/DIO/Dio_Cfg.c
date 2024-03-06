/*
 * Dio_Cfg.c
 *
 * Created: 05 March 2024
 * Author: Diaa Ahmed
 * Description: AUTOSAR-compliant configuration source file for the DIO module.
 * 
 * This file contains the configuration data for the DIO module. It includes the actual
 * configuration data for DIO channels and any other relevant configuration parameters.
 * 
 * The configuration data includes the mapPings of channel IDs to Ports and Pins, as well
 * as the initial directions for input and output channels. This information is used during
 * the initialization of the DIO module to configure the hardware accordingly.
 * 
 * Note: This file is part of the AUTOSAR-compliant implementation and should not be modified
 * without careful consideration of the impact on the entire system.
 */


#include "Dio_Cfg.h"

/* Actual configuration data for DIO channels */
const Dio_ChannelConfigType Dio_ChannelConfig[DIO_MAX_CHANNELS] = {
	{DIO_PORT_A, 0u},  // PORTA PIN 0
	{DIO_PORT_A, 1u},  // PORTA PIN 1
	{DIO_PORT_A, 2u},  // PORTA PIN 2
	{DIO_PORT_A, 3u},  // PORTA PIN 3
	{DIO_PORT_A, 4u},  // PORTA PIN 4
	{DIO_PORT_A, 5u},  // PORTA PIN 5
	{DIO_PORT_A, 6u},  // PORTA PIN 6
	{DIO_PORT_A, 7u},  // PORTA PIN 7
	{DIO_PORT_B, 0u},  // PORTB PIN 0
	{DIO_PORT_B, 1u},  // PORTB PIN 1
	{DIO_PORT_B, 2u},  // PORTB PIN 2
	{DIO_PORT_B, 3u},  // PORTB PIN 3
	{DIO_PORT_B, 4u},  // PORTB PIN 4
	{DIO_PORT_B, 5u},  // PORTB PIN 5
	{DIO_PORT_B, 6u},  // PORTB PIN 6
	{DIO_PORT_B, 7u},  // PORTB PIN 7
	{DIO_PORT_C, 0u},  // PORTC PIN 0
	{DIO_PORT_C, 1u},  // PORTC PIN 1
	{DIO_PORT_C, 2u},  // PORTC PIN 2
	{DIO_PORT_C, 3u},  // PORTC PIN 3
	{DIO_PORT_C, 4u},  // PORTC PIN 4
	{DIO_PORT_C, 5u},  // PORTC PIN 5
	{DIO_PORT_C, 6u},  // PORTC PIN 6
	{DIO_PORT_C, 7u},  // PORTC PIN 7
	{DIO_PORT_D, 0u},  // PORTD PIN 0
	{DIO_PORT_D, 1u},  // PORTD PIN 1
	{DIO_PORT_D, 2u},  // PORTD PIN 2
	{DIO_PORT_D, 3u},  // PORTD PIN 3
	{DIO_PORT_D, 4u},  // PORTD PIN 4
	{DIO_PORT_D, 5u},  // PORTD PIN 5
	{DIO_PORT_D, 6u},  // PORTD PIN 6
	{DIO_PORT_D, 7u}   // PORTD PIN 7
};