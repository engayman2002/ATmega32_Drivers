/*
                <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Seven_Segment_interface.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
                
                Author: Ayman Mohamed Elasrhy
                Layer : HAL
                SWC   : Seven_Segment
*/

#ifndef _SEVEN_SEGMENT_INTERFACE_H_
#define _S_SEVEN_SEGMENT_INTERFACE_H_

#include "../../LIB/My_Platform_Types.h"

typedef enum
{
    SS_NOK,
    SS_OK
}SS_Error_State;

typedef struct 
{
    uint8_t Active_State;   // Active State (Common Anode or Common Cathode)
    uint8_t Port;           // Port that you want to write on it
    uint8_t Nibble;         // Low Nibble or High Nibble
}Seven_Segment_4_bits; // Here you want to use 4 pins in MC and External Decoder

typedef struct 
{
    uint8_t Active_State;   // Active State (Common Anode or Common Cathode)
    uint8_t Port;           // Port that you want to write on it
}Seven_Segment_8_bits; // Here you want to use 8 pins in MC

// Active State (Common Anode or Common Cathode)
#define Common_Cathode  ((uint8_t)0)
#define Common_Anode    ((uint8_t)1)

// Choose the Port from here
#define SS_PORTA ((uint8_t)0)
#define SS_PORTB ((uint8_t)1)
#define SS_PORTC ((uint8_t)2)
#define SS_PORTD ((uint8_t)3)

// Choose Nibble
#define SS_Low_Nibble   ((uint8_t)0)
#define SS_High_Nibble  ((uint8_t)1)



// 8 bits Seven Segment (Without Decoder)
extern SS_Error_State   SS_8bits_Init      (Seven_Segment_8_bits My_Sev);
extern SS_Error_State   SS_8bits_SetValue  (Seven_Segment_8_bits My_Sev,uint8_t Value);

// 4 bits Seven Segment (Decoder Required)
extern SS_Error_State   SS_4bits_Init      (Seven_Segment_4_bits My_Sev);
extern SS_Error_State   SS_4bits_SetValue  (Seven_Segment_4_bits My_Sev,uint8_t Value);

#endif