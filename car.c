#include "car.h"
#include "motor.h"

#define STEP 5

void car_init(void){

	motor_init();

}

void car_forward(void){

	motor1_pwm_up(STEP);
	motor2_pwm_up(STEP);


}
void car_backward(void){

	motor1_pwm_dn(STEP);
	motor2_pwm_dn(STEP);

}

void car_turn_left(void){
	motor1_pwm_dn(STEP);
	motor2_pwm_up(STEP);
}

void car_turn_right(void){

	motor1_pwm_up(STEP);
	motor2_pwm_dn(STEP);

}

void car_stop(void){

	motor1_set_pwm(0);
	motor2_set_pwm(0);

}
