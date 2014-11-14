
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>

#include "usart.h"
#include "car.h"
#include "report.h"
#include "bumper.h"
#include "adc.h"
#include "speed.h"

static FILE mystdout = FDEV_SETUP_STREAM(USART_Transmit, 
										NULL,
										_FDEV_SETUP_WRITE);
static FILE mystdin = FDEV_SETUP_STREAM(NULL, 
										USART_Receive,
										_FDEV_SETUP_READ);

#define STEP 20

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
	AdcInit();

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
		
		
			SystemDelay(10);

			if(0){
			int line_pos = GetLinePos();

				motor1_set_pwm(40+line_pos*3);
				motor2_set_pwm(40-line_pos*3);

				//car_turn_left(line_pos);

			}

		
		if(1){





		char ctrl = 0;
		
			//ctrl = USART_Receive();
			switch(ctrl){
				case 'w': car_forward(STEP);printf(" GO forward \r\n");	break;
				case 's': car_backward(STEP);printf(" GO backward \r\n");	break;
				case 'a': car_turn_left(STEP);printf(" TURN left \r\n");	break;
				case 'd': car_turn_right(STEP);printf(" TURN right \r\n");	break;
				case 'f': car_stop();break;
			}
			
		}
		else{
		
		SystemDelay(500);
	
		
		if (TestBumper1()&&TestBumper2() ){
			
			//car_stop();
			motor1_set_pwm(0);
			motor2_set_pwm(0);
			SystemDelay(1000);
			
			//car_backward();
			motor1_set_pwm(-50);
			motor2_set_pwm(-50);
			SystemDelay(2000);

			//car_turn_left();
			motor1_set_pwm(50);
			motor2_set_pwm(-50);
			SystemDelay(2000);
			
			//car_forward();
			motor1_set_pwm(50);
			motor2_set_pwm(50);
			
		}else
		if (TestBumper1()){
			
			//car_stop();
			motor1_set_pwm(0);
			motor2_set_pwm(0);
			SystemDelay(500);
			
			//car_backward();
			motor1_set_pwm(-50);
			motor2_set_pwm(-50);
			SystemDelay(1000);
			
			//car_turn_left();
			motor1_set_pwm(50);
			motor2_set_pwm(-50);
			SystemDelay(1000);
			
			//car_forward();
			motor1_set_pwm(50);
			motor2_set_pwm(50);
		}else
		if (TestBumper2()){
			//car_stop();
			motor1_set_pwm(0);
			motor2_set_pwm(0);
			SystemDelay(500);
			
			//car_backward();
			motor1_set_pwm(-50);
			motor2_set_pwm(-50);
			SystemDelay(1000);
			
//			car_turn_right();
			motor1_set_pwm(-50);
			motor2_set_pwm(50);
			SystemDelay(1000);
			
			//car_forward();
			motor1_set_pwm(50);
			motor2_set_pwm(50);
			
		}else
		{

			//car_forward();

		}
		}

	}

return;
}




