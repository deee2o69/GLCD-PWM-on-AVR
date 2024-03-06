/*
 * Dio_Types.h
 *
 * Created: 5 March 2024
 * Author: Diaa Ahmed
 * Description: AUTOSAR-compliant types header file for the DIO module.
 * 
 * This file includes type definitions specific to the DIO (Digital Input/Output) module,
 * such as enums for channel directions and levels. These types are fundamental to the DIO
 * module's implementation, contributing to a standardized interface for configuring and
 * controlling Digital Input/Output channels.
 * 
 * The module adheres to AUTOSAR naming conventions, and the types defined in this file are used
 * across various components to ensure a uniform and standardized interface.
 * 
 * Note: This file is part of the AUTOSAR-compliant implementation and should not be modified
 * without careful consideration of the impact on the entire system.
 */


#ifndef DIO_TYPES_H_
#define DIO_TYPES_H_

#include <stdint.h>  // Include standard integer types

/* Enumeration for DIO channel direction */
typedef enum {
	DIO_INPUT,    /* Input direction */
	DIO_OUTPUT    /* Output direction */
} Dio_DirectionType;

/* Enumeration for DIO channel level */
typedef enum {
	DIO_LOW,      /* Low level */
	DIO_HIGH      /* High level */
} Dio_LevelType;

/* Type definition for DIO channel ID */
typedef uint8_t Dio_ChannelType;

/* Type definition for DIO Port ID */
typedef uint8_t Dio_PortType;

/* Type definition for DIO channel configuration */
typedef struct {
	Dio_PortType Port;  /* DIO Port identifier */
	uint8_t Pin;        /* DIO Pin number within the Port */
} Dio_ChannelConfigType;



#endif /* DIO_TYPES_H_ */