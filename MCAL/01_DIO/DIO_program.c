/*
                <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< DIO_program.c >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
                
                Author: Ayman Mohamed Elasrhy
                Layer : MCAL
                SWC   : DIO/GPIO
*/

#include "My_Platform_Types.h"
#include "My_Bit_Cal.h"

#include "DIO_config.h"
#include "DIO_interface.h"
#include "DIO_private.h"

// ---------------------- Functions for Specific Bit in Port ----------------------

DIO_Error_Status     DIO_enum_SetPinDirection    (uint8_t Copy_PORT,uint8_t Copy_PIN,uint8_t Copy_Direction)
{
    DIO_Error_Status Check_Status = DIO_OK;

    // Important for Validation
    if( Copy_PORT<DIO_PORTA || Copy_PORT>DIO_PORTD || Copy_PIN<0 || Copy_PIN>7 || Copy_Direction!=DIO_PIN_INPUT || Copy_Direction!=DIO_PIN_OUTPUT )
    {
        Check_Status = DIO_NOK;
    }
    else
    {

    switch (Copy_PORT)
    {
    case DIO_PORTA:
        Copy_Direction==DIO_PIN_OUTPUT ? SET_BIT(DDRA,Copy_PIN) : CLR_BIT(DDRA,Copy_PIN);
        break;

    case DIO_PORTB:
        Copy_Direction==DIO_PIN_OUTPUT ? SET_BIT(DDRB,Copy_PIN) : CLR_BIT(DDRB,Copy_PIN);
        break;

    case DIO_PORTC:
        Copy_Direction==DIO_PIN_OUTPUT ? SET_BIT(DDRC,Copy_PIN) : CLR_BIT(DDRC,Copy_PIN);
        break;

    case DIO_PORTD:
        Copy_Direction==DIO_PIN_OUTPUT ? SET_BIT(DDRD,Copy_PIN) : CLR_BIT(DDRD,Copy_PIN);
        break;
    }

    }

    return Check_Status;
    
}

DIO_Error_Status     DIO_enum_SetPinValue        (uint8_t Copy_PORT,uint8_t Copy_PIN,uint8_t Copy_Value)
{
    DIO_Error_Status Check_Status=DIO_OK;
    // Important for Validation
    if( Copy_PORT<DIO_PORTA || Copy_PORT>DIO_PORTD || Copy_PIN<0 || Copy_PIN>7 || Copy_Value!=DIO_PIN_HIGH || Copy_Value!=DIO_PIN_LOW)
    {
        Check_Status=DIO_NOK;
    }
    else{
    switch (Copy_PORT)
    {
    case DIO_PORTA:
        Copy_Value==DIO_PIN_HIGH? SET_BIT(PORTA,Copy_PIN) : CLR_BIT(PORTA,Copy_PIN);
        break;
    
    case DIO_PORTB:
        Copy_Value==DIO_PIN_HIGH? SET_BIT(PORTB,Copy_PIN) : CLR_BIT(PORTB,Copy_PIN);
        break;

    case DIO_PORTC:
        Copy_Value==DIO_PIN_HIGH? SET_BIT(PORTC,Copy_PIN) : CLR_BIT(PORTC,Copy_PIN);
        break;

    case DIO_PORTD:
        Copy_Value==DIO_PIN_HIGH? SET_BIT(PORTD,Copy_PIN) : CLR_BIT(PORTD,Copy_PIN);
        break;
    }
    }

    return Check_Status;

    
}

DIO_Error_Status     DIO_enum_GetPinValue        (uint8_t Copy_PORT,uint8_t Copy_PIN,uint8_t *Copy_PtrData)
{
    DIO_Error_Status Check_Status = DIO_OK;
    // Important for Validation
    if( Copy_PORT<DIO_PORTA || Copy_PORT>DIO_PORTD || Copy_PIN<0 || Copy_PIN>7 )
    {
        Check_Status = DIO_NOK;
    }
    else
    {
    switch (Copy_PORT)
    {
    case DIO_PORTA:
        *Copy_PtrData=GET_BIT(PINA,Copy_PIN);
        break;

    case DIO_PORTB:
        *Copy_PtrData=GET_BIT(PINB,Copy_PIN);
        break;

    case DIO_PORTC:
        *Copy_PtrData=GET_BIT(PINC,Copy_PIN);
        break;

    case DIO_PORTD:
        *Copy_PtrData=GET_BIT(PIND,Copy_PIN);
        break;
    }
    }

    return Check_Status;
    

    
}

DIO_Error_Status     DIO_enum_TogglePinValue     (uint8_t Copy_PORT,uint8_t Copy_PIN)
{
    DIO_Error_Status Check_Status=DIO_OK;
    // Important for Validation
    if( Copy_PORT<DIO_PORTA || Copy_PORT>DIO_PORTD || Copy_PIN<0 || Copy_PIN>7)
    {
        Check_Status=DIO_NOK;
    }
    else
    {
    switch(Copy_PORT)
    {
        case DIO_PORTA:
            TOG_BIT(PORTA,Copy_PIN);
            break;

        case DIO_PORTB:
            TOG_BIT(PORTB,Copy_PIN);
            break;

        case DIO_PORTC:
            TOG_BIT(PORTC,Copy_PIN);
            break;

        case DIO_PORTD:
            TOG_BIT(PORTD,Copy_PIN);
            break;
    }
    }

    return Check_Status;
}

// ---------------------- Functions for the Port ----------------------

DIO_Error_Status     DIO_enum_SetPortDirection   (uint8_t Copy_PORT,uint8_t Copy_Direction)
{
    DIO_Error_Status Check_Status = DIO_OK;
    // Important for Validation
    if( Copy_PORT<DIO_PORTA || Copy_PORT>DIO_PORTD || Copy_Direction!=DIO_PIN_INPUT || Copy_Direction!=DIO_PIN_OUTPUT )
    {
        Check_Status = DIO_NOK;
    }
    else
    {
    switch (Copy_PORT)
    {
    case DIO_PORTA:
        DDRA = (Copy_Direction==DIO_PIN_INPUT ? DIO_PORT_INPUT : DIO_PORT_OUTPUT );
        break;

    case DIO_PORTB:
        DDRB = (Copy_Direction==DIO_PIN_INPUT ? DIO_PORT_INPUT : DIO_PORT_OUTPUT );
        break;

    case DIO_PORTC:
        DDRC = (Copy_Direction==DIO_PIN_INPUT ? DIO_PORT_INPUT : DIO_PORT_OUTPUT );
        break;

    case DIO_PORTD:
        DDRD = (Copy_Direction==DIO_PIN_INPUT ? DIO_PORT_INPUT : DIO_PORT_OUTPUT );
        break;
    }
    }

    return Check_Status;
    
}

DIO_Error_Status     DIO_enum_SetPortValue       (uint8_t Copy_PORT,uint8_t Copy_Value)
{
    DIO_Error_Status Check_Status = DIO_OK;
    // Important for Validation
    if( Copy_PORT<DIO_PORTA || Copy_PORT>DIO_PORTD)
    {
        Check_Status = DIO_NOK;
    }
    else
    {
        switch (Copy_PORT)
    {
    case DIO_PORTA:
        PORTA=Copy_Value;
        break;
    case DIO_PORTB:
        PORTB=Copy_Value;
        break;
    case DIO_PORTC:
        PORTC=Copy_Value;
        break;
    case DIO_PORTD:
        PORTD=Copy_Value;
        break;
    }
    }

    return Check_Status;  
}

DIO_Error_Status     DIO_enum_GetPortValue       (uint8_t Copy_PORT,uint8_t *Copy_PtrData)
{
    DIO_Error_Status Check_Status = DIO_OK;
    // Important for Validation
    if( Copy_PORT<DIO_PORTA || Copy_PORT>DIO_PORTD)
    {
        Check_Status = DIO_NOK;
    }
    else
    {
    switch (Copy_PORT)
    {
    case DIO_PORTA:
        *Copy_PtrData=PINA;
        break;

    case DIO_PORTB:
        *Copy_PtrData=PINB;
        break;

    case DIO_PORTC:
        *Copy_PtrData=PINC;
        break;

    case DIO_PORTD:
        *Copy_PtrData=PIND;
        break;
    }
    }

    return Check_Status;
}

DIO_Error_Status     DIO_enum_TogglePortValue    (uint8_t Copy_PORT)
{
    DIO_Error_Status Check_Status = DIO_OK;
    // Important for Validation
    if( Copy_PORT<DIO_PORTA || Copy_PORT>DIO_PORTD)
    {
        Check_Status = DIO_NOK;
    }
    else
    {
    switch (Copy_PORT)
    {
    case DIO_PORTA:
        PORTA = (~PINA);
        break;

    case DIO_PORTB:
        PORTB = (~PINB);
        break;

    case DIO_PORTC:
        PORTC = (~PINC);
        break;

    case DIO_PORTD:
        PORTD = (~PIND);
        break;
    }
    }

    return Check_Status;
    
}

// ---------------------- Functions for the Low Nibble in the Port ----------------------

DIO_Error_Status     DIO_enum_Set_LowNibble_PortDirection   (uint8_t Copy_PORT,uint8_t Copy_Direction)
{
    DIO_Error_Status Check_Status = DIO_OK;
    // Important for Validation
    if( Copy_PORT<DIO_PORTA || Copy_PORT>DIO_PORTD || Copy_Direction!=DIO_PORT_INPUT || Copy_Direction!=DIO_PORT_OUTPUT)
    {
        Check_Status = DIO_NOK;
    }
    else
    {
        switch(Copy_PORT)
        {
            case DIO_PORTA:
            Copy_Direction==DIO_PORT_INPUT?/*INPUT Process*/(PORTA&=0xf0):/*OUTPUT Process*/(PORTA|=0x0f);
            break;

            case DIO_PORTB:
            Copy_Direction==DIO_PORT_INPUT?/*INPUT Process*/(PORTB&=0xf0):/*OUTPUT Process*/(PORTB|=0x0f);
            break;

            case DIO_PORTC:
            Copy_Direction==DIO_PORT_INPUT?/*INPUT Process*/(PORTC&=0xf0):/*OUTPUT Process*/(PORTC|=0x0f);
            break;

            case DIO_PORTD:
            Copy_Direction==DIO_PORT_INPUT?/*INPUT Process*/(PORTD&=0xf0):/*OUTPUT Process*/(PORTD|=0x0f);
            break;
        }
    }
    return Check_Status;
}

DIO_Error_Status     DIO_enum_Set_LowNibble_PortValue       (uint8_t Copy_PORT,uint8_t Copy_Value)
{
    DIO_Error_Status Check_Status = DIO_OK;
    // Important for Validation
    if( Copy_PORT<DIO_PORTA || Copy_PORT>DIO_PORTD)
    {
        Check_Status = DIO_NOK;
    }
    else
    {
        Copy_Value&=0x0f;
        switch (Copy_PORT)
        {
        case DIO_PORTA:
                PORTA&=0xf0;
                PORTA|=Copy_Value;
            break;
        
        case DIO_PORTB:
                PORTB&=0xf0;
                PORTB|=Copy_Value;
            break;

        case DIO_PORTC:
                PORTC&=0xf0;
                PORTC|=Copy_Value;
            break;

        case DIO_PORTD:
                PORTD&=0xf0;
                PORTD|=Copy_Value;
            break;
        }
    }
    return Check_Status;

}

DIO_Error_Status     DIO_enum_Get_LowNibble_PortValue       (uint8_t Copy_PORT,uint8_t *Copy_PtrData)
{
    DIO_Error_Status Check_Status = DIO_OK;
    // Important for Validation
    if( Copy_PORT<DIO_PORTA || Copy_PORT>DIO_PORTD)
    {
        Check_Status = DIO_NOK;
    }
    else
    {
        *Copy_PtrData=0x00;

        switch (Copy_PORT)
        {
        case DIO_PORTA:
                *Copy_PtrData= PINA & 0x0f;
            break;

        case DIO_PORTB:
                *Copy_PtrData= PINB & 0x0f;
            break;

        case DIO_PORTC:
                *Copy_PtrData= PINC & 0x0f;
            break;

        case DIO_PORTD:
                *Copy_PtrData= PIND & 0x0f;
            break;
        }
    }
    return Check_Status;
}

DIO_Error_Status     DIO_enum_Toggle_LowNibble_PortValue    (uint8_t Copy_PORT)
{
    DIO_Error_Status Check_Status = DIO_OK;
    // Important for Validation
    if( Copy_PORT<DIO_PORTA || Copy_PORT>DIO_PORTD)
    {
        Check_Status = DIO_NOK;
    }
    else
    {
        switch (Copy_PORT)
        {
        case DIO_PORTA:
                PORTA = PINA ^ (0x0f);
            break;
        
        case DIO_PORTB:
                PORTB = PINB ^ (0x0f);
            break;

        case DIO_PORTC:
                PORTC = PINC ^ (0x0f);
            break;

        case DIO_PORTD:
                PORTD = PIND ^ (0x0f);
            break;
        }
    }
    return Check_Status;
}


// ---------------------- Functions for the High Nibble in the Port ----------------------
DIO_Error_Status     DIO_enum_Set_HighNibble_PortDirection   (uint8_t Copy_PORT,uint8_t Copy_Direction)
{
    DIO_Error_Status Check_Status = DIO_OK;
    // Important for Validation
    if( Copy_PORT<DIO_PORTA || Copy_PORT>DIO_PORTD || Copy_Direction!=DIO_PORT_INPUT || Copy_Direction!=DIO_PORT_OUTPUT)
    {
        Check_Status = DIO_NOK;
    }
    else
    {
        switch(Copy_PORT)
        {
            case DIO_PORTA:
            Copy_Direction==DIO_PORT_INPUT?/*INPUT Process*/(PORTA&=0x0f):/*OUTPUT Process*/(PORTA|=0xf0);
            break;

            case DIO_PORTB:
            Copy_Direction==DIO_PORT_INPUT?/*INPUT Process*/(PORTB&=0x0f):/*OUTPUT Process*/(PORTB|=0xf0);
            break;

            case DIO_PORTC:
            Copy_Direction==DIO_PORT_INPUT?/*INPUT Process*/(PORTC&=0x0f):/*OUTPUT Process*/(PORTC|=0xf0);
            break;

            case DIO_PORTD:
            Copy_Direction==DIO_PORT_INPUT?/*INPUT Process*/(PORTD&=0x0f):/*OUTPUT Process*/(PORTD|=0xf0);
            break;
        }
    }
    return Check_Status;
}

DIO_Error_Status     DIO_enum_Set_HighNibble_PortValue       (uint8_t Copy_PORT,uint8_t Copy_Value)
{
    DIO_Error_Status Check_Status = DIO_OK;
    // Important for Validation
    if( Copy_PORT<DIO_PORTA || Copy_PORT>DIO_PORTD)
    {
        Check_Status = DIO_NOK;
    }
    else
    {
        Copy_Value = Copy_Value<<4; // 0bxxxx0000
        switch (Copy_PORT)
        {
        case DIO_PORTA:
                PORTA&=0x0f;
                PORTA|=Copy_Value;
            break;
        
        case DIO_PORTB:
                PORTB&=0x0f;
                PORTB|=Copy_Value;
            break;

        case DIO_PORTC:
                PORTC&=0x0f;
                PORTC|=Copy_Value;
            break;

        case DIO_PORTD:
                PORTD&=0x0f;
                PORTD|=Copy_Value;
            break;
        }
    }
    return Check_Status;
}

DIO_Error_Status     DIO_enum_Get_HighNibble_PortValue       (uint8_t Copy_PORT,uint8_t *Copy_PtrData)
{
    DIO_Error_Status Check_Status = DIO_OK;
    // Important for Validation
    if( Copy_PORT<DIO_PORTA || Copy_PORT>DIO_PORTD)
    {
        Check_Status = DIO_NOK;
    }
    else
    {
        *Copy_PtrData=0x00;
        
        switch (Copy_PORT)
        {
        case DIO_PORTA:
                *Copy_PtrData= (PINA>>4);
            break;

        case DIO_PORTB:
                *Copy_PtrData= (PINB>>4);
            break;

        case DIO_PORTC:
                *Copy_PtrData= (PINC>>4);
            break;

        case DIO_PORTD:
                *Copy_PtrData= (PIND>>4);
            break;
        }
    }
    return Check_Status;
}

DIO_Error_Status     DIO_enum_Toggle_HighNibble_PortValue    (uint8_t Copy_PORT)
{
    DIO_Error_Status Check_Status = DIO_OK;
    // Important for Validation
    if( Copy_PORT<DIO_PORTA || Copy_PORT>DIO_PORTD)
    {
        Check_Status = DIO_NOK;
    }
    else
    {
        switch (Copy_PORT)
        {
        case DIO_PORTA:
                PORTA = PINA ^ (0xf0);
            break;
        
        case DIO_PORTB:
                PORTB = PINB ^ (0xf0);
            break;

        case DIO_PORTC:
                PORTC = PINC ^ (0xf0);
            break;

        case DIO_PORTD:
                PORTD = PIND ^ (0xf0);
            break;
        }
    }
    return Check_Status;
}