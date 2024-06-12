/******************************************************************************
 *
 * Module: GPIO
 *
 * File Name: gpio.c
 *
 * Description: Source file for the AVR GPIO driver
 *
 * Creator: Eng :  Abdelrahman Mohamed Amir
 *
 *******************************************************************************/

#include "gpio.h" /* To include the GPIO header file */
#include "../../LIB_DRIVERS/BITS_MACROS.h"

#include <avr/io.h> /* To use the IO Ports Registers */

/**
 * @brief 
 * 
 * @param port_num 
 * @param pin_num 
 * @param direction 
 */
void GPIO_setPinDirection(uint8 port_num, uint8 pin_num, GPIO_PinDirection direction)
{
    if ((pin_num >= NUM_OF_PINS) || (port_num >= NUM_OF_PORTS))
    {
        return;
    }
    switch (port_num)
    {
    case PORTA_ID:
        if (direction == PIN_OUTPUT)
            SET_BIT(DDRA, pin_num);
        else
            CLEAR_BIT(DDRA, pin_num);
        break;
    case PORTB_ID:
        if (direction == PIN_OUTPUT)
            SET_BIT(DDRB, pin_num);
        else
            CLEAR_BIT(DDRB, pin_num);
        break;
    case PORTC_ID:
        if (direction == PIN_OUTPUT)
            SET_BIT(DDRC, pin_num);
        else
            CLEAR_BIT(DDRC, pin_num);
        break;
    case PORTD_ID:
        if (direction == PIN_OUTPUT)
            SET_BIT(DDRD, pin_num);
        else
            CLEAR_BIT(DDRD, pin_num);
        break;
    default:
        break;
    }
}
void GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 value)
{
    if ((pin_num >= NUM_OF_PINS) || (port_num >= NUM_OF_PORTS))
    {
        return;
    }
    switch (port_num)
    {
    case PORTA_ID:
        WRITE_BIT(PORTA, pin_num, value);
        break;
    case PORTB_ID:
        WRITE_BIT(PORTB, pin_num, value);
        break;
    case PORTC_ID:
        WRITE_BIT(PORTC, pin_num, value);
        break;
    case PORTD_ID:
        WRITE_BIT(PORTD, pin_num, value);
        break;
    default:
        break;
    }
}
uint8 GPIO_readPin(uint8 port_num, uint8 pin_num)
{
     if ((pin_num >= NUM_OF_PINS) || (port_num >= NUM_OF_PORTS))
    {
    }
    else{
    switch (port_num)
    {
    case PORTA_ID:
        return READ_BIT(PORTA, pin_num);
    case PORTB_ID:
        return READ_BIT(PORTB, pin_num);
    case PORTC_ID:
        return READ_BIT(PORTC, pin_num);
    case PORTD_ID:
        return READ_BIT(PORTD, pin_num);
    default:
        break;
    }
    }
}
void GPIO_setPortDirection(uint8 port_num, GPIO_PortDirection direction)
{
    if ((port_num >= NUM_OF_PORTS))
    {
        return;
    }
    switch (port_num)
    {
    case PORTA_ID:
        DDRA = direction;
        break;
    case PORTB_ID:
        DDRB = direction;
        break;
    case PORTC_ID:
        DDRC = direction;
        break;
    case PORTD_ID:
        DDRD = direction;
        break;
    default:
        break;
    }
}
void GPIO_writePort(uint8 port_num, uint8 value)
{
     if ((port_num >= NUM_OF_PORTS))
    {
        return;
    }
    switch (port_num)
    {
    case PORTA_ID:
        PORTA = value;
        break;
    case PORTB_ID:
        PORTB = value;
        break;
    case PORTC_ID:
        PORTC = value;
        break;
    case PORTD_ID:
        PORTD = value;
        break;
    default:
        break;
    }
}
uint8 GPIO_readPort(uint8 port_num)
{
    if ((port_num >= NUM_OF_PORTS))
    {
    }
    else{
    switch (port_num)
    {
    case PORTA_ID:
        return PINA;
    case PORTB_ID:
        return PINB;
    case PORTC_ID:
        return PINC;
    case PORTD_ID:
        return PIND;
    default:
        break;
    }
}
}
