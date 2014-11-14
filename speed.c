#include "speed.h"

#define MAX_PERIOD 2000

volatile int previous_phase = 0;
volatile int current_phase = 0;
volatile int encoder_period = MAX_PERIOD;


void InitEncoder(void){
	ENCODER_DDR  &= ~((1<<PHASE_A_PIN)|(1<<PHASE_B_PIN));
	ENCODER_PORT |=  ((1<<PHASE_A_PIN)|(1<<PHASE_B_PIN));
}




void EncoderDriver(void){

	static int period_counter;
	if (period_counter < MAX_PERIOD )
		period_counter++;
	else{
		encoder_period = MAX_PERIOD;
	}



	int phase = GetEncoderPhase();


	if(phase != current_phase){
		previous_phase = current_phase;
		current_phase = phase;
		encoder_period = period_counter;
		period_counter = 0;

	}

	
}


int GetEncoderPhase(void){

	int phase = 0;

	if(ENCODER_PIN & (1<<PHASE_A_PIN)){
		phase |= 1<<0;
	}
	if(ENCODER_PIN & (1<<PHASE_B_PIN)){
		phase |= 1<<1;
	}

	return phase;
}

int GetEncoderDirection(void){

	if(previous_phase == current_phase)
		return 0;
	if(current_phase > 3)
		return 0;

	switch(previous_phase){
		case 0b00: if(current_phase == 0b01) 
						return 1;
					else 
						return -1;
		case 0b01: if(current_phase == 0b11) 
						return 1;
					else 
						return -1;
		case 0b11: if(current_phase == 0b10) 
						return 1;
					else 
						return -1;
		case 0b10: if(current_phase == 0b00) 
						return 1;
					else 
						return -1;
		default: return 0;
	}

}

int GetEncoderPeriod(void){
	return encoder_period;
}
int GetEncoderSpeed(void){
	return (MAX_PERIOD - 1)/ encoder_period;
}



