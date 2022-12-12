/*
 * timer_0.c
 *
 *  Created on: Dec 12, 2022
 *  Author: Ahmed Amr
 */ 

#include "timer_0.h"
#include <avr/io.h>
#include <stdint.h>
#include <avr/interrupt.h>
#include "../../ECUAL/LED Driver/led.h"

uint8_t i = 0;

void static (*TIMER0_callback)(void);

void TIMER0_init(void){
	
	TCNT0 = 0;
	TIMSK = 0x01;
	sei();
	
	TCCR0 = 0x05;
	
}
void TIMER_FUNC_CALL(void (*callback)(void)){

		TIMER0_callback = callback;
}

ISR(TIMER0_OVF_vect)
{
	 if (i == 16)
	 {
		 TIMER0_callback();
	 }

	i %= 16;
	
	i++;
}

/************************************************************************/
/* Testing the module                                                   */
/************************************************************************/

/*

// toggling the bit every second.

LED ledaya = {0 , PORTn_A};
	
void toggel (void);
	
int main (void){
	
	LED_init_t(&ledaya);
	
	TIMER0_init();
	
	TIMER_FUNC_CALL(toggel);
	
	while(1);
	
		
	
	return 0 ;
}

void toggel (void){
	
	LED_toggle_t(&ledaya);
}
*/