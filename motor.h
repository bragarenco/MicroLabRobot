#ifndef _MOTOR_H_
#define _MOTOR_H_

void motor_init(void);



int GetMotor1_PWM(void);

int GetMotor2_PWM(void);


void motor1_pwm_up( int pwm);
void motor2_pwm_up( int pwm);
void motor1_pwm_dn( int pwm);
void motor2_pwm_dn( int pwm);
void motor1_set_pwm( int pwm);
void motor2_set_pwm( int pwm);


#endif
