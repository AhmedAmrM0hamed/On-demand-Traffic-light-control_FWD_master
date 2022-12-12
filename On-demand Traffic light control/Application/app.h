/*
 * app.h
 *
 *  Created on: Dec 12, 2022
 *  Author: Ahmed Amr
 */ 


#ifndef APP_H_
#define APP_H_

typedef enum APP_ERROR_t {APP_OK , APP_FAILED} APP_ERROR_t;
	
void app_Start (void);

/* pedestrian_mode
  * when the cars light is green set the turn to be yellow.
 */
void pedestrian_mode(void);

APP_ERROR_t turn_all_leds_off(void);

APP_ERROR_t initialize_leds (void);

/* change_turn
 *	change the lights turn every five seconds
 */
void change_turn (void);

/* traffic_orgnization
 *	light up the led on it's turn.
 *  close the previous one.
 *  if the led turn is yellow toggle it and light up the previous one.
 */
void traffic_orgnization (void);


#endif