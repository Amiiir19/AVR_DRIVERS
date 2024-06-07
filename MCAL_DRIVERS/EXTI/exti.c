/******************************************************************************
 *
 * Module: External Interrupt
 *
 * File Name: EXTI.c
 *
 * Description: Source file for the External Interrupt driver
 *
 * Author: Abdelrahman Mohamed Amir
 *
 *******************************************************************************/
#include "exti.h"
#include "../../LIB_DRIVERS/BITS_MACROS.h"
#include <avr/interrupt.h>
/* Global variables to hold the address of the call back function in the application */
static volatile void (*g_INT0_callBackPtr)(void) = NULL_PTR;
static volatile void (*g_INT1_callBackPtr)(void) = NULL_PTR;
static volatile void (*g_INT2_callBackPtr)(void) = NULL_PTR;
/*******************************************************************************
 *                                    ISR's                                    *
 *******************************************************************************/
ISR(INT0_vect)
{
    if (g_INT0_callBackPtr != NULL_PTR)
    {
        /* Call the Call Back function in the application  */
        (*g_INT0_callBackPtr)();
    }
}
ISR(INT1_vect)
{
    if (g_INT1_callBackPtr != NULL_PTR)
    {
        /* Call the Call Back function in the application  */
        (*g_INT1_callBackPtr)();
    }
}
ISR(INT2_vect)
{
    if (g_INT2_callBackPtr != NULL_PTR)
    {
        /* Call the Call Back function in the application  */
        (*g_INT2_callBackPtr)();
    }
}
/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void EXTI_init(EXTI_ConfigType *Config_PTR)
{

    switch (Config_PTR->interrupt)
    {
    case EXTI_INT0:
        switch (Config_PTR->sense_control)
        {
        case LOW_LEVEL:
            CLEAR_BIT(MCUCR, ISC00);
            CLEAR_BIT(MCUCR, ISC01);
            break;
        case ANY_LOGICAL_CHANGE:
            SET_BIT(MCUCR, ISC00);
            CLEAR_BIT(MCUCR, ISC01);
            break;
        case FALLING_EDGE:
            CLEAR_BIT(MCUCR, ISC00);
            SET_BIT(MCUCR, ISC01);
            break;
        case RISING_EDGE:
            SET_BIT(MCUCR, ISC00);
            SET_BIT(MCUCR, ISC01);
            break;
        default:
            break;
        }
        break;
    case EXTI_INT1:
        switch (Config_PTR->sense_control)
        {
        case LOW_LEVEL:
            CLEAR_BIT(MCUCR, ISC10);
            CLEAR_BIT(MCUCR, ISC11);
            break;
        case ANY_LOGICAL_CHANGE:
            SET_BIT(MCUCR, ISC10);
            CLEAR_BIT(MCUCR, ISC11);
            break;
        case FALLING_EDGE:
            CLEAR_BIT(MCUCR, ISC10);
            SET_BIT(MCUCR, ISC11);
            break;
        case RISING_EDGE:
            SET_BIT(MCUCR, ISC10);
            SET_BIT(MCUCR, ISC11);
            break;
        default:
            break;
        }
        break;
    case EXTI_INT2:
        switch (Config_PTR->sense_control)
        {
        case FALLING_EDGE:
            CLEAR_BIT(MCUCSR, ISC2);
            break;
        case RISING_EDGE:
            SET_BIT(MCUCSR, ISC2);
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}
void EXTI_Enable(EXTI_ConfigType *Config_PTR)
{
    switch (Config_PTR->interrupt)
    {
    case EXTI_INT0:
        SET_BIT(GICR, INT0);
        break;
    case EXTI_INT1:
        SET_BIT(GICR, INT1);
        break;
    case EXTI_INT2:
        SET_BIT(GICR, INT2);
        break;
    default:
        break;
    }
}
void EXTI_Disable(EXTI_ConfigType *Config_PTR)
{
    switch (Config_PTR->interrupt)
    {
    case EXTI_INT0:
        CLEAR_BIT(GICR, INT0);
        break;
    case EXTI_INT1:
        CLEAR_BIT(GICR, INT1);
        break;
    case EXTI_INT2:
        CLEAR_BIT(GICR, INT2);
        break;
    default:
        break;
    }
}

void EXTI_setCallBack(Interrupt_ConfigType *Config_Ptr, void (*a_ptr)(void))
{
    switch (Config_PTR->interrupt)
    {
    case EXTI_INT0:
        g_INT0_callBackPtr = a_ptr;
        break;
    case EXTI_INT1:
        g_INT1_callBackPtr = a_ptr;
        break;
    case EXTI_INT2:
        g_INT2_callBackPtr = a_ptr;
        break;
    default:
        break;
    }
}
