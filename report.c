#include "report.h"
#include "motor.h"
#include "adc.h"
#include "speed.h"




void ShowStatusReport(void){
	printf("\r\n");
	printf("\r\n");
	printf("==================================\r\n");
	printf(" Encoder phase : %d", GetEncoderPhase());
	printf(" | Direction : %d\r\n", GetEncoderDirection());
	printf(" Period : %5d", GetEncoderPeriod());
	printf(" | SPEED : %5d\r\n", GetEncoderSpeed());
	printf("----------------------------------\r\n");
	printf("| LEFT PWM %4d | RIGHT PWM %4d | \r\n", (int)GetMotor1_PWM(), (int)GetMotor2_PWM());
	printf("----------------------------------\r\n");
	printf("| LEFT BUMPER %d | RIGHT BUMPER %d | \r\n", TestBumper1(), TestBumper2());
	printf("----------------------------------\r\n");

	
	for (int i= 0; i<5 ; i++)
	{
		printf("| %4d", GetADC(i));
	}
		

	printf("|\r\n");
	for (int i= 0; i<5 ; i++)
	{
		printf("| %4d", GetSensorADC(i));
	}
		

	printf("|\r\n");
	for (int i= 0; i<5 ; i++)
	{
		printf("| %4d", GetSensor(i));
		
		
	}
	printf("|\r\n");

	printf("----------------------------------\r\n");
printf("|");
for (int i= -25; i<25 ; i=i+3)
	{
		
		if(i<GetLinePos()){
			printf("-");
		}else{
			break;
		}
		
	}
	printf("X\r\n");

	printf("| pos ->  %4d\r\n", GetLinePos());

}

volatile int diplay_cnt= 0; 
#define DISPLAY_PERIOD 1000 // ms

void DisplayStatusReport(void){

	if (++diplay_cnt >= DISPLAY_PERIOD){
		diplay_cnt = 0;
		ShowStatusReport();
	
	}
}

