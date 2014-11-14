

#include <stdio.h>

#include "usart.h"
#include "car.h"

static FILE mystdout = FDEV_SETUP_STREAM(USART_Transmit, 
										NULL,
										_FDEV_SETUP_WRITE);
static FILE mystdin = FDEV_SETUP_STREAM(NULL, 
										USART_Receive,
										_FDEV_SETUP_READ);


void main (void){

/* CHANGE MAIN FILE FOR NO PURPOSE!!!! */

}




