#include "car.h"
#include "motor.h"

void car_init(void){

	motor_init();

}
void car_forward(void){
	motor1_fwd();
	motor2_fwd();
	motor1_set_pwm(100);
	motor2_set_pwm(100);


}
void car_backward(void){
	motor1_bwd();
	motor2_bwd();
	motor1_set_pwm(100);
	motor2_set_pwm(100);


}
void car_turn_left(void){

	motor1_bwd();
	motor2_fwd();
	motor1_set_pwm(100);
	motor2_set_pwm(100);

}
void car_turn_right(void){

	motor1_fwd();
	motor2_bwd();
	motor1_set_pwm(100);
	motor2_set_pwm(100);

}
void car_stop(void){
	motor1_set_pwm(0);
	motor2_set_pwm(0);
}
