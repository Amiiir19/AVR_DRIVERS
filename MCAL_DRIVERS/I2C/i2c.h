/******************************************************************************
 *
 * Module: TWI (I2C)
 *
 * File Name: TWI.h
 *
 * Description: Header file for the TWI (Two Wire Interface) (I2C) AVR driver
 *
 * Author: Abdelrahman Mohamed
 *
 *******************************************************************************/

#ifndef TWI_H_
#define TWI_H_

#include "../../LIB_DRIVERS/STD_TYPES.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

/* TWI Status Bits in the TWSR Register */
#define TWI_START 0x08		  /* start has been sent */
#define TWI_REP_START 0x10	  /* repeated start */
#define TWI_MT_SLA_W_ACK 0x18 /* Master transmit ( slave address + Write request ) to slave + ACK received from slave. */
#define TWI_MT_SLA_R_ACK 0x40 /* Master transmit ( slave address + Read request ) to slave + ACK received from slave. */
#define TWI_MT_DATA_ACK 0x28  /* Master transmit data and ACK has been received from Slave. */
#define TWI_MR_DATA_ACK 0x50  /* Master received data and send ACK to slave. */
#define TWI_MR_DATA_NACK 0x58 /* Master received data but doesn't send ACK to slave. */

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum
{
	NormalMode_100Kb = 100000,
	FastMode_400Kb = 400000,
	FastModePlus_1Mb = 1000000,
	HighSpeedMode_3Mb = 3400000
} SCL_Frquency;

typedef enum
{
	TWI_Prescaler_1,
	TWI_Prescaler_4,
	TWI_Prescaler_16,
	TWI_Prescaler_64

} TWI_Prescaler;

typedef enum
{
	TWI_GeneralCallRecognitionEnable_OFF,
	TWI_GeneralCallRecognitionEnable_ON
} TWI_GENERAL_CALL_RECOGNITION_ENABLE_MODE;

typedef struct
{
	SCL_Frquency SCL_Frq;
	TWI_Prescaler prescaler;
	TWI_GENERAL_CALL_RECOGNITION_ENABLE_MODE generalCallRecognitionEnableModeConfig;
	uint8 TWI_slaveAddress;
} TWI_configType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void TWI_init(const TWI_configType *Config_Ptr);
void TWI_start(void);
void TWI_stop(void);
void TWI_writeByte(uint8 data);
uint8 TWI_readByteWithACK(void);  // read with send Ack
uint8 TWI_readByteWithNACK(void); // read without send Ack
uint8 TWI_getStatus(void);

#endif /* TWI_H_ */
