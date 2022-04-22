/*
 * servo.h
 *
 *  Created on: Apr 8, 2022
 *      Author: tjfriedl
 */

#ifndef SERVO_H_
#define SERVO_H_

float current_degrees;

// Initializes the servo registers
void servo_init(void);

// Uses PWM to send signal to mode servo
void servo_move(float degrees);



#endif /* SERVO_H_ */
