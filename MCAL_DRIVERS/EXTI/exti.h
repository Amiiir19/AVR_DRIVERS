/******************************************************************************
 *
 * Module: External Interrupt
 *
 * File Name: EXTI.h
 *
 * Description: Header file for External Interrupt Module.
 *
 * Author: Abdelrahman  Mohamed
 *
 *******************************************************************************/

#ifndef EXTI_H_
#define EXTI_H_

#include "../../LIB_DRIVERS/STD_TYPES.h"
#include <avr/io.h>

/*******************************************************************************
 * 					       Types Declaration                               	   *
 * *****************************************************************************/

typedef enum
{
    EXTI_INT0,
    EXTI_INT1,
    EXTI_INT2
} EXTI_Interrupt;

typedef enum
{
    LOW_LEVEL,
    ANY_LOGICAL_CHANGE,
    FALLING_EDGE,
    RISING_EDGE
} EXTI_Mode;
/*******************************************************************************
 * 								Configuration structure                        *
 * *****************************************************************************/
typedef struct
{
    EXTI_Interrupt interrupt;
    EXTI_Mode sense_control;
} EXTI_ConfigType;

/*******************************************************************************
 * 								Functions Prototypes                           *
 * *****************************************************************************/

void EXTI_init(EXTI_ConfigType *Config_PTR);
void EXTI_Enable(EXTI_ConfigType *Config_PTR);
void EXTI_Disable(EXTI_ConfigType *Config_PTR);

/****************************** Call Back function *****************************/
void EXTI_setCallBack(EXTI_ConfigType *Config_Ptr, void (*a_ptr)(void));

#endif
