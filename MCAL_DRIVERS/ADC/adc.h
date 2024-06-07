/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: ADC.h
 *
 * Description: Header file for the ADC drivers
 *
 * Author: Abdelrahman Mohamed Amir
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "../../LIB_DRIVERS/STD_TYPES.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define ADC_MAXIMUM_VALUE 1023	/* 10-bit resolution (2^10 - 1 = 1023)*/
#define ADC_REF_VOLT_VALUE 2.56 /* ADC reference voltage value (5V or 3.3V)*/

/* static configuration for ADC driver */
#define ADC_INTERRUPT_MODE /* Comment this line if you want polling mode */
#undef ADC_INTERRUPT_MODE

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

extern volatile uint16 g_ADC_result; /* Global variable to store the ADC result in interrupt mode */

typedef enum
{
    ADC_AREF,
    ADC_AVCC,
    ADC_INTERNAL
} ADC_VoltageRef;

typedef enum
{
    NO_PRESCALAR = 0,
    ADC_PRESCALAR_2,
    ADC_PRESCALAR_4,
    ADC_PRESCALAR_8,
    ADC_PRESCALAR_16,
    ADC_PRESCALAR_32,
    ADC_PRESCALAR_64,
    ADC_PRESCALAR_128
} ADC_Prescalar;

typedef struct adc
{
    ADC_VoltageRef ref_voltage;
    ADC_Prescalar prescalar;
} ADC_ConfigType;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*******************************************************************************
 * @fn              - ADC_init
 * @brief           - This function is used to initialize the ADC driver
 * @param[in]       - ADC_ConfigType *config_ptr (Struct members are ref_volt, prescaler)
 * @return          - void
 *******************************************************************************/
void ADC_init(ADC_ConfigType *config_struct);

/*******************************************************************************
 * @fn              - ADC_readChannel
 * @brief           - This function is used to read the ADC channel
 * @param[in]       - uint8 channel_num
 * @return          - void
 * Note: The result is stored in the global variable g_ADC_result
 *******************************************************************************/
void ADC_readChannel(uint8 channel_num);

#endif