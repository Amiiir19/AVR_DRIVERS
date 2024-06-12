/******************************************************************************
 *
 * Module: Sensor
 *
 * File Name: Sensor.h
 *
 * Description: Header file for the Sensor driver
 * 				- LM35 Sensor
 *
 * Author: Abdelrahman Mohamed
 *
 *******************************************************************************/
#ifndef SENSOR_H
#define SENSOR_H
#include "../../MCAL_DRIVERS/ADC/adc.h"
#include "../../LIB_DRIVERS/STD_TYPES.h"



#define SENSOR_LM35_CHANNELNUM 2				 /* Channel of the ADC to which the sensor is connected */
#define SENSOR_LM35_MAX_TEMPERATURE 150
#define SENSOR_LM35_MAX_VOLT 1.5

/******************************************************************************
 *                                Functions Prototypes                        *
 * ****************************************************************************/

/******************************************************************************
 * Description: Function to read the temperature from the LM35 sensor
 * @param void
 * @return uint8
 * 		   Description: Temperature value
 * 		   Range: 0 ~ 150
 ******************************************************************************/

uint8 SENSOR_LM35_READ(void);


#endif