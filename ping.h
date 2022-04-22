/*
 * ping.h
 *
 *  Revised on: April 14, 2021
 *      Author: Trevor Friedl
 */

#ifndef PING_H_
#define PING_H_
#include "Timer.h"


volatile enum {LOW, HIGH, DONE} state; // set by ISR
volatile unsigned int rising_time; //Pulse start time: Set by ISR
volatile unsigned int falling_time; //Pulse end time: Set by ISR

volatile unsigned int num_overflows;


void ping_init();

float ping_read();

void TIMER3B_Handler();

void send_pulse();



#endif /* PING_H_ */
