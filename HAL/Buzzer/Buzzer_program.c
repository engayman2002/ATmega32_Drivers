/*
                <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Buzzer_progam.c >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
                
                Author: Ayman Mohamed Elasrhy
                Layer : HAL
                SWC   : LED
*/

#include "My_Platform_Types.h"
#include "My_Bit_Cal.h"

#include "../../MCAL/01_DIO/DIO_interface.h"

#include "Buzzer_config.h"
#include "Buzzer_interface.h"
#include "Buzzer_private.h"



Buzzer_Error_Status  Buzzer_init       (Buzzer_t Copy_Buzzer)
{
    Buzzer_Error_Status Check_Status = Buzzer_OK;
    if(Copy_Buzzer.Port<Buzzer_PORTA || Copy_Buzzer.Port>Buzzer_PORTD || Copy_Buzzer.Pin<Buzzer_PIN0 || Copy_Buzzer.Pin>Buzzer_PIN7)
    {
        Check_Status= Buzzer_NOK;
    }
    else
    {
        DIO_enum_SetPinDirection(Copy_Buzzer.Port,Copy_Buzzer.Pin,DIO_PIN_OUTPUT);
    }
    return Check_Status;
}

Buzzer_Error_Status  Buzzer_Setting    (Buzzer_t Copy_Buzzer,uint8_t Status)
{
    
    Buzzer_Error_Status Check_Status = Buzzer_OK;
    if(Copy_Buzzer.Port<Buzzer_PORTA || Copy_Buzzer.Port>Buzzer_PORTD || Copy_Buzzer.Pin<Buzzer_PIN0 || Copy_Buzzer.Pin>Buzzer_PIN7 || Status!=Buzzer_ON || Status!=Buzzer_OFF)
    {
        Check_Status= Buzzer_NOK;
    }
    else
    {
        if(Copy_Buzzer.Active_State==ACTIVE_LOW)
        {
            Status= !Status;
        }
        DIO_enum_SetPinValue(Copy_Buzzer.Port,Copy_Buzzer.Pin,Status);
    }
    return Check_Status;
}

Buzzer_Error_Status  Buzzer_Toggle     (Buzzer_t Copy_Buzzer)
{
    Buzzer_Error_Status Check_Status = Buzzer_OK;
    if(Copy_Buzzer.Port<Buzzer_PORTA || Copy_Buzzer.Port>Buzzer_PORTD || Copy_Buzzer.Pin<Buzzer_PIN0 || Copy_Buzzer.Pin>Buzzer_PIN7)
    {
        Check_Status= Buzzer_NOK;
    }
    else
    {
        DIO_enum_TogglePinValue(Copy_Buzzer.Port,Copy_Buzzer.Pin);
    }
    return Check_Status;
}
