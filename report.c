#include "report.h"
#include "motor.h"

void ShowStatusReport(void){

printf("-----------------------------------\r\n");
printf("|   LEFT %4d   |    RIGHT %4d  | \r\n", (int)GetMotor1_PWM(), (int)GetMotor2_PWM());
printf("---------------------------\r\n");
printf("| LEFT BUMPER %d |  RIGHT BUMPER %d  | \r\n", TestBumper1(), TestBumper2());
printf("-----------------------------------\r\n");


}

volatile int diplay_cnt= 0; 
#define DISPLAY_PERIOD 1000 // ms

void DisplayStatusReport(void){

	if (++diplay_cnt >= DISPLAY_PERIOD){
		diplay_cnt = 0;
		ShowStatusReport();
	
	}
}

