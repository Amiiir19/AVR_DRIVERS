#ifndef  DC_MOTOR_H
#define   DC_MOTOR_H
#include "../../MCAL_DRIVERS/GPIO/gpio.h"
#include "../../LIB_DRIVERS/STD_TYPES.h"
typedef enum {
	CLOCKWISE, ANTI_CLOCKWISE, STOP
} DcMotor_State;

void DcMotor_Init(void);
void DcMotor_Rotate(DcMotor_State state, uint8 speed);

#endif
