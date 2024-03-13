#ifndef _MY_BIT_CAL_H_
#define _MY_BIT_CAL_H_

#define SET_BIT(Reg,Bit_NUM) (Reg|=(1<<Bit_NUM))      // Set Bit 
#define CLR_BIT(Reg,Bit_NUM) (Reg&=~(1<<Bit_NUM))     // Clear Bit
#define TOG_BIT(Reg,Bit_NUM) (Reg^=(1<<Bit_NUM))      // Toggle Bit
#define GET_BIT(Reg,Bit_NUM) (Reg&(1<<Bit_NUM)!=0)    // Check if a Specific Bit is Set or Not

#define IS_BIT_SET(Reg,Bit_Num) (Reg&(1<<Bit_NUM)!=0)
#define IS_BIT_CLR(Reg,Bit_Num) (!(Reg&(1<<Bit_NUM)!=0))


#endif