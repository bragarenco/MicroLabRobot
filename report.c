#include "report.h"
#include "motor.h"
#include "adc.h"
#include "encoder.h"
#include "bumper.h"
#include "line_sensor.h"


volatile char reportflag = 0;

int ReportBussy(void ){
	return reportflag;
}

void ShowStatusReport(void){
	while(ReportBussy());
	reportflag = 1;
	printf("\r\n");
	printf("\r\n");
	printf("==================================\r\n");
	printf("| PARAMETER |  LEFT  |  RIGHT  |\r\n");
	printf("==================================\r\n");
	printf("| ENC PHASE |  %5d  |  %5d  |\r\n", GetEncoderPhase(0),		GetEncoderPhase(1));
	printf("----------------------------------\r\n");
	printf("| DIRECTION |  %5d  |  %5d  |\r\n", GetEncoderDirection(0),	GetEncoderDirection(1));
	printf("----------------------------------\r\n");
	printf("| FREE CNT  |  %5d  |  %5d  |\r\n", GetEncoderCounter(0),	GetEncoderCounter(1));
	printf("----------------------------------\r\n");
	printf("| PERIOD    |  %5d  |  %5d  |\r\n", GetEncoderPeriod(0),	GetEncoderPeriod(1));
	printf("----------------------------------\r\n");
	printf("| SPEED     |  %5d  |  %5d  |\r\n", GetEncoderSpeed(0),		GetEncoderSpeed(1));
	printf("----------------------------------\r\n");
	printf("| PWM       |  %5d  |  %5d  |\r\n", GetMotor1_PWM(),		GetMotor2_PWM());
	printf("----------------------------------\r\n");
	printf("| BUMPER    |  %5d  |  %5d  |\r\n", TestBumper1(),			TestBumper2());
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
for (int i= -25; i<25 ; i=i+1)
	{
		
		if(i<GetLinePos()){
			printf("-");
		}else{
			break;
		}
		
	}
	printf("X\r\n");

	printf("| pos ->  %4d\r\n", GetLinePos());
reportflag = 0;
}

volatile int diplay_cnt= 0; 
#define DISPLAY_PERIOD 10000 // ms

void DisplayStatusReport(void){

	if (++diplay_cnt >= DISPLAY_PERIOD){
		diplay_cnt = 0;
		ShowStatusReport();
	
	}
}

