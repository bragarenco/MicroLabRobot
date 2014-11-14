#include "system.h"
#include "report.h"
#include "speed.h"

volatile int sistem_timer=0;


void SystemTick(void){

	DisplayStatusReport(); 
	car_control();
	EncoderDriver();
	
	if(sistem_timer>0){
		sistem_timer--;
	}

}



void SystemDelay(int time_ms){

	sistem_timer = time_ms;

	while(sistem_timer!=0){
		asm("nop");
	};
}
