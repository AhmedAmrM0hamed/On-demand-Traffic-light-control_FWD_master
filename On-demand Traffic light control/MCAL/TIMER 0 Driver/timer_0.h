/*
 * timer_0.h
 *
 *  Created on: Dec 12, 2022
 *  Author: Ahmed Amr
 */ 


#ifndef TIMER_0_H_
#define TIMER_0_H_

/* TIMER0_init*/
void TIMER0_init(void);

/* TIMER_FUNC_CALL*/
void TIMER_FUNC_CALL(void (*callback)(void));

#endif 