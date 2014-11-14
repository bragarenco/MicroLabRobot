

#include <stdio.h>

#include "usart.h"
#include "car.h"

static FILE mystdout = FDEV_SETUP_STREAM(USART_Transmit, 
										NULL,
										_FDEV_SETUP_WRITE);
static FILE mystdin = FDEV_SETUP_STREAM(NULL, 
										USART_Receive,
										_FDEV_SETUP_READ);


void main (void){

	stdout = &mystdout;
	stdin  = &mystdin;

	USART_Init(51);
	car_init();

	printf("MOTOR CONTROL\r\n");
	printf("forward - w\r\n");
	printf("backward - s\r\n");
	printf("left - a\r\n");
	printf("right - d\r\n");
	printf("stop - <space>\r\n");
	printf("---- GO -----\r\n");

	printf("LEFT %4d    RIGHT %4d  \r\n", GetMotor1_PWM(), GetMotor2_PWM());

	while(1){
		char ctrl;
			
		ctrl = USART_Receive();
		switch(ctrl){
			case 'w': car_forward();printf(" GO forward \r\n");	break;
			case 's': car_backward();printf(" GO backward \r\n");	break;
			case 'a': car_turn_left();printf(" TURN left \r\n");	break;
			case 'd': car_turn_right();printf(" TURN right \r\n");	break;
			case 'f': car_stop();break;
		}

			printf("LEFT %d    RIGHT %d  \r\n", (int)GetMotor1_PWM(), (int)GetMotor2_PWM());

	}

return;
}




