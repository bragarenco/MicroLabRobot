#ifndef _SPEED_H_
#define _SPEED_H_

#include <avr/io.h>


#define ENCODER_PORT	PORTC
#define ENCODER_DDR		DDRC
#define ENCODER_PIN		PINC

#define PHASE_A_1_PIN		PIN7
#define PHASE_B_1_PIN		PIN6
#define PHASE_A_2_PIN		PIN5
#define PHASE_B_2_PIN		PIN4



void InitEncoder(const uint8_t * PORT, const char phase_A_pin_mask, const char phase_B_pin_mask);
void EncoderDriver(int);
int GetEncoderPhase(int);
int GetEncoderDirection(int);
int GetEncoderPeriod(int);
int GetEncoderSpeed(int);

int GetEncoderCounter(int);









#endif
