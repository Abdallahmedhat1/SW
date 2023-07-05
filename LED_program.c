/*
 * LED_program.c
 *
 * Created: 7/2/2023 2:13:29 PM
 *  Author: Abdallah Medhat
 */ 
#include "LED_interface.h"
void LED_Init   (LED_Type LED_Configuration)
{
	
	Dio_SetPinDirection(LED_Configuration.Port,LED_Configuration.Pin,DIO_PIN_OUTPUT);
}



void LED_On     (LED_Type LED_Configuration)
   {
	            if(LED_Configuration.Active_State==ACTIVE_HIGH)
                            	{
	                               	Dio_SetPinValue(LED_Configuration.Port,LED_Configuration.Pin,DIO_PIN_HIGH);
	                                }
	                             else if(LED_Configuration.Active_State==ACTIVE_LOW)
	                            {
		                                Dio_SetPinValue(LED_Configuration.Port,LED_Configuration.Pin,DIO_PIN_LOW);
		
	                                   }
	
  }
  
  
  
void LED_Off    (LED_Type LED_Configuration)
 {
	                     if(LED_Configuration.Active_State==ACTIVE_HIGH)
	               {
		                  Dio_SetPinValue(LED_Configuration.Port,LED_Configuration.Pin,DIO_PIN_LOW);
	                  }
	                                else if(LED_Configuration.Active_State==ACTIVE_LOW)
	                          {
		                          Dio_SetPinValue(LED_Configuration.Port,LED_Configuration.Pin,DIO_PIN_HIGH);
		
	                                 }
	
 }
 
 
 
void LED_Toggle (LED_Type LED_Configuration)
        {
	               Dio_TogglePin(LED_Configuration.Port,LED_Configuration.Pin);
              }
