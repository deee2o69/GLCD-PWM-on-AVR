/*
 * Dio.h
 *
 * Created: 6/20/2023 12:28:29 AM
 *  Author: diaag
 */ 


#ifndef DIO_H_
#define DIO_H_

;
typedef enum {
	STD_INPUT,
	STD_OUTPUT
	}Dio_dir;

typedef enum {
	STD_LOW,
	STD_HIGH
	}Dio_level;

 

#define PA (0u)
#define PB (1u)
#define PC (2u)
#define PD (3u)

extern void			Dio_init_channel		(	uint8_t ch	,	Dio_dir DIR		);
extern void			Dio_Write_channel		(	uint8_t ch	,	Dio_level level	);
extern Dio_level	Dio_Read_channel		(	uint8_t ch	);
extern void			Dio_init_channel_group	(	uint8_t* ch	,	uint8_t size	,	Dio_dir* DIR		);
extern void			Dio_Write_channel_group	(	uint8_t* ch	,	uint8_t size	,	uint8_t data	);
extern uint8_t		Dio_Read_channel_group	(	uint8_t* ch	,	uint8_t size	);


#endif /* DIO_H_ */