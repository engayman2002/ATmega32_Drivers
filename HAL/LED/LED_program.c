/*
                <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< LED_progam.c >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
                
                Author: Ayman Mohamed Elasrhy
                Layer : HAL
                SWC   : LED
*/

#include "../../LIB/My_Platform_Types.h"
#include "../../LIB/My_Bit_Cal.h"


#include "../../MCAL/01_DIO/DIO_interface.h"

#include "LED_config.h"
#include "LED_interface.h"
#include "LED_private.h"



LED_Error_Status  LED_init       (LED_t Copy_LED)
{
    LED_Error_Status Check_Status = LED_OK;
    if(Copy_LED.Port<LED_PORTA || Copy_LED.Port>LED_PORTD || Copy_LED.Pin<LED_PIN0 || Copy_LED.Pin>LED_PIN7)
    {
        Check_Status= LED_NOK;
    }
    else
    {
        DIO_enum_SetPinDirection(Copy_LED.Port,Copy_LED.Pin,DIO_PIN_OUTPUT);
    }
    return Check_Status;
}

LED_Error_Status  LED_Setting    (LED_t Copy_LED,uint8_t Status)
{
    
    LED_Error_Status Check_Status = LED_OK;
    if(Copy_LED.Port<LED_PORTA || Copy_LED.Port>LED_PORTD || Copy_LED.Pin<LED_PIN0 || Copy_LED.Pin>LED_PIN7 || Status!=LED_ON || Status!=LED_OFF)
    {
        Check_Status= LED_NOK;
    }
    else
    {
        if(Copy_LED.Active_State==ACTIVE_LOW)
        {
            Status= !Status;
        }
        DIO_enum_SetPinValue(Copy_LED.Port,Copy_LED.Pin,Status);
    }
    return Check_Status;
}

LED_Error_Status  LED_Toggle     (LED_t Copy_LED)
{
    LED_Error_Status Check_Status = LED_OK;
    if(Copy_LED.Port<LED_PORTA || Copy_LED.Port>LED_PORTD || Copy_LED.Pin<LED_PIN0 || Copy_LED.Pin>LED_PIN7)
    {
        Check_Status= LED_NOK;
    }
    else
    {
        DIO_enum_TogglePinValue(Copy_LED.Port,Copy_LED.Pin);
    }
    return Check_Status;
}
