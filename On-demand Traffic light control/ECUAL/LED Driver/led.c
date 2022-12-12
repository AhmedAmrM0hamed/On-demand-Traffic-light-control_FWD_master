/*
 * led.c
 *
 *  Created on: Dec 12, 2022
 *  Author: Ahmed Amr
 */ 

#include "led.h"
LED_ERROR_t LED_init(uint8_t ledPort , uint8_t ledPin)
{
	
	if(DIO_init(ledPin , ledPort , OUT) != DIO_OK ){
		return LED_FAILED;
	}
		
	return LED_OK;
}


LED_ERROR_t LED_on (uint8_t ledPort , uint8_t ledPin)
{
	
	if(DIO_write(ledPin , ledPort , HIGH) != DIO_OK ){
		return LED_FAILED;
	}
	
	return LED_OK ;
}


LED_ERROR_t LED_off (uint8_t ledPort , uint8_t ledPin)
{
	
	if(DIO_write(ledPin , ledPort , LOW) != DIO_OK){
		return LED_FAILED;
	}
	
	return LED_OK;
}


LED_ERROR_t LED_toggle (uint8_t ledPort , uint8_t ledPin)
{
	
	if (DIO_toggle(ledPin , ledPort) != DIO_OK){
		return LED_FAILED ;
	}
	
	return LED_OK;
}

/********** same functions as above but for structs ***************/

LED_ERROR_t LED_init_t(LED* led)
{
	if (DIO_init(led->ledPin , led->ledPort , OUT) != DIO_OK ){
		return LED_FAILED;
	}
	
	return LED_OK;
}


LED_ERROR_t LED_on_t (LED* led)
{
	if (DIO_write(led->ledPin , led->ledPort , HIGH) != DIO_OK ){
		return LED_FAILED;
	}
	
	return LED_OK;
}


LED_ERROR_t LED_off_t (LED* led)
{
	if (DIO_write(led->ledPin , led->ledPort , LOW) != DIO_OK ){
		return LED_FAILED;
	}
	
	return LED_OK;
}


LED_ERROR_t LED_toggle_t (LED* led)
{
	if (DIO_toggle(led->ledPin , led->ledPort) != DIO_OK )
	{
		return LED_FAILED;
	}
	
	return LED_OK;
}

/************************************************************************/
/* Testing                                                */
/************************************************************************/

/*

int main (void) {
	
	LED_init(PORTn_A , 0);
	
	LED_on(PORTn_A , 0);
	
	LED ledaya = {0 , PORTn_B};
		
	LED_init_t(&ledaya);
	
	LED_on_t(&ledaya);
	
	return 0;
	}
*/