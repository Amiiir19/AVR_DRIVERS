/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: ADC.c
 *
 * Description: source file for the ADC driver
 *
 * Author: Hossam Mohamed
 *
 *******************************************************************************/
#include "adc.h"
#include "../../LIB_DRIVERS/BITS_MACROS.h"
#include "avr/io.h"        /* To use the IO Ports Registers */
#include <avr/interrupt.h> /* For ADC ISR */
/*******************************************************************************
 *                          Global Variables                                   *
 *******************************************************************************/
volatile uint16 g_ADC_result = 0;
/*******************************************************************************
 *                          Functions Definitions                              *
 *******************************************************************************/

/*******************************************************************************
 * @fn              - ADC_init
 * @brief           - This function is used to initialize the ADC driver
 * @param[in]       - ADC_ConfigType *config_ptr (Struct members are ref_volt, prescaler)
 * @return          - void
 *******************************************************************************/
void ADC_init(ADC_ConfigType *config_ptr)
{
    /****************     Reference Voltage For ADC      ******************/
    switch (config_ptr->ref_voltage)
    {
    case ADC_AREF:
        CLEAR_BIT(ADMUX, REFS0);
        CLEAR_BIT(ADMUX, REFS1);
        break;
    case ADC_AVCC:
        CLEAR_BIT(ADMUX, REFS0);
        SET_BIT(ADMUX, REFS1);
        break;
    case ADC_INTERNAL:
        SET_BIT(ADMUX, REFS0);
        SET_BIT(ADMUX, REFS1);
        break;
    default:
        break;
    }
    /****************   Prescalar   ****************/
    /* Look At page 215 in Data sheet */
    // ADMUX | Assume channel 0  11100000
    ADMUX = ADMUX & 0xE0;

    // ADCSRA | ADC Prescaler Selections 11111000
    ADCSRA = (ADCSRA & 0xF8) | (config_ptr->prescaler & 0x07);

    // ADCSRA | ADC enable
    SET_BIT(ADCSRA, ADEN);

    /********************  Enable Or disable Interrupt ***********/

#ifdef ADC_INTERRUPT_MODE
    SET_BIT(ADCSRA, ADIE);
#else
    CLEAR_BIT(ADCSRA, ADIE);
#endif
}

/*******************************************************************************
 * @fn              - ADC_readChannel
 * @brief           - This function is used to read the ADC channel
 * @param[in]       - uint8 channel_num
 * @return          - void
 *******************************************************************************/
void ADC_readChannel(uint8 channel_num)
{
    // insert channel num 00000111
    ADMUX = (ADMUX & 0xE0) | (0x07 & channel_num); /* Input channel number must be from 0 --> 7 */

    // start conversion
    SET_BIT(ADCSRA, ADSC);

#ifndef ADC_INTERRUPT_MODE
    // polling until flag ADCIF == 1
    while (IS_BIT_CLEAR(ADCSRA, ADIF))
        ;

    // clear flag
    SET_BIT(ADCSRA, ADIF);

    // get data
    g_ADC_result = ADC;
#endif
}
/*******************************************************************************
 *                          ISR Definitions                              *
 *******************************************************************************/
/* ADC Interrupt Service Routine executed when ADC conversion completes */

#ifdef ADC_INTERRUPT_MODE

ISR(ADC_vect)
{
    /* Read ADC Data after conversion complete */
    g_ADC_result = ADC;
}
#endif
