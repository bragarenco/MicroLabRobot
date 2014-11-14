#ifndef _SPEED_H_
#define _SPEED_H_

#include <avr/io.h>


#define ENCODER_PORT	PORTC
#define ENCODER_DDR		DDRC
#define ENCODER_PIN		PINC

#define PHASE_A_1_PIN		PIN1
#define PHASE_B_1_PIN		PIN3
#define PHASE_A_2_PIN		PIN3
#define PHASE_B_2_PIN		PIN1



void InitEncoder(void);
void EncoderDriver(void);
int GetEncoderPhase_1(void);
int GetEncoderDirection_1(void);
int GetEncoderPeriod_1(void);
int GetEncoderSpeed_1(void);

int GetEncoderPhase_2(void);
int GetEncoderDirection_2(void);
int GetEncoderPeriod_2(void);
int GetEncoderSpeed_2(void);


#endif
