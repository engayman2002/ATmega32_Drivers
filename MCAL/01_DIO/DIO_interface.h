/*
                <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< DIO_interface.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
                
                Author: Ayman Mohamed Elasrhy
                Layer : MCAL
                SWC   : DIO/GPIO
*/
#include "My_Platform_Types.h"

#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_

typedef enum{
    DIO_NOK,
    DIO_OK
}DIO_Error_Status;

// Type the status of Pin
#define DIO_PIN_OUTPUT ((uint8_t)1)
#define DIO_PIN_INPUT  ((uint8_t)0)

// Set Pin with Low or High
#define DIO_PIN_LOW  ((uint8_t)0)
#define DIO_PIN_HIGH ((uint8_t)1)

// Choose the Port from here
#define DIO_PORTA ((uint8_t)0)
#define DIO_PORTB ((uint8_t)1)
#define DIO_PORTC ((uint8_t)2)
#define DIO_PORTD ((uint8_t)3)

// Choose the Pin from here
#define DIO_PIN0 ((uint8_t)0)
#define DIO_PIN1 ((uint8_t)1)
#define DIO_PIN2 ((uint8_t)2)
#define DIO_PIN3 ((uint8_t)3)
#define DIO_PIN4 ((uint8_t)4)
#define DIO_PIN5 ((uint8_t)5)
#define DIO_PIN6 ((uint8_t)6)
#define DIO_PIN7 ((uint8_t)7)

// PORT Direction
#define DIO_PORT_OUTPUT ((uint8_t)0xff)
#define DIO_PORT_INPUT  ((uint8_t)0x00)

// PORT Value Options
#define DIO_PORT_HIGH ((uint8_t)0xff)
#define DIO_PORT_LOW  ((uint8_t)0x00)


// Functions for Specific Bit in Port
extern DIO_Error_Status     DIO_enum_SetPinDirection    (uint8_t Copy_PORT,uint8_t Copy_PIN,uint8_t Copy_Direction);
extern DIO_Error_Status     DIO_enum_SetPinValue        (uint8_t Copy_PORT,uint8_t Copy_PIN,uint8_t Copy_Value);
extern DIO_Error_Status     DIO_enum_GetPinValue        (uint8_t Copy_PORT,uint8_t Copy_PIN,uint8_t *Copy_PtrData);
extern DIO_Error_Status     DIO_enum_TogglePinValue     (uint8_t Copy_PORT,uint8_t Copy_PIN);

// Functions for the Port
extern DIO_Error_Status     DIO_enum_SetPortDirection   (uint8_t Copy_PORT,uint8_t Copy_Direction);
extern DIO_Error_Status     DIO_enum_SetPortValue       (uint8_t Copy_PORT,uint8_t Copy_Value);
extern DIO_Error_Status     DIO_enum_GetPortValue       (uint8_t Copy_PORT,uint8_t *Copy_PtrData);
extern DIO_Error_Status     DIO_enum_TogglePortValue    (uint8_t Copy_PORT);

// Functions for the Low Nibble in the Port
extern DIO_Error_Status     DIO_enum_Set_LowNibble_PortDirection   (uint8_t Copy_PORT,uint8_t Copy_Direction);
extern DIO_Error_Status     DIO_enum_Set_LowNibble_PortValue       (uint8_t Copy_PORT,uint8_t Copy_Value);
extern DIO_Error_Status     DIO_enum_Get_LowNibble_PortValue       (uint8_t Copy_PORT,uint8_t *Copy_PtrData);
extern DIO_Error_Status     DIO_enum_Toggle_LowNibble_PortValue    (uint8_t Copy_PORT);

// Functions for the High Nibble in the Port
extern DIO_Error_Status     DIO_enum_Set_HighNibble_PortDirection   (uint8_t Copy_PORT,uint8_t Copy_Direction);
extern DIO_Error_Status     DIO_enum_Set_HighNibble_PortValue       (uint8_t Copy_PORT,uint8_t Copy_Value);
extern DIO_Error_Status     DIO_enum_Get_HighNibble_PortValue       (uint8_t Copy_PORT,uint8_t *Copy_PtrData);
extern DIO_Error_Status     DIO_enum_Toggle_HighNibble_PortValue    (uint8_t Copy_PORT);


#endif