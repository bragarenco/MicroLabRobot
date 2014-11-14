/*
 * adc.h
 *
 * Created: 10/24/2014 6:54:17 PM
 *  Author: Andrei
 */ 


#ifndef ADC_H_
#define ADC_H_
#include <avr/io.h>
#include <avr/interrupt.h>

void AdcInit();
 int GetADC(int channel);


#endif /* INCFILE1_H_ */