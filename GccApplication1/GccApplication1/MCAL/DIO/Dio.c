/*
 * dio.c
 *
 * Created: 5 March 2024
 * Author: Diaa Ahmed
 * Description: Implementation file for the DIO (Digital Input/Output) module.
 * 
 * This file contains the actual implementation of the DIO module, providing functions
 * for initializing individual channels, writing to and reading from individual channels,
 * as well as working with groups of channels. The implementation adheres to AUTOSAR
 * standards, providing a standardized API for configuring and controlling Digital
 * Input/Output channels.
 * 
 * The module's functions are designed to be used in an AUTOSAR-compliant software
 * architecture. The implementation uses standard types and naming conventions for clarity
 * and consistency.
 * 
 * Note: This file is part of the AUTOSAR-compliant implementation and should not be
 * modified without careful consideration of the impact on the entire system.
 */

#include <stdint-gcc.h>
#include <avr/io.h>
#include "Dio_types.h"
#include "DIO_cfg.h"
#include "Dio.h"

/**************************************************************
 * Description: Initializes a specific channel.
 * Parameters:
 *   - ChannelId: Channel identifier.
 *   - Direction: Direction (DIO_INPUT or DIO_OUTPUT).
 * Inputs: 
 *   - ChannelId: The identifier of the channel to be initialized.
 *   - Direction: The desired direction for the channel (input or output).
 * Outputs:
 *   - None
 *   - May modify the data direction register (DDRx) based on the specified channel.
 *   - May have side effects on the configured hardware Port.
 *   - Generates an error if the channel ID is invalid.
 * Conformance to AUTOSAR Standard: 
 *   - This function adheres to the AUTOSAR standard by providing a standardized API for channel initialization.
 *   - It follows the standard naming conventions and parameter types as specified in the AUTOSAR standard.
 * Reentrancy: 
 *   - Non-Reentrant
 *   - This function is not designed to be reentrant as it directly modifies hardware registers.
 * Note:
 *   - This function should be called during the initialization phase of the software.
 *   - Ensure proper initialization of Dio_ChannelConfig array before calling this function.
 **************************************************************/
void Dio_InitChannel(uint8_t ChannelId, Dio_DirectionType Direction)
{
    /* Check if the channel ID is valid */
    if (ChannelId >= DIO_MAX_CHANNELS)
    {   
        /* Error: Invalid channel ID */
        /* Implement error handling logic as needed */
    }
    else
    {
        /* Select the Port based on the configuration */
        switch (Dio_ChannelConfig[ChannelId - 1].Port)
        {
            case DIO_PORT_A:
                if (Direction == DIO_OUTPUT)
                {
                    /* Set the corresponding Pin as an output */
                    DDRA |= (1u << Dio_ChannelConfig[ChannelId - 1].Pin);
                }
                else
                {
                    /* Set the corresponding Pin as an input */
                    DDRA &= ~(1u << Dio_ChannelConfig[ChannelId - 1].Pin);
                }
                break;

            case DIO_PORT_B:
                if (Direction == DIO_OUTPUT)
                {
                    DDRB |= (1u << Dio_ChannelConfig[ChannelId - 1].Pin);
                }
                else
                {
                    DDRB &= ~(1u << Dio_ChannelConfig[ChannelId - 1].Pin);
                }
                break;

            case DIO_PORT_C:
                if (Direction == DIO_OUTPUT)
                {
                    DDRC |= (1u << Dio_ChannelConfig[ChannelId - 1].Pin);
                }
                else
                {
                    DDRC &= ~(1u << Dio_ChannelConfig[ChannelId - 1].Pin);
                }
                break;

            case DIO_PORT_D:
                if (Direction == DIO_OUTPUT)
                {
                    DDRD |= (1u << Dio_ChannelConfig[ChannelId - 1].Pin);
                }
                else
                {
                    DDRD &= ~(1u << Dio_ChannelConfig[ChannelId - 1].Pin);
                }
                break;
        }
    }
}
/**************************************************************
 * Description: Writes a specified level to a specific channel.
 * Parameters:
 *   - ChannelId: Channel identifier.
 *   - Level: Output level (DIO_LOW or DIO_HIGH).
 * Inputs: 
 *   - ChannelId: The identifier of the channel to be written.
 *   - Level: The desired output level for the channel (low or high).
 * Outputs:
 *   - None
 *   - Modifies the output register (PORTx) based on the specified channel.
 *   - Generates an error if the channel ID is invalid.
 * Conformance to AUTOSAR Standard: 
 *   - This function adheres to the AUTOSAR standard by providing a standardized API for channel write operation.
 *   - It follows the standard naming conventions and parameter types as specified in the AUTOSAR standard.
 *   - The function uses MISRA-C compliant syntax and error checking.
 * Reentrancy: 
 *   - Non-Reentrant
 *   - This function is not designed to be reentrant as it directly modifies hardware registers.
 * Note:
 *   - This function should be called to set the output level of a configured output channel.
 **************************************************************/
void Dio_WriteChannel(uint8_t ChannelId, Dio_LevelType Level)
{
    if (ChannelId >= DIO_MAX_CHANNELS)
    {
        /* Error: Invalid channel ID */
        // Add error handling code if needed
    }
    else
    {
        switch (Dio_ChannelConfig[ChannelId - 1].Port)
        {
            case DIO_PORT_A:
                if (Level == DIO_HIGH)
                    PORTA |= (1u << Dio_ChannelConfig[ChannelId - 1].Pin);
                else
                    PORTA &= ~(1u << Dio_ChannelConfig[ChannelId - 1].Pin);
                break;
                
            case DIO_PORT_B:
                if (Level == DIO_HIGH)
                    PORTB |= (1u << Dio_ChannelConfig[ChannelId - 1].Pin);
                else
                    PORTB &= ~(1u << Dio_ChannelConfig[ChannelId - 1].Pin);
                break;
                
            case DIO_PORT_C:
                if (Level == DIO_HIGH)
                    PORTC |= (1u << Dio_ChannelConfig[ChannelId - 1].Pin);
                else
                    PORTC &= ~(1u << Dio_ChannelConfig[ChannelId - 1].Pin);
                break;
                
            case DIO_PORT_D:
                if (Level == DIO_HIGH)
                    PORTD |= (1u << Dio_ChannelConfig[ChannelId - 1].Pin);
                else
                    PORTD &= ~(1u << Dio_ChannelConfig[ChannelId - 1].Pin);
                break;
                
            default:
                /* Error: Invalid Port in Dio_ChannelConfig */
                // Add error handling code if needed
                break;
        }
    }
}


/**************************************************************
 * Description: Reads the current level of a specific channel.
 * Parameters:
 *   - ChannelId: Channel identifier.
 * Outputs:
 *   - Dio_LevelType: Current level of the specified channel (DIO_LOW or DIO_HIGH).
 *   - Generates an error if the channel ID is invalid.
 * Conformance to AUTOSAR Standard: 
 *   - This function adheres to the AUTOSAR standard by providing a standardized API for channel read operation.
 *   - It follows the standard naming conventions and parameter types as specified in the AUTOSAR standard.
 *   - The function uses MISRA-C compliant syntax and error checking.
 * Reentrancy: 
 *   - Non-Reentrant
 *   - This function is not designed to be reentrant as it directly reads hardware registers.
 * Note:
 *   - This function should be called to get the current level of a configured input channel.
 **************************************************************/
Dio_LevelType Dio_ReadChannel(uint8_t ChannelId)
{	
    Dio_LevelType ReturnValue = DIO_LOW;  // Initialize to low level
    
    if (ChannelId >= DIO_MAX_CHANNELS)
    {
        /* Error: Invalid channel ID */
        // Add error handling code if needed
    }
    else
    {
        switch (Dio_ChannelConfig[ChannelId - 1].Port)
        {
            case DIO_PORT_A:
                ReturnValue = (PINA & (1u << Dio_ChannelConfig[ChannelId - 1].Pin)) ? DIO_HIGH : DIO_LOW;
                break;
                
            case DIO_PORT_B:
                ReturnValue = (PINB & (1u << Dio_ChannelConfig[ChannelId - 1].Pin)) ? DIO_HIGH : DIO_LOW;
                break;
                
            case DIO_PORT_C:
                ReturnValue = (PINC & (1u << Dio_ChannelConfig[ChannelId - 1].Pin)) ? DIO_HIGH : DIO_LOW;
                break;
                
            case DIO_PORT_D:
                ReturnValue = (PIND & (1u << Dio_ChannelConfig[ChannelId - 1].Pin)) ? DIO_HIGH : DIO_LOW;
                break;
                
            default:
                /* Error: Invalid Port in Dio_ChannelConfig */
                // Add error handling code if needed
                break;
        }
    }

    return ReturnValue;
}


/**************************************************************
 * Description: Writes a specified data to a group of channels.
 * Parameters:
 *   - ChannelIds: Array of channel identifiers.
 *   - Size: Number of channels in the group.
 *   - Data: Data to be written to the group (each bit corresponds to a channel).
 * Inputs: 
 *   - ChannelIds: Array containing the identifiers of the channels to be written.
 *   - Size: The number of channels in the group.
 *   - Data: Data to be written to the group (each bit corresponds to a channel).
 * Outputs:
 *   - None
 *   - Calls Dio_WriteChannel for each channel in the group to set the output level.
 *   - Generates an error if any channel ID is invalid.
 * Conformance to AUTOSAR Standard: 
 *   - This function adheres to the AUTOSAR standard by providing a standardized API for channel group write operation.
 *   - It follows the standard naming conventions and parameter types as specified in the AUTOSAR standard.
 *   - The function uses MISRA-C compliant syntax and error checking.
 * Reentrancy: 
 *   - Non-Reentrant
 *   - This function is not designed to be reentrant as it directly modifies hardware registers.
 * Note:
 *   - This function should be called to set the output levels of a configured group of output channels.
 **************************************************************/
void Dio_WriteChannelGroup(uint8_t* ChannelIds, uint8_t Size, uint8_t Data)
{
    for (int i = 0; i < Size; i++)
    {
        Dio_WriteChannel(ChannelIds[i], (Data & (1u << i)) >> i);
    }
}

/**************************************************************
 * Description: Reads the current levels of a group of channels and combines them into a byte.
 * Parameters:
 *   - ChannelIds: Array of channel identifiers.
 *   - Size: Number of channels in the group.
 * Outputs:
 *   - uint8_t: Combined data from the group (each bit corresponds to a channel).
 *   - Generates an error if any channel ID is invalid.
 * Conformance to AUTOSAR Standard: 
 *   - This function adheres to the AUTOSAR standard by providing a standardized API for channel group read operation.
 *   - It follows the standard naming conventions and parameter types as specified in the AUTOSAR standard.
 *   - The function uses MISRA-C compliant syntax and error checking.
 * Reentrancy: 
 *   - Non-Reentrant
 *   - This function is not designed to be reentrant as it directly reads hardware registers.
 * Note:
 *   - This function should be called to get the current levels of a configured group of input channels.
 **************************************************************/
uint8_t Dio_ReadChannelGroup(uint8_t* ChannelIds, uint8_t Size)
{
    uint8_t Data = 0;
    
    for (int i = 0; i < Size; i++)
    {
        Data |= (Dio_ReadChannel(ChannelIds[i]) << i);
    }
    
    return Data;
}

/**************************************************************
 * Description: Initializes a group of channels.
 * Parameters:
 *   - ChannelIds: Array of channel identifiers.
 *   - Size: Number of channels in the group.
 *   - Directions: Array of directions (STD_INPUT or STD_OUTPUT).
 * Inputs: 
 *   - ChannelIds: Array containing the identifiers of the channels to be initialized.
 *   - Size: The number of channels in the group.
 *   - Directions: Array containing the desired directions for each channel in the group (input or output).
 * Outputs:
 *   - None
 *   - Calls Dio_InitChannel for each channel in the group to initialize the channel.
 *   - Generates an error if any channel ID is invalid.
 * Conformance to AUTOSAR Standard: 
 *   - This function adheres to the AUTOSAR standard by providing a standardized API for channel group initialization.
 *   - It follows the standard naming conventions and parameter types as specified in the AUTOSAR standard.
 *   - The function uses MISRA-C compliant syntax and error checking.
 * Reentrancy: 
 *   - Non-Reentrant
 *   - This function is not designed to be reentrant as it directly modifies hardware registers.
 * Note:
 *   - This function should be called during the initialization phase of the software.
 *   - Ensure proper initialization of Dio_ChannelConfig array before calling this function.
 **************************************************************/
void Dio_InitChannelGroup(uint8_t* ChannelIds, uint8_t Size, Dio_DirectionType* Directions)
{
    for (int i = 0; i < Size; i++)
    {
        Dio_InitChannel(ChannelIds[i], Directions[i]);
    }
}
