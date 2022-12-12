/*
 * dio.h
 *
 *  Created on: Dec 12, 2022
 *  Author: Ahmed Amr
 */ 


#ifndef DIO_H_
#define DIO_H_
#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
	
//macros

//direction definitions
#define IN 0
#define OUT 1

//values definitions
#define LOW 0
#define HIGH 1

#define PORTn_A 'A'
#define PORTn_B 'B'
#define PORTn_C 'C'
#define PORTn_D 'D'

// typedefs 

typedef enum DIO_ERROR {DIO_OK , DIO_WRONG_PIN, DIO_WRONG_PORT, DIO_WRONG_VALUE}DIO_ERROR;
	
// functions 

DIO_ERROR DIO_init(uint8_t pinNumber , uint8_t portNumber , uint8_t direction);

DIO_ERROR DIO_write(uint8_t pinNumber , uint8_t portNumber , uint8_t value);

DIO_ERROR DIO_toggle(uint8_t pinNumber , uint8_t portNumber );

DIO_ERROR DIO_read(uint8_t pinNumber , uint8_t portNumber , uint8_t* value );

/* enable_external_INT0*/
void enable_external_INT0(void);
/* INT0_FUNC_CALL*/
void INT0_FUNC_CALL(void (*callback)(void));


#endif