/******************************************************************************
 *
 * Module: BITS Useful Macros
 *
 * File Name: BITS_MACROS.h
 *
 * Description: Contains Useful Macros in dealing with Bits
 *
 * Creator: Eng :  Abdelrahman Mohamed Amir
 *
 *******************************************************************************/

#ifndef BITS_MACROS_H
#define BITS_MACROS_H

/* Set Bit To 1 */
#define SET_BIT(reg, bit_num) ((reg) |= (1U << bit_num))
/* Clear Bit To 0 */
#define CLEAR_BIT(reg, bit_num) ((reg) &= ~(1U << bit_num))
/* Toggle Bit */
#define TOGGLE_BIT(reg, bit_num) ((reg) ^= (1U << bit_num))
/* Read Bit */
#define READ_BIT(reg, bit_num) ((reg) >> (bit_num) & (1U))
/* Check if bit set or not */
#define IS_BIT_SET(reg, bit_num) ((reg) & ((1U) << (bit_num)))
/* Check if bit clear or not */
#define IS_BIT_CLEAR(reg, bit_num) (!((reg) & ((1U) << (bit_num))))
/* clear a specific bit and set it with a value 0 or 1 */
#define WRITE_BIT(reg, bit, value)  	((reg) = ((reg & ~(1U << (bit))) | ((value) << (bit))))

/* Set multiple bits based on mask */
#define SET_MASK(reg, mask) 			((reg) |= (mask))

/* Clear multiple bits based on mask */
#define CLEAR_MASK(reg, mask) 			((reg) &= ~(mask))

/* Toggle multiple bits based on mask */
#define TOGGLE_MASK(reg, mask) 			((reg) ^= (mask))

/* Check if a bit is set to 1 and clear it */
#define TEST_AND_CLEAR_BIT(reg, bit) 	(((reg) >> (bit)) & 1U) && CLEAR_BIT(reg, bit)

/* Check if a bit is cleared to 0 and set it */
#define TEST_AND_SET_BIT(reg, bit) 		(!((reg) >> (bit)) & 1U) && SET_BIT(reg, bit)

/* Rotate right the register value with a specific number of rotates */
#define ROR(reg, num) 					((reg) = ((reg >> (num)) | (reg << (8U - (num)))))

/* Rotate left the register value with a specific number of rotates */
#define ROL(reg, num) 					((reg) = ((reg << (num)) | (reg >> (8U - (num)))))

/* Set a bit to 1 */
#define BIT(x) 							(1U << (x))


#endif