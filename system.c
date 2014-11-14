#include "system.h"
#include "report.h"
#include "encoder.h"
#include "car.h"

volatile int sistem_timer=0;


void SystemTick(void){

	DisplayStatusReport(); 
	car_control();
	EncoderDriver(0);
	EncoderDriver(1);
	NavigateDriver();
	
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
