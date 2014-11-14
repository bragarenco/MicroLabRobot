#include "bumper.h"


void BumperInit(void){
	

 BUMPER_PORT |= (1<<BUMPER_PIN1)|
 				(1<<BUMPER_PIN2)|
				(1<<BUMPER_PIN3);
 BUMPER_DDR &= ~((1<<BUMPER_PIN1)|
 				(1<<BUMPER_PIN2)|
				(1<<BUMPER_PIN3));

}


int TestBumper1(void){
	if(BUMPER_PIN & (1<< BUMPER_PIN1))
		return 0;
	else
		return 1;
}
int TestBumper2(void){
	if(BUMPER_PIN & (1<< BUMPER_PIN2))
		return 0;
	else
		return 1;
}
int TestBumper3(void){
	if(BUMPER_PIN & (1<< BUMPER_PIN3))
		return 0;
	else
		return 1;
}

