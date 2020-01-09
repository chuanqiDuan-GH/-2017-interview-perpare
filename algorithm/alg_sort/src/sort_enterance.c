#include <stdio.h>
#include "sort_algorithm.h"


int RandomNum(int lower, int upper)
{
    int num = 0;
    num = rand() % upper + lower;
    printf("%s : %d\n", __FUNCTION__, num);
    return num;
}

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

void ImputDataToArr(int *arr)
{
    if (NULL == arr) {
        printf("arr is null\n");
        return;
    }

    for (int i = 0; i < ARR_LEN; i++) {
        arr[i] = RandomNum(LOWER, UPPER);
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[ARR_LEN] = { 0 };
    ImputDataToArr(arr);
    ShowArr(arr, ARR_LEN);

    //BubSort(arr, len);
    //QuiSort(arr, 0, len - 1);
    //InsSort(arr, len);
    //SheSort(arr, len);
    //SelSort(arr, ARR_LEN);
    MergeSort(arr, 0, ARR_LEN - 1);

    ShowArr(arr, ARR_LEN);
}
