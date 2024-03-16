/*
                <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Seven_Segment_program.c >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
                
                Author: Ayman Mohamed Elasrhy
                Layer : HAL
                SWC   : Seven_Segment
*/

#include "../../MCAL/01_DIO/DIO_interface.h"
#include "../../LIB/My_Platform_Types.h"
#include "../../LIB/My_Bit_Cal.h"

#include "Seven_Segment_interface.h"
#include "Seven_Segment_private.h"
#include "Seven_Segment_config.h"

uint8_t Ten_Numbers[10]=nums;

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< 8 bits Seven Segment (Without Decoder) >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

SS_Error_State   SS_8bits_Init      (Seven_Segment_8_bits My_Sev)
{
    SS_Error_State Check_Status = SS_OK;
    if(My_Sev.Port<SS_PORTA || My_Sev.Port>SS_PORTD || My_Sev.Active_State!=Common_Anode || My_Sev.Active_State!=Common_Cathode )
    {
        Check_Status =SS_NOK;
    }
    else
    {
        DIO_enum_SetPortDirection(My_Sev.Port,DIO_PORT_INPUT);
    }
    return Check_Status;
}



SS_Error_State   SS_8bits_SetValue  (Seven_Segment_8_bits My_Sev,uint8_t Value)
{
    uint16_t Printed_Value;
    SS_Error_State Check_Status = SS_OK;
    if(My_Sev.Port<SS_PORTA || My_Sev.Port>SS_PORTD || My_Sev.Active_State!=Common_Anode || My_Sev.Active_State!=Common_Cathode || Value>9 )
    {
        Check_Status =SS_NOK;
    }
    else
    {
        Printed_Value==Ten_Numbers[Value];
        if(My_Sev.Active_State==Common_Anode)
        {
            Printed_Value = ~Printed_Value;
        }
        DIO_enum_SetPortValue(My_Sev.Port,Printed_Value);
    }
    return Check_Status;
}


// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< 4 bits Seven Segment (Decoder Required) >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

SS_Error_State   SS_4bits_Init      (Seven_Segment_4_bits My_Sev)
{
    SS_Error_State Check_Status = SS_OK;
    if(My_Sev.Port<SS_PORTA || My_Sev.Port>SS_PORTD || My_Sev.Active_State!=Common_Anode || My_Sev.Active_State!=Common_Cathode || My_Sev.Nibble!=SS_Low_Nibble || My_Sev.Nibble!=SS_High_Nibble )
    {
        Check_Status =SS_NOK;
    }
    else
    {
        if(My_Sev.Nibble==SS_Low_Nibble)
        {
            DIO_enum_Set_LowNibble_PortDirection(My_Sev.Port,DIO_PORT_INPUT);
        }
        else // High Nibble
        {
            DIO_enum_Set_HighNibble_PortDirection(My_Sev.Port,DIO_PORT_INPUT);
        }
    }
    return Check_Status;
}


SS_Error_State   SS_4bits_SetValue  (Seven_Segment_4_bits My_Sev,uint8_t Value)
{
    SS_Error_State Check_Status = SS_OK;
    if(My_Sev.Port<SS_PORTA || My_Sev.Port>SS_PORTD || My_Sev.Active_State!=Common_Anode || My_Sev.Active_State!=Common_Cathode || Value>9 )
    {
        Check_Status =SS_NOK;
    }
    else
    {
        if(My_Sev.Active_State==Common_Anode)
        {
            Value = ~Value;
        }

        switch (My_Sev.Nibble)
        {
        case SS_Low_Nibble:
            DIO_enum_Set_LowNibble_PortValue(My_Sev.Port,Value);
            break;
        
        case SS_High_Nibble:
            DIO_enum_Set_HighNibble_PortValue(My_Sev.Port,Value);
            break;
        }
        
        
    }
    return Check_Status;
}

