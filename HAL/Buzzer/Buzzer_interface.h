/*
                <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Buzzer_interface.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
                
                Author: Ayman Mohamed Elasrhy
                Layer : HAL
                SWC   : LED
*/
#include "../../LIB/My_Platform_Types.h"

#ifndef _Buzzer_INTERFACE_H_
#define _Buzzer_INTERFACE_H_

typedef enum{
    Buzzer_NOK,
    Buzzer_OK
}Buzzer_Error_Status;

typedef struct
{
    uint8_t Port;
    uint8_t Pin;
    uint8_t Active_State;
}Buzzer_t;


// Choose the Port from here
#define Buzzer_PORTA ((uint8_t)0)
#define Buzzer_PORTB ((uint8_t)1)
#define Buzzer_PORTC ((uint8_t)2)
#define Buzzer_PORTD ((uint8_t)3)

// Choose the Pin from here
#define Buzzer_PIN0 ((uint8_t)0)
#define Buzzer_PIN1 ((uint8_t)1)
#define Buzzer_PIN2 ((uint8_t)2)
#define Buzzer_PIN3 ((uint8_t)3)
#define Buzzer_PIN4 ((uint8_t)4)
#define Buzzer_PIN5 ((uint8_t)5)
#define Buzzer_PIN6 ((uint8_t)6)
#define Buzzer_PIN7 ((uint8_t)7)

// Choose LED Status
#define Buzzer_ON  ((uint8_t)1)
#define Buzzer_OFF ((uint8_t)0)

// Choose Active State
#define ACTIVE_HIGH  ((uint8_t)1)
#define ACTIVE_LOW   ((uint8_t)0)

extern Buzzer_Error_Status  Buzzer_init       (Buzzer_t Copy_Buzzer);
extern Buzzer_Error_Status  Buzzer_Setting    (Buzzer_t Copy_Buzzer,uint8_t Status);
extern Buzzer_Error_Status  Buzzer_Toggle     (Buzzer_t Copy_Buzzer);




#endif