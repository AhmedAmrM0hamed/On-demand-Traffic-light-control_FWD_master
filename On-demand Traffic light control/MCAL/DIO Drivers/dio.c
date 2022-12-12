/*
 * dio.c
 *
 *  Created on: Dec 12, 2022
 *  Author: Ahmed Amr
 */ 
#include "dio.h"
#include "../../ECUAL/LED Driver/led.h"

void static (*INT0_callback)(void);

DIO_ERROR DIO_init(uint8_t pinNumber , uint8_t portNumber , uint8_t direction)
{
	
	if(pinNumber > 7 || pinNumber < 0)
	{
		return DIO_WRONG_PIN;
	}
	
	switch(portNumber)
	{
		
		case PORTn_A :
			
			if (direction == OUT)
			 {
				DDRA |= (1<<pinNumber) ;
			}
			else if (direction == IN)
			{
				DDRA &= ~(1<<pinNumber);
			}
			else{
				//error handling
				return DIO_WRONG_VALUE;
			}
			break;
			
		
		case PORTn_B :
		
			if (direction == OUT)
			{
				DDRB |= (1<<pinNumber) ;
			}
			else if (direction == IN)
			{
				DDRB &= ~(1<<pinNumber);
			}
			else{
				//error handling
				return DIO_WRONG_VALUE;
			}
			break;
		
		
		case PORTn_C :
		
		if (direction == OUT)
		{
			DDRC |= (1<<pinNumber) ;
		}
		else if (direction == IN)
		{
			DDRC &= ~(1<<pinNumber);
		}
		else{
			//error handling
			return DIO_WRONG_VALUE;
		}
		break;
		
		case PORTn_D :
		
		if (direction == OUT)
		{
			DDRD |= (1<<pinNumber) ;
		}
		else if (direction == IN)
		{
			DDRD &= ~(1<<pinNumber);
		}
		else
		{
			//error handling
			return DIO_WRONG_VALUE;
		}
		break;
		
		default:
		return DIO_WRONG_PORT;
	}
	
	return DIO_OK;
}
DIO_ERROR DIO_write(uint8_t pinNumber , uint8_t portNumber , uint8_t value)
{
	
	if(pinNumber > 7 || pinNumber < 0)
	{
		return DIO_WRONG_PIN;
	}
	
	switch(portNumber)
	{
	
		case PORTn_A :
	
		if (value == HIGH)
		{
			PORTA |= (1<<pinNumber) ;
		}
		else if (value == LOW)
		{
			PORTA &= ~(1<<pinNumber);
		}
		else{
			//error handling
			return DIO_WRONG_VALUE;
		}
		break;
	
	
		case PORTn_B :
	
		if (value == HIGH)
		{
			PORTB |= (1<<pinNumber) ;
		}
		else if (value == LOW)
		{
			PORTB &= ~(1<<pinNumber);
		}
		else{
			//error handling
			return DIO_WRONG_VALUE;
		}
		break;
	
	
		case PORTn_C :
	
		if (value == HIGH)
		{
			PORTC |= (1<<pinNumber) ;
		}
		else if (value == LOW)
		{
			PORTC &= ~(1<<pinNumber);
		}
		else{
			//error handling
			return DIO_WRONG_VALUE;
		}
		break;
	
	
		case PORTn_D :
	
		if (value == HIGH)
		{
			PORTD |= (1<<pinNumber) ;
		}
		else if (value == LOW)
		{
			PORTD &= ~(1<<pinNumber);
		}
		else{
			//error handling
			return DIO_WRONG_VALUE;
		}
		break;
		
		default:
		return DIO_WRONG_PORT;
	}
	return DIO_OK;
}

DIO_ERROR DIO_toggle(uint8_t pinNumber , uint8_t portNumber )
{
	
	if(pinNumber > 7 || pinNumber < 0)
	{
		return DIO_WRONG_PIN;
	}
	
	switch(portNumber){
		
		case PORTn_A :
		
		PORTA ^= (1<<pinNumber);
		break;
		
		
		case PORTn_B :
		
		PORTB ^= (1<<pinNumber);
		break;
		
		
		case PORTn_C :
		
		PORTC ^= (1<<pinNumber);
		break;
		
		
		case PORTn_D :
		
		PORTD ^= (1<<pinNumber);
		break;
		
		default:
		return DIO_WRONG_PORT;
	}
	return DIO_OK;
}

DIO_ERROR DIO_read(uint8_t pinNumber , uint8_t portNumber , uint8_t* value)
{
	
	if(pinNumber > 7 || pinNumber < 0){
		return DIO_WRONG_PIN;
	}
	
	switch(portNumber){
		
		case PORTn_A :
			*value = (PINA & (1<<pinNumber))>>pinNumber; 
			break;
			
		
		case PORTn_B :
			*value = (PINB & (1<<pinNumber))>>pinNumber; 
			break;
		
		case PORTn_C :
			*value = (PINC & (1<<pinNumber))>>pinNumber; 
			break;
		
		
		case PORTn_D :
			*value = (PIND & (1<<pinNumber))>>pinNumber;
			break;
			
		default:
		return DIO_WRONG_PORT;
	}
	
	return DIO_OK;
}

void enable_external_INT0(void)
{
	
	PORTD |=(1<<2) ;
	
	GICR = 1<<INT0;
	
	MCUCR |= (1<<ISC01);
	MCUCR |= (1<<ISC00);
	sei();
}
void INT0_FUNC_CALL(void (*callback)(void))
{
	
	INT0_callback = callback;
}

ISR (INT0_vect){
	
	INT0_callback();
}

/************************************************************************/
/* Testing the module                                                   */
/************************************************************************/

/*

LED ledaya = {0 , PORTn_A};
	
void toggel (void);
	
int main (void){
	
	LED_init_t(&ledaya);
	enable_external_INT0();
	
	INT0_FUNC_CALL(toggel);
	
	while(1);
	
		
	
	return 0 ;
}

void toggel (void){
	
	LED_toggle_t(&ledaya);
}
*/