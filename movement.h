#ifndef MOVEMENT_H_
#define MOVEMENT_H_
#include "open_interface.h"

void move_forward(oi_t *sensor, int centimeters); //moves the robot forward "centimeters" centimeters

void turn_right(oi_t *sensor, int angle); //turns the robot's wheels angle degrees right

void turn_left(oi_t *sensor, int angle); //turns the robot's wheels angle degrees left INPUT A NEGATIVE NUMBER

void bump(oi_t *sensor, double centimeters); //run this and the robot will do step 3 completely. centimeters is net distance forward

void move_backward(oi_t *sensor, int centimeters); //moves the robot backwards INPUT A NEGATIVE NUMBER

void printToPutty(char str[], int degrees, float distance);

void printToPuttyObject(char str[], int count, int angle, int width,
                        float distance);

//void printToPuttyWidth(char str[], int count, int width);

int findMinWidth(int arr[], int n);

//void pushw_moveForward(oi_t *sensor, int centimeters);
//
//void pushs_moveBackward(oi_t, int centimeters);
//
//void pushd_turnRight(oi_t *sensor, int angle);
//
//void pusha_turnLeft(oi_t *sensor, int angle);

#endif
