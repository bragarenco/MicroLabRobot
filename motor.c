#include "motor.h"
#include <avr/io.h>

#define IN1_PIN PIND2  
#define IN2_PIN PIND3  

#define DIR1_PIN PIND3

#define EN1_PIN PIND4  
#define EN2_PIN PIND5 

#define DIR2_PIN PIND6

#define IN3_PIN PIND6  
#define IN4_PIN PIND7  


#define MOTOR_DDR  DDRD
#define MOTOR_PORT  PORTD

#define PWM_RES 10
#define PWM_TOP ((1<<PWM_RES)-1) // 10 bit -> 1023


volatile int motor1_PWM = 0;
volatile int motor2_PWM = 0;



int GetMotor1_PWM(void){
	return motor1_PWM;
}

int GetMotor2_PWM(void){
	return motor2_PWM;
}


void motor_init(void){

	

	MOTOR_DDR |=(1<<IN1_PIN)|    
				(1<<IN2_PIN)|    
				(1<<EN1_PIN)|
				(1<<EN2_PIN)|
				(1<<IN3_PIN)|
				(1<<IN4_PIN);

	MOTOR_PORT &= ~((1<<IN1_PIN)|    
				(1<<IN2_PIN)|    
				(1<<EN1_PIN)|
				(1<<EN2_PIN)|
				(1<<IN3_PIN)|
				(1<<IN4_PIN));



	TCCR1A = (1<<WGM11) |  (1<<WGM10) | (1<<COM1A1) | (0<<COM1A0) |(1<<COM1B1) | (0<<COM1B0); 	
	TCCR1B = (0<<WGM13) |  (1<<WGM12) | (0<<CS12) |(1<<CS11) |(1<<CS10) ; 

	motor1_PWM = 0;
	motor2_PWM = 0;
	motor1_set_pwm(0);
	motor2_set_pwm(0);


		
}

void motor1_fwd(){
//	MOTOR_PORT &= ~(1<<IN1_PIN);
//	MOTOR_PORT |= (1<<IN2_PIN);

	MOTOR_PORT |= 1<<DIR1_PIN;

}


void motor1_bwd(){
//	MOTOR_PORT &= ~(1<<IN2_PIN);
//	MOTOR_PORT |= (1<<IN1_PIN);

	MOTOR_PORT &= ~(1<<DIR1_PIN);

}
void motor2_fwd(){
//	MOTOR_PORT &= ~(1<<IN3_PIN);
//	MOTOR_PORT |= (1<<IN4_PIN);

	MOTOR_PORT |= (1<<DIR2_PIN);


}
void motor2_bwd(){
//	MOTOR_PORT &= ~(1<<IN4_PIN);
//	MOTOR_PORT |= (1<<IN3_PIN);

	MOTOR_PORT &= ~(1<<DIR2_PIN);

}


void motor1_pwm_up( int pwm){

	motor1_set_pwm(motor1_PWM+pwm);
}

void motor2_pwm_up( int pwm){
	
	motor2_set_pwm(motor2_PWM+pwm);
}

void motor1_pwm_dn( int pwm){
	
	motor1_set_pwm(motor1_PWM-pwm);
}

void motor2_pwm_dn( int pwm){
	
	motor2_set_pwm(motor2_PWM-pwm);
}





void motor1_set_pwm( int pwm){

	if (pwm > 100)
		pwm = 100;

	if (pwm < (-100))
		pwm = (-100);


	motor1_PWM = pwm;


	if (pwm>0){
		motor1_fwd();
	}else{
		motor1_bwd();
		pwm*=(-1);
	}


int a = ((long)PWM_TOP * pwm)/100 ;


	OCR1A =a ;

/*	if (pwm>0)
	{
		MOTOR_PORT |= (1<<EN1_PIN);
	}
	else{
		MOTOR_PORT &= ~(1<<EN1_PIN);
	}

*/
}

void motor2_set_pwm( int pwm){


	if (pwm > 100)
		pwm = 100;

	if (pwm < (-100))
		pwm = (-100);


	motor2_PWM = pwm;



	if (pwm>0){
		motor2_fwd();
	}else{
		motor2_bwd();
		pwm*=(-1);
	}


	int a = ((long)PWM_TOP * pwm)/100 ;

	OCR1B = a;

/*	if (pwm>0)
	{
		MOTOR_PORT |= (1<<EN2_PIN);
	}
	else{
		MOTOR_PORT &= ~(1<<EN2_PIN);
	}
*/
}
