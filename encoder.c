#include "encoder.h"
#include "filter.h"

#define MAX_PERIOD 2000
#define NR_OF_ENCODERS 2

#define LEFT_ENCODER 0
#define RIGHT_ENCODER 1


typedef struct encoder_s {
		 int previous_phase;
		volatile int current_phase;
		volatile int period;
		int free_counter;
		volatile int period_counter;
		volatile uint8_t * PORT;
		volatile uint8_t  PHASE_A_MASK;
		volatile uint8_t  PHASE_B_MASK;
} encoder_t;




encoder_t encoder_table[NR_OF_ENCODERS];


struct encoder_s encoder_1;



extern int encoderFilterTab[2][MEDIAN_FILTER_DEPTH];
extern int averageFilterTab[2][AVERAGE_FILTER_DEPTH];

void InitEncoder(const uint8_t * PORT, const char phase_A_pin_mask, const char phase_B_pin_mask){
//	(*(volatile uint8_t *)(PORT-1))	&= ~(phase_A_pin_mask | phase_B_pin_mask); // DDR
//	(*(volatile uint8_t *)(PORT))				|=  (phase_A_pin_mask | phase_B_pin_mask);
	encoder_table[0].PHASE_A_MASK = 1 << PHASE_A_1_PIN;
	encoder_table[1].PHASE_A_MASK = 1 << PHASE_A_2_PIN;
	encoder_table[0].PHASE_B_MASK = 1 << PHASE_B_1_PIN;
	encoder_table[1].PHASE_B_MASK = 1 << PHASE_B_2_PIN;

	ENCODER_DDR  &= ~((1<<PHASE_A_1_PIN)|(1<<PHASE_B_1_PIN));
	ENCODER_PORT |=  ((1<<PHASE_A_1_PIN)|(1<<PHASE_B_1_PIN));
	ENCODER_DDR  &= ~((1<<PHASE_A_2_PIN)|(1<<PHASE_B_2_PIN));
	ENCODER_PORT |=  ((1<<PHASE_A_2_PIN)|(1<<PHASE_B_2_PIN));
}


void EncoderDriver(int i){

	if (encoder_table[i].period_counter < MAX_PERIOD )
		encoder_table[i].period_counter++;
	else{
		encoder_table[i].period = MAX_PERIOD;
	}



	int phase = GetEncoderPhase(i);


	if(phase != encoder_table[i].current_phase){

		encoder_table[i].previous_phase = encoder_table[i].current_phase;
		encoder_table[i].current_phase = phase;
		encoder_table[i].period = encoder_table[i].period_counter;
		encoder_table[i].period_counter = 0;

		if( GetEncoderDirection(i) > 0 )
			encoder_table[i].free_counter++;
		if( GetEncoderDirection(i) < 0 )
			encoder_table[i].free_counter--;

		// filter period
		PushToTab(encoderFilterTab[i],encoder_table[i].period,MEDIAN_FILTER_DEPTH);
		encoder_table[i].period = GetMedianValue(encoderFilterTab[i], MEDIAN_FILTER_DEPTH);
		PushToTab(averageFilterTab[i],encoder_table[i].period,AVERAGE_FILTER_DEPTH);
		encoder_table[i].period = GetAverageValue(averageFilterTab[i],AVERAGE_FILTER_DEPTH);


		
		

	}

	
}


inline int GetEncoderCounter(int i){
	return encoder_table[i].free_counter;
}


int GetEncoderPhase(int i){

	int phase = 0;

	if(ENCODER_PIN & encoder_table[i].PHASE_A_MASK){
		phase |= 1<<0;
	}
	if(ENCODER_PIN & encoder_table[i].PHASE_B_MASK){
		phase |= 1<<1;
	}

	return phase;
}

int GetEncoderDirection(int i){

	if(encoder_table[i].previous_phase == encoder_table[i].current_phase)
		return 0;
	if(encoder_table[i].current_phase > 3)
		return 0;

	switch(encoder_table[i].previous_phase){
		case 0b00: if(encoder_table[i].current_phase == 0b01)
						return 1;
					else 
						return -1;
		case 0b01: if(encoder_table[i].current_phase == 0b11)
						return 1;
					else 
						return -1;
		case 0b11: if(encoder_table[i].current_phase == 0b10)
						return 1;
					else 
						return -1;
		case 0b10: if(encoder_table[i].current_phase == 0b00)
						return 1;
					else 
						return -1;
		default: return 0;
	}

}

int GetEncoderPeriod(int i){
	return encoder_table[i].period;
}
int GetEncoderSpeed(int i){
	return (MAX_PERIOD - 1)/ encoder_table[i].period;
}



