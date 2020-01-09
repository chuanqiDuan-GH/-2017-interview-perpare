#ifndef __SORT_ALGORITHM_H__
#define __SORT_ALGORITHM_H__


#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "common.h"

void InsSort(int *arr, const unsigned int len);
void BubSort(int *arr, const unsigned int len); 
void QuiSort(int *arr, unsigned int left, unsigned int right); 
void SheSort(int *arr, const int len);
void SelSort(int *arr, const int len);
void MergeSort(int *arr, int low, int high);

#endif // __SORT_ALGORITHM_H__