/*
 * Dio.h
 *
 * Created: 6/20/2023 12:28:29 AM
 * Author: diaag
 * Description: AUTOSAR-compliant header file for the DIO module.
 * 
 * This file contains the declarations and prototypes for the DIO module, providing a standardized
 * API for configuring and controlling Digital Input/Output channels. The module supPorts functions
 * for initializing individual channels, writing to and reading from individual channels, as well
 * as working with groups of channels.
 * 
 * The module adheres to AUTOSAR naming conventions and provides standardized enums for channel
 * directions and levels. The functions are designed to be used in an AUTOSAR-compliant software
 * architecture.
 * 
 * Note: This file is part of the AUTOSAR-compliant implementation and should not be modified
 * without careful consideration of the impact on the entire system.
 */ 

#ifndef DIO_H_
#define DIO_H_

#include "Dio_types.h"
/* Function prototypes */

/**************************************************************
 * Description: Initializes a specific channel.
 * Parameters:
 *   - ChannelId: Channel identifier.
 *   - Direction: Direction (STD_INPUT or STD_OUTPUT).
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
extern void Dio_InitChannel(uint8_t ChannelId, Dio_DirectionType Direction);
/**************************************************************
 * Description: Writes a specified level to a specific channel.
 * Parameters:
 *   - ChannelId: Channel identifier.
 *   - Level: Output level (STD_LOW or STD_HIGH).
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
 * Reentrancy: 
 *   - Non-Reentrant
 *   - This function is not designed to be reentrant as it directly modifies hardware registers.
 * Note:
 *   - This function should be called to set the output level of a configured output channel.
 **************************************************************/
extern void Dio_WriteChannel(uint8_t ChannelId, Dio_LevelType Level);

/**************************************************************
 * Description: Reads the current level of a specific channel.
 * Parameters:
 *   - ChannelId: Channel identifier.
 * Outputs:
 *   - Dio_LevelType: Current level of the specified channel (STD_LOW or STD_HIGH).
 *   - Generates an error if the channel ID is invalid.
 * Conformance to AUTOSAR Standard: 
 *   - This function adheres to the AUTOSAR standard by providing a standardized API for channel read operation.
 *   - It follows the standard naming conventions and parameter types as specified in the AUTOSAR standard.
 * Reentrancy: 
 *   - Non-Reentrant
 *   - This function is not designed to be reentrant as it directly reads hardware registers.
 * Note:
 *   - This function should be called to get the current level of a configured input channel.
 **************************************************************/
extern Dio_LevelType Dio_ReadChannel(uint8_t ChannelId);

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
 *   - May modify the data direction register (DDRx) based on the specified channels.
 *   - May have side effects on the configured hardware Ports.
 *   - Generates an error if any channel ID is invalid.
 * Conformance to AUTOSAR Standard: 
 *   - This function adheres to the AUTOSAR standard by providing a standardized API for channel group initialization.
 *   - It follows the standard naming conventions and parameter types as specified in the AUTOSAR standard.
 * Reentrancy: 
 *   - Non-Reentrant
 *   - This function is not designed to be reentrant as it directly modifies hardware registers.
 * Note:
 *   - This function should be called during the initialization phase of the software.
 *   - Ensure proper initialization of Dio_ChannelConfig array before calling this function.
 **************************************************************/
extern void Dio_InitChannelGroup(uint8_t* ChannelIds, uint8_t Size, Dio_DirectionType* Directions);

/**************************************************************
 * Description: Writes a specified data to a group of channels.
 * Parameters:
 *   - ChannelIds: Array of channel identifiers.
 *   - Size: Number of channels in the group.
 *   - Data: Data to be written to the channels.
 * Inputs: 
 *   - ChannelIds: Array containing the identifiers of the channels to be written.
 *   - Size: The number of channels in the group.
 *   - Data: The data to be written to all channels in the group.
 * Outputs:
 *   - None
 *   - Modifies the output registers (PORTx) based on the specified channels.
 *   - Generates an error if any channel ID is invalid.
 * Conformance to AUTOSAR Standard: 
 *   - This function adheres to the AUTOSAR standard by providing a standardized API for channel group write operation.
 *   - It follows the standard naming conventions and parameter types as specified in the AUTOSAR standard.
 * Reentrancy: 
 *   - Non-Reentrant
 *   - This function is not designed to be reentrant as it directly modifies hardware registers.
 * Note:
 *   - This function should be called to set the output level of a configured output channel group.
 **************************************************************/
extern void Dio_WriteChannelGroup(uint8_t* ChannelIds, uint8_t Size, uint8_t Data);

/**************************************************************
 * Description: Reads the current data from a group of channels.
 * Parameters:
 *   - ChannelIds: Array of channel identifiers.
 *   - Size: Number of channels in the group.
 * Outputs:
 *   - uint8_t: Current data read from the specified channels.
 *   - Generates an error if any channel ID is invalid.
 * Conformance to AUTOSAR Standard: 
 *   - This function adheres to the AUTOSAR standard by providing a standardized API for channel group read operation.
 *   - It follows the standard naming conventions and parameter types as specified in the AUTOSAR standard.
 * Reentrancy: 
 *   - Non-Reentrant
 *   - This function is not designed to be reentrant as it directly reads hardware registers.
 * Note:
 *   - This function should be called to get the current data from a configured input channel group.
 **************************************************************/
extern uint8_t Dio_ReadChannelGroup(uint8_t* ChannelIds, uint8_t Size);


#endif /* DIO_H_ */