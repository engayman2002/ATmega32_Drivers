/*
                <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< LED_interface.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
                
                Author: Ayman Mohamed Elasrhy
                Layer : HAL
                SWC   : LED
*/
#include "../../LIB/My_Platform_Types.h"


#ifndef _LED_INTERFACE_H_
#define _LED_INTERFACE_H_

typedef enum{
    LED_NOK,
    LED_OK
}LED_Error_Status;

typedef struct
{
    uint8_t Port;
    uint8_t Pin;
    uint8_t Active_State;
}LED_t;


// Choose the Port from here
#define LED_PORTA ((uint8_t)0)
#define LED_PORTB ((uint8_t)1)
#define LED_PORTC ((uint8_t)2)
#define LED_PORTD ((uint8_t)3)

// Choose the Pin from here
#define LED_PIN0 ((uint8_t)0)
#define LED_PIN1 ((uint8_t)1)
#define LED_PIN2 ((uint8_t)2)
#define LED_PIN3 ((uint8_t)3)
#define LED_PIN4 ((uint8_t)4)
#define LED_PIN5 ((uint8_t)5)
#define LED_PIN6 ((uint8_t)6)
#define LED_PIN7 ((uint8_t)7)

// Choose LED Status
#define LED_ON  ((uint8_t)1)
#define LED_OFF ((uint8_t)0)

// Choose Active State
#define ACTIVE_HIGH  ((uint8_t)1)
#define ACTIVE_LOW   ((uint8_t)0)

extern LED_Error_Status  LED_init       (LED_t Copy_LED);
extern LED_Error_Status  LED_Setting    (LED_t Copy_LED,uint8_t Status);
extern LED_Error_Status  LED_Toggle     (LED_t Copy_LED);




#endif