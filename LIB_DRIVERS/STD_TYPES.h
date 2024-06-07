/******************************************************************************
 *
 * Module: Types Construction
 *
 * File Name: STD_TYPES.h
 *
 * Description: Types for AVR Controller
 *
 * Creator: Eng :  Abdelrahman Mohamed Amir
 *
 *******************************************************************************/

#ifndef STD_TYPES_H_
#define STD_TYPES_H_


#ifndef FALSE
#define FALSE 				(0u)
#endif
#ifndef TRUE
#define TRUE 				(1u)
#endif

#define LOGIC_HIGH   (1u)
#define LOGIC_LOW   (0u)
#define NULL_PTR  ((void *) 0)

typedef unsigned char boolean;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef unsigned long long uint64;
typedef signed char sint8;
typedef signed short sint16;
typedef signed long sint32;
typedef signed long long sint64;
typedef  float float32;
typedef  double float64;



#endif