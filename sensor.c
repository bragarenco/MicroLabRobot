#include "sensor.h"
#include "adc.h"
 
 int posTab[5] = {-25, -10, 0 , 10, 25};
 int adcRef[5] = {1, 2, 3, 4, 0};



//|  436|  411|  224|  157|  236|
					
//152|  132|  133|  388|  411|

//197|  151|  184|  223|  340|

 int minValues[5] =  {197,  151,  184,  223,  340};
 int maxValues[5] =  {  3,    5,    3,    3,    3};

int GetSensorADC(int i){
	int pos = adcRef[i];

	return GetADC(pos);

}

int GetSensor(int i){

	float adc = GetSensorADC(i) -  maxValues[i];

	int val = 100.0 - (adc *100/(minValues[i] - maxValues[i]));

	return val;
}


 int GetLinePos(void){

 	float  upS = 0;
	float  dnS = 0;
	
	for (int i= 0; i<5 ; i++)
	{
		
		upS+= posTab[i]*(GetSensor(i));
		dnS+= (GetSensor(i));
		
	}


	int linePos = upS/dnS;


//	printf("| pos ->   %d    %d    %4d\r\n", (int)(upS*1),(int)(dnS*1), (int)(20 + 3*(linePos - 20)));

	return linePos;
 }
