#ifndef _BUMPER_H_
#define _BUMPER_H_

#include <avr/io.h>

#define BUMPER_PORT PORTA
#define BUMPER_DDR  DDRA
#define BUMPER_PIN  PINA


#define BUMPER_PIN1	PINA4
#define BUMPER_PIN2	PINA5
#define BUMPER_PIN3	PINA6



void BumperInit(void);
int TestBumper1(void);
int TestBumper2(void);
int TestBumper3(void);

#endif
