/*
                <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< DIO_private.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
                
                Author: Ayman Mohamed Elasrhy
                Layer : MCAL
                SWC   : DIO/GPIO
*/
#include "My_Platform_Types.h"

#ifndef _DIO_PRIVATE_H_
#define _DIO_PRIVATE_H_

// <<<<<<<< Groups Definitons >>>>>>>>>

// Register Definition of Group A
#define PORTA (*(vuint8_t*)((vuint8_t*)0x3b))
#define DDRA  (*(vuint8_t*)((vuint8_t*)0x3a))
#define PINA  (*(vuint8_t*)((vuint8_t*)0x39))

// Register Definition of Group B
#define PORTB (*(vuint8_t*)((vuint8_t*)0x38))
#define DDRB  (*(vuint8_t*)((vuint8_t*)0x37))
#define PINB  (*(vuint8_t*)((vuint8_t*)0x36))

// Register Definition of Group C
#define PORTC (*(vuint8_t*)((vuint8_t*)0x35))
#define DDRC  (*(vuint8_t*)((vuint8_t*)0x34))
#define PINC  (*(vuint8_t*)((vuint8_t*)0x33))

// Register Definition of Group D
#define PORTD (*(vuint8_t*)((vuint8_t*)0x32))
#define DDRD  (*(vuint8_t*)((vuint8_t*)0x31))
#define PIND  (*(vuint8_t*)((vuint8_t*)0x30))







#endif