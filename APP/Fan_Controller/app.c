/******************************************************************************
 * @file   : app.c
 * @brief  :
 * @author : Abdelrahman Mohamed
 * @date   :
 * @version: v1.0
 * @Target : ATMEGA32 MCU (AVR)
 *******************************************************************************/

#include "app.h"
#include "../LIB_DRIVERS/STD_TYPES.h"
#include "../MCAL_DRIVERS/ADC/adc.h"
#include "../HAL_DRIVERS/LCD/lcd.h"
#include "../HAL_DRIVERS/DC_MOTOR/dcmotor.h"

/**
 * ADC CONFIG
 *
 * ADC driver should configure to operate using the internal reference voltage 2.56
 * voltage and prescaler F_CPU/8.
 *  **/

void app_main(void) {
	/*         System Initialization         */

	APP_FanControl_INIT();

	/*         Super Loop         */
	for (;;) {

		APP_FanControl_logic();
	}
}
void APP_FanControl_INIT(void) {

	/****** Config ********/

	ADC_ConfigType adc_conf = { .ref_voltage = ADC_INTERNAL, .prescaler =
			ADC_PRESCALAR_8 };

	/**** Init Drivers ****/
	ADC_init(&adc_conf);
	LCD_init();
	DcMotor_Init();

	/**************LCD Init *****************/
	LCD_displayString("Fan is  ");
	LCD_sendCommand(0xC0);
	LCD_displayString("Temp =    C");
}
/**
 *
 */
void APP_FanControl_logic(void) {
	uint8 temp_value = 0;
	temp_value = SENSOR_LM35_READ();
	LCD_moveCursor(1, 7);
	LCD_intgerToString(temp_value);
	if (temp_value < 30) {
		DcMotor_Rotate(STOP, 0);
		LCD_moveCursor(0, 7);
		LCD_displayString("OFF");
	} else if (temp_value < 60) {
		DcMotor_Rotate(CLOCKWISE, 25);
		LCD_moveCursor(0, 7);
		LCD_displayString("ON ");
	} else if (temp_value < 90) {
		DcMotor_Rotate(CLOCKWISE, 50);
		LCD_moveCursor(0, 7);
		LCD_displayString("ON ");
	} else if (temp_value < 120) {
		DcMotor_Rotate(CLOCKWISE, 75);
		LCD_moveCursor(0, 7);
		LCD_displayString("ON ");
		LCD_displayString("   ");
	} else if (temp_value >= 120) {
		DcMotor_Rotate(CLOCKWISE, 100);
		LCD_moveCursor(0, 7);
		LCD_displayString("ON ");
	} else {
		DcMotor_Rotate(STOP, 0);
		LCD_moveCursor(0, 7);
		LCD_displayString("ERROR");
	}
	/***Clean Screen ****/
	if (temp_value < 100) {
		LCD_moveCursor(1, 9);
		LCD_displayString(" ");
	}
}
