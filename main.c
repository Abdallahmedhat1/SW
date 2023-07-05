/*
 * SW.c
 *
 * Created: 7/4/2023 7:54:25 PM
 * Author : Abdallah Medhat
 */ 

#include "SW_Interface.h"
#include "LED_interface.h"


int main(void)
{
	
	LED_Type LED={DIO_PORTA,DIO_PIN2,ACTIVE_HIGH};
		
    SW_Type SW={DIO_PORTA,DIO_PIN0,SW_Ext_PULL_DOWN };
		
		SW_Init(SW);
		
		LED_Init(LED);
		
		
    while (1) 
    {
		u8 read_Sw=0;
		
		 read_Sw=SW_u8GetPressed (SW);
		
		if(read_Sw==1)
		{
			LED_On(LED);
		}
		
		else if(read_Sw==0)
		{
			LED_Off(LED);
		}
		
		
    }
}

