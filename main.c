
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>

#include "usart.h"
#include "car.h"
#include "report.h"
#include "bumper.h"

static FILE mystdout = FDEV_SETUP_STREAM(USART_Transmit, 
										NULL,
										_FDEV_SETUP_WRITE);
static FILE mystdin = FDEV_SETUP_STREAM(NULL, 
										USART_Receive,
										_FDEV_SETUP_READ);


void Timer0Init(){

 TIMSK |= (1<<TOIE0);
 TCCR0 = 0x03; 
 TCNT0 = 125;
}

ISR(TIMER0_OVF_vect){
 TCNT0 = 125;
 SystemTick();	

}


void main (void){

	stdout = &mystdout;
	stdin  = &mystdin;

	USART_Init(51);
	Timer0Init();

	BumperInit();

	car_init();

	printf("MOTOR CONTROL\r\n");
	printf("forward - w\r\n");
	printf("backward - s\r\n");
	printf("left - a\r\n");
	printf("right - d\r\n");
	printf("stop - <space>\r\n");
	printf("---- GO -----\r\n");

	ShowStatusReport();	

	sei();

    SystemDelay(2000); 
	printf("---- 2 sec -----\r\n");


	while(1){
		char ctrl;
		
			ctrl = 0;
			//USART_Receive();
			switch(ctrl){
				case 'w': car_forward();printf(" GO forward \r\n");	break;
				case 's': car_backward();printf(" GO backward \r\n");	break;
				case 'a': car_turn_left();printf(" TURN left \r\n");	break;
				case 'd': car_turn_right();printf(" TURN right \r\n");	break;
				case 'f': car_stop();break;
			}
			

		SystemDelay(1000);

		
		if (TestBumper1()&&TestBumper2() ){
			motor1_set_pwm(0);
			motor2_set_pwm(0);
			SystemDelay(1000);
			motor1_set_pwm(-50);
			motor2_set_pwm(-50);
			//car_backward();
			SystemDelay(2000);

			motor1_set_pwm(50);
			motor2_set_pwm(-50);

			//car_turn_left();
			SystemDelay(1000);
			motor1_set_pwm(50);
			motor2_set_pwm(50);
			//car_forward();
		}else
		if (TestBumper1()){
			motor1_set_pwm(0);
			motor2_set_pwm(0);
			SystemDelay(1000);
			motor1_set_pwm(50);
			motor2_set_pwm(-50);
			//car_turn_left();
			SystemDelay(1000);
			motor1_set_pwm(50);
			motor2_set_pwm(50);
			//car_forward();
		}else
		if (TestBumper2()){
			motor1_set_pwm(0);
			motor2_set_pwm(0);
			SystemDelay(1000);
			motor1_set_pwm(-50);
			motor2_set_pwm(50);
//			car_turn_right();
			SystemDelay(1000);
			motor1_set_pwm(50);
			motor2_set_pwm(50);
			//car_forward();
		}else
		{

			//car_forward();

		}

	}

return;
}




