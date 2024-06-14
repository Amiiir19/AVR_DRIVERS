#include "dcmotor.h"
#include "../../MCAL_DRIVERS/PWM/pwm.h"

void DcMotor_Init(void) {

	GPIO_setPinDirection(PORTB_ID, PIN0_ID, PIN_OUTPUT);
	GPIO_setPinDirection(PORTB_ID, PIN1_ID, PIN_OUTPUT);
	GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);
	GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);
	PWM_Timer0_Init(0);

}
void DcMotor_Rotate(DcMotor_State state, uint8 speed) {

	switch (state) {
	case STOP:
		GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);
		GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);
		PWM_Timer0_Init(0);
		break;
	case CLOCKWISE:
		GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_HIGH);
		GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);
		PWM_Timer0_Init(speed);

		break;
	case ANTI_CLOCKWISE:
		GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);
		GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_HIGH);
		PWM_Timer0_Init(speed);

		break;
	default:
		break;
	}
}
