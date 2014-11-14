#ifndef _BUMPER_H_
#define _BUMPER_H_

#include <avr/io.h>

#define BUMPER_PORT PORTB
#define BUMPER_DDR  DDRB
#define BUMPER_PIN  PINB


#define BUMPER_PIN1	PINB6
#define BUMPER_PIN2	PINB7
#define BUMPER_PIN3	PINB7



void BumperInit(void);
int TestBumper1(void);
int TestBumper2(void);
int TestBumper3(void);

#endif
