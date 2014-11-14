/*
 * filter.c
 *
 *  Created on: Nov 12, 2014
 *      Author: Andrei
 */

#include "filter.h"



int encoderFilterTab[2][MEDIAN_FILTER_DEPTH];
int medianFilterTab[2][MEDIAN_FILTER_DEPTH];
int averageFilterTab[2][AVERAGE_FILTER_DEPTH];



int SortTab(int tab[], int size){
	for(int i = 0 ; i < size -1 ; i++){
		for(int j = i+1; j< size -1; j++){
			if(tab[i]>tab[j]) {
				int tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
		}
	}

	return 0;
}


int PushToTab(int tab[] ,int data , int size){
		for(int i = size-1 ; i > 0 ; i--){
			tab[i] = tab[i-1];
		}
		tab[0] = data;

		return 0;

}

int CopyTab(int tab_d[],int tab_s[] , int size){
	for(int i = 0 ; i < size ; i++){
		tab_d[i] = tab_s[i];
	}
	return 0;
}



int GetMedianValue (int tab[], int size){

	CopyTab(medianFilterTab, tab, size);
	SortTab(medianFilterTab, size);

	return medianFilterTab[size/2];
}

int GetAverageValue (int tab[], int size){


	long sum = 0;
	for(int i = 0 ; i < size ; i++){
		sum+= tab[i];
	}
	return sum/size;
}




