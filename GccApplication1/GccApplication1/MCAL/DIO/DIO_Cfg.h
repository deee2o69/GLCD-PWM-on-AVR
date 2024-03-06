/*
 * Dio_Cfg.h
 *
 * Created: 05 March 2024
 * Author: Diaa Ahmed
 * Description: AUTOSAR-compliant configuration header file for the DIO module.
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

#ifndef DIO_CFG_H_
#define DIO_CFG_H_

#include "Dio_Types.h"  // Include types header

/* Maximum number of DIO channels */
#define DIO_MAX_CHANNELS    (32u)

/* DIO port identifiers */
#define DIO_PORT_A           (0u)
#define DIO_PORT_B           (1u)
#define DIO_PORT_C           (2u)
#define DIO_PORT_D           (3u)

/* DIO channel configurations */
extern const Dio_ChannelConfigType Dio_ChannelConfig[DIO_MAX_CHANNELS];

#endif /* DIO_CFG_H_ */