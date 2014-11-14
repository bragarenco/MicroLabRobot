/*
 * adc.c
 *
 * Created: 10/24/2014 6:55:35 PM
 *  Author: Andrei
 */ 
#include "adc.h"

volatile int adcTab[8];

int adcCannel = 0;

void AdcInit(void){
	
	ADMUX = 0;
	ADCSRA = (1<<ADEN)|(1<<ADSC)|(1<<ADIE)|(1<<ADATE)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0); // /32

}

ISR(ADC_vect){
	int adcData =  ADC;
	
	adcTab[adcCannel++] = adcData;

	adcCannel %= 5;
	
	ADMUX = (ADMUX & (~0x07)) | adcCannel; 
		
}

 int GetADC(int channel){
	 return adcTab[channel];
 }