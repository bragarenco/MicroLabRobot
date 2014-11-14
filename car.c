#include "car.h"
#include "motor.h"




volatile int atenuate_cnt= 0;
#define CAR_ATENUATE_PERIOD 10 // ms

void car_control(void){

return;

	if (++atenuate_cnt < CAR_ATENUATE_PERIOD)
		return;
		
		atenuate_cnt = 0;



	
	int pwm;
	
	
	
	if (pwm = GetMotor1_PWM() < 0)
	{
		motor1_pwm_up(1);
	}
	if (pwm = GetMotor1_PWM() > 0)
	{
		motor1_pwm_dn(1);
	}
	if (pwm = GetMotor2_PWM() < 0)
	{
		motor2_pwm_up(1);
	}
	if (pwm = GetMotor2_PWM() > 0)
	{
		motor2_pwm_dn(1);
	}
	
	
}

void car_init(void){

	motor_init();

}

void car_forward(int STEP){

	motor1_pwm_up(STEP);
	motor2_pwm_up(STEP);


}
void car_backward(int STEP){

	motor1_pwm_dn(STEP);
	motor2_pwm_dn(STEP);

}

void car_turn_left(int STEP){
	motor1_pwm_dn(STEP);
	motor2_pwm_up(STEP);
}

void car_turn_right(int STEP){

	motor1_pwm_up(STEP);
	motor2_pwm_dn(STEP);

}

void car_stop(void){

	motor1_set_pwm(0);
	motor2_set_pwm(0);

}
