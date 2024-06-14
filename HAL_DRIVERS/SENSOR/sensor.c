/******************************************************************************
 *
 * Module: Sensor
 *
 * File Name: Sensor.c
 *
 * Description: Source file for the Sensor driver
 * 				- LM35 Sensor
 *
 * Author: Abdelrahman Mohamed
 *
 *******************************************************************************/
#include "sensor.h"
#include "../../MCAL_DRIVERS/ADC/adc.h"


uint8 SENSOR_LM35_READ(void)
{

    uint8 value = 0;
    ADC_readChannel(SENSOR_LM35_CHANNELNUM);
    value = (uint8)(((uint32)g_ADC_result * SENSOR_LM35_MAX_TEMPERATURE * ADC_REF_VOLT_VALUE) / (ADC_MAXIMUM_VALUE * SENSOR_LM35_MAX_VOLT));
    return value;
}
