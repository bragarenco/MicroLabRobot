/*
 * navigate.c
 *
 *  Created on: Nov 12, 2014
 *      Author: Andrei
 */

#include "navigate.h"
#include "motor.h"
#include "encoder.h"
#include "system.h"
#include <stdio.h>



//while (notFinished()) {
//  moveForward();
//  turnRight();
//  turnLeft();
//}

#define ONE_STEP_DISTANCE 12
#define RIGHT_ANGLE_TURN_DISTANCE 20  

#define NAV_STATUS_FWD 1
#define NAV_STATUS_BWD 2
#define NAV_STATUS_LEFT 3
#define NAV_STATUS_RIGHT 4 

volatile int navigate_status = 0;

volatile int leftEncCnt;
volatile int rightEncCnt;


void NavigateDriver(){

	switch (navigate_status) {
	case NAV_STATUS_FWD:
		if (((leftEncCnt + ONE_STEP_DISTANCE) < GetEncoderCounter(0))
		|| ((rightEncCnt + ONE_STEP_DISTANCE) < GetEncoderCounter(1))) {
			navigate_status = 0;
		}

		break;
	case NAV_STATUS_BWD:
		if (((leftEncCnt - ONE_STEP_DISTANCE) > GetEncoderCounter(0))
		|| ((rightEncCnt - ONE_STEP_DISTANCE) > GetEncoderCounter(1))) {
			navigate_status = 0;
		}

		break;
	case NAV_STATUS_RIGHT:
		if (((leftEncCnt - RIGHT_ANGLE_TURN_DISTANCE) > GetEncoderCounter(0))
		|| ((rightEncCnt + RIGHT_ANGLE_TURN_DISTANCE) < GetEncoderCounter(1))) {
			navigate_status = 0;
		}

		break;
	case NAV_STATUS_LEFT:
		if (((leftEncCnt + RIGHT_ANGLE_TURN_DISTANCE) < GetEncoderCounter(0))
		|| ((rightEncCnt - RIGHT_ANGLE_TURN_DISTANCE) > GetEncoderCounter(1))) {
			navigate_status = 0;

		}

		break;
	default:
		navigate_status = 0;
		motor1_set_pwm(0);
		motor2_set_pwm(0);
		break;
	}
 	



 }

void moveForward(){
	while(navigate_status);
	motor1_set_pwm(100);	
	motor2_set_pwm(100);

	navigate_status = 1;
	leftEncCnt = GetEncoderCounter(0);
	rightEncCnt = GetEncoderCounter(1);

}

void moveBackward(){
	while(navigate_status);
	motor1_set_pwm(-100);
	motor2_set_pwm(-100);

	navigate_status = NAV_STATUS_BWD;
	leftEncCnt = GetEncoderCounter(0);
	rightEncCnt = GetEncoderCounter(1);

}

void turnLeft(){
	while(navigate_status);
	motor1_set_pwm(100);
	motor2_set_pwm(-100);

	navigate_status = NAV_STATUS_LEFT;
	leftEncCnt = GetEncoderCounter(0);
	rightEncCnt = GetEncoderCounter(1);

}

void turnRight(){
	while(navigate_status);
	motor1_set_pwm(-100);
	motor2_set_pwm(100);

	navigate_status = NAV_STATUS_RIGHT;
	leftEncCnt = GetEncoderCounter(0);
	rightEncCnt = GetEncoderCounter(1);

}



