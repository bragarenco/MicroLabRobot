/*
 * filter.h
 *
 *  Created on: Nov 12, 2014
 *      Author: Andrei
 */

#ifndef FILTER_H_
#define FILTER_H_


#define MEDIAN_FILTER_DEPTH 7
#define AVERAGE_FILTER_DEPTH 25


int SortTab(int tab[], int size);
int PushToTab(int tab[] ,int data , int size);
int CopyTab(int tab_d[],int tab_s[] , int size);
int GetMedianValue (int tab[], int size);
int GetAverageValue (int tab[], int size);


#endif /* FILTER_H_ */
