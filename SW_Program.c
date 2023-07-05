/*
 * SW_Program.c
 *
 * Created: 7/4/2023 7:55:53 PM
 *  Author: Abdallah Medhat
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include <util\delay.h>

#include "DIO_INTERFACE.h"


#include "SW_Interface.h"
#include "SW_Private.h"
#include "SW_Config.h"


//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
* Breif : This Function initialize the pin which connected to Push Button as Pull Up Input pin
* Parameters :   => struct has the switch porn , pin , status
* return : void
*/
void SW_Init      ( SW_Type SW_Config ){
	
	Dio_SetPinDirection( SW_Config.Port , SW_Config.Pin , DIO_PIN_INPUT );
	
	/* If Sw is Internal Pull Up */
	if( SW_Config.Pull_State == SW_Int_PULL_UP ){
		
		Dio_SetPinValue( SW_Config.Port , SW_Config.Pin , DIO_PIN_HIGH  );
		
		/* we could use DIO_enumConnectPullup */
	}
	
}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
* Breif : This Function read Button status
* Parameters :   => struct has the switch porn , pin , status
* return : switch status
*/

  u8 SW_u8GetPressed ( SW_Type SW_Config ){
	
u8 read_value=0;

/*
	u8 LOC_u8Result = SW_NOT_PRESSED ;
	u8 LOC_u8PinVal = SW_NOT_PRESSED ;
	*/

	if ( (SW_Config.Pull_State == SW_Int_PULL_UP) || (SW_Config.Pull_State == SW_Ext_PULL_UP) )
	{
	  read_value=Dio_GetPinValue( SW_Config.Port , SW_Config.Pin );
		
		if (read_value==0)
		{
			read_value = SW_PRESSED ;
		}
		else if (read_value==1)
		{
			read_value = SW_NOT_PRESSED ;
		}

	}
	else if (SW_Config.Pull_State == SW_Ext_PULL_DOWN)
	{
		read_value=	Dio_GetPinValue( SW_Config.Port , SW_Config.Pin);
		
		if (read_value==0)
		{
			read_value = SW_NOT_PRESSED ;
		}
		else if (read_value==1)
		{
			read_value = SW_PRESSED ;
		}
	}
	
	return read_value ;
	
}