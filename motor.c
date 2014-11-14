#include "motor.h"
#include <avr/io.h>

#define IN1_PIN PIND2  
#define IN2_PIN PIND3  
#define EN1_PIN PIND4  
#define EN2_PIN PIND5 
#define IN3_PIN PIND6  
#define IN4_PIN PIND7  
#define MOTOR_DDR  DDRD
#define MOTOR_PORT  PORTD

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
}

void motor1_fwd(){
	MOTOR_PORT &= ~(1<<IN1_PIN);
	MOTOR_PORT |= (1<<IN2_PIN);

}


void motor1_bwd(){
	MOTOR_PORT &= ~(1<<IN2_PIN);
	MOTOR_PORT |= (1<<IN1_PIN);

}
void motor2_fwd(){
	MOTOR_PORT &= ~(1<<IN3_PIN);
	MOTOR_PORT |= (1<<IN4_PIN);

}
void motor2_bwd(){
	MOTOR_PORT &= ~(1<<IN4_PIN);
	MOTOR_PORT |= (1<<IN3_PIN);

}

void motor1_set_pwm(unsigned char pwm){
	if (pwm>0)
	{
		MOTOR_PORT |= (1<<EN1_PIN);
	}
	else{
		MOTOR_PORT &= ~(1<<EN1_PIN);
	}


}
void motor2_set_pwm(unsigned char pwm){
	if (pwm>0)
	{
		MOTOR_PORT |= (1<<EN2_PIN);
	}
	else{
		MOTOR_PORT &= ~(1<<EN2_PIN);
	}
}
