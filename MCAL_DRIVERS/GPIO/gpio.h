/******************************************************************************
 *
 * Module: GPIO
 *
 * File Name: gpio.h
 *
 * Description: Gpio driver for AVR
 *
 * Creator: Eng :  Abdelrahman Mohamed Amir
 *
 *******************************************************************************/

#ifndef GPIO_H
#define GPIO_H

#include "../../LIB_DRIVERS/STD_TYPES.h"

/************************************************
 *                 Definitions                  *
 *************************************************/

#define NUM_OF_PINS 8
#define NUM_OF_PORTS 4

#define PORTA_ID 0
#define PORTB_ID 1
#define PORTC_ID 2
#define PORTD_ID 3

#define PIN0_ID 0
#define PIN1_ID 1
#define PIN2_ID 2
#define PIN3_ID 3
#define PIN4_ID 4
#define PIN5_ID 5
#define PIN6_ID 6
#define PIN7_ID 7

/************************************************
 *                 Types Declarations           *
 *************************************************/

typedef enum
{
    PIN_INPUT,
    PIN_OUTPUT
} GPIO_PinDirection;
typedef enum
{
    PORT_INPUT,
    PORT_OUTPUT = 0XFF
} GPIO_PortDirection;
/************************************************
 *                 Function Prototype           *
 *************************************************/
void GPIO_setPinDirection(uint8 port_num, uint8 pin_num, GPIO_PinDirection direction);
void GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 value);
uint8 GPIO_readPin(uint8 port_num, uint8 pin_num);
void GPIO_setPortDirection(uint8 port_num, GPIO_PortDirection direction);
void GPIO_writePort(uint8 port_num, uint8 value);
uint8 GPIO_readPort(uint8 port_num);

#endif