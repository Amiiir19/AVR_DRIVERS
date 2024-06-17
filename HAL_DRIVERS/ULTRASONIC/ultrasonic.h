#ifndef ULTRASONIC_H
#define ULTRASONIC_H
#include "../../LIB_DRIVERS/STD_TYPES.h"
#include "../../MCAL_DRIVERS/ICU/icu.h"
#include "../../MCAL_DRIVERS/GPIO/gpio.h"

void Ultrasonic_init(void);
void Ultrasonic_Trigger(void);
uint16 Ultrasonic_readDistance(void);
void Ultrasonic_edgeProcessing(void);

#endif