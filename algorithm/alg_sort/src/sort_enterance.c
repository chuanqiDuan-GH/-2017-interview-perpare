#include <stdio.h>
#include "sort_algroithm.h"


void ShowArr(int *arr, const unsigned int len)
{
    if (NULL == arr && len == 0) {
    return;	
    }

    unsigned int arrIdx = 0;

    while (arrIdx < len) {
    printf("arr[%d]:%d ", arrIdx, arr[arrIdx]); 
    arrIdx++;
    }
    printf("\n");
}

int main()
{
    int arr[5] = {91, 19, 15, 10, 0};
    unsigned int len = sizeof(arr)/sizeof(int);

    //BubSort(arr, len);
    //QuiSort(arr, 0, len - 1);
    //InsSort(arr, len);
    //SheSort(arr, len);
    //SelSort(arr, len);
    MergeSort(arr, 0, len - 1);

    ShowArr(arr, sizeof(arr)/sizeof(int));
}
