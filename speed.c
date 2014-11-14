#include "speed.h"

#define MAX_PERIOD 2000

volatile int previous_phase_1 = 0;
volatile int current_phase_1 = 0;
volatile int encoder_period_1 = MAX_PERIOD;
volatile int previous_phase_2 = 0;
volatile int current_phase_2 = 0;
volatile int encoder_period_2 = MAX_PERIOD;



void InitEncoder(void){
	ENCODER_DDR  &= ~((1<<PHASE_A_1_PIN)|(1<<PHASE_B_1_PIN));
	ENCODER_PORT |=  ((1<<PHASE_A_1_PIN)|(1<<PHASE_B_1_PIN));
	ENCODER_DDR  &= ~((1<<PHASE_A_2_PIN)|(1<<PHASE_B_2_PIN));
	ENCODER_PORT |=  ((1<<PHASE_A_2_PIN)|(1<<PHASE_B_2_PIN));
}




void EncoderDriver(void){

	static int period_counter_1;
	if (period_counter_1 < MAX_PERIOD )
		period_counter_1++;
	else{
		encoder_period_1 = MAX_PERIOD;
	}



	int phase = GetEncoderPhase();


	if(phase != current_phase_1){
		previous_phase_1 = current_phase_1;
		current_phase_1 = phase;
		encoder_period_1 = period_counter_1;
		period_counter_1 = 0;

	}

	
}


int GetEncoderPhase(void){

	int phase = 0;

	if(ENCODER_PIN & (1<<PHASE_A_1_PIN)){
		phase |= 1<<0;
	}
	if(ENCODER_PIN & (1<<PHASE_B_1_PIN)){
		phase |= 1<<1;
	}

	return phase;
}

int GetEncoderDirection(void){

	if(previous_phase_1 == current_phase_1)
		return 0;
	if(current_phase_1 > 3)
		return 0;

	switch(previous_phase_1){
		case 0b00: if(current_phase_1 == 0b01) 
						return 1;
					else 
						return -1;
		case 0b01: if(current_phase_1 == 0b11) 
						return 1;
					else 
						return -1;
		case 0b11: if(current_phase_1 == 0b10) 
						return 1;
					else 
						return -1;
		case 0b10: if(current_phase_1 == 0b00) 
						return 1;
					else 
						return -1;
		default: return 0;
	}

}

int GetEncoderPeriod(void){
	return encoder_period_1;
}
int GetEncoderSpeed(void){
	return (MAX_PERIOD - 1)/ encoder_period_1;
}



