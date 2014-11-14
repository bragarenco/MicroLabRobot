#ifndef _SPEED_H_
#define _SPEED_H_

#include <avr/io.h>


#define ENCODER_PORT	PORTC
#define ENCODER_DDR		DDRC
#define ENCODER_PIN		PINC

#define PHASE_A_PIN		PIN6
#define PHASE_B_PIN		PIN7


void InitEncoder(void);
void EncoderDriver(void);
int GetEncoderPhase(void);
int GetEncoderDirection(void);
int GetEncoderPeriod(void);
int GetEncoderSpeed(void);

#endif