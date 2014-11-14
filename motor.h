#ifndef _MOTOR_H_
#define _MOTOR_H_

void motor_init(void);

void motor1_fwd();
void motor1_bwd();
void motor2_fwd();
void motor2_bwd();

void motor1_set_pwm(unsigned char pwm);
void motor2_set_pwm(unsigned char pwm);

#endif