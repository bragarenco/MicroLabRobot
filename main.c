

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

	printf("MOTOR CONTROL\r");
	printf("forward - w\r");
	printf("backward - s\r");
	printf("left - a\r");
	printf("right - d\r");
	printf("stop - <space>\r");
	printf("---- GO -----");

	while(1){
		char ctrl;
			
		ctrl = USART_Receive();
		switch(ctrl){
			case 'w': car_forward();break;
			case 's': car_backward();break;
			case 'a': car_turn_left();break;
			case 'd': car_turn_right();break;
			case ' ': car_stop();break;
		}

	}

return;
}




