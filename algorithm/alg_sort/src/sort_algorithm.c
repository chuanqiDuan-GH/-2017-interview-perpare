#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

void BubSort(int *arr, const unsigned int len) 
{
    if (NULL == arr || len <= 1) {
        return;
    }

    unsigned int outIdx = 0;
    unsigned int innIdx = 0;
    unsigned int swapSign = 0;
    int saveNum = 0;

    for (outIdx = len; outIdx > 0; outIdx--) {
        swapSign = 0;
        for (innIdx = 0; innIdx < len; innIdx++) {
            if (arr[innIdx] > arr[innIdx+1]) {
                saveNum = arr[innIdx];
                arr[innIdx] = arr[innIdx+1];
                arr[innIdx+1] = saveNum;
                swapSign = 1;
            }
        }

        if (swapSign == 0) {
            break;
        }
    }
    return;
}

/*
 左右下标边界不需要用unsigned int定义
 自减时有可能变为极大值(0自减之后)
 导致函数异常
 */
void QuiSort(int *arr, int left, int right) 
{
    if (NULL == arr || left < 0 || right < 0 || left >= right) {
        return;
    }

    int i = left;
    int j = right;
    int save = arr[left];

    if (left < right) {
        while (i < j) {
            while (i < j && arr[j] > save) {
                j--;
            }
            if (i < j) {
                arr[i++] = arr[j];
            }

            while (i < j && arr[i] <= save) {
                i++;
            }
            if (i < j) {
                arr[j--] = arr[i];
            }
        }
        arr[i] = save;
        QuiSort(arr, left, i - 1);
        QuiSort(arr, i + 1, right);
    }
    return;
}

void InsSort(int *arr, int len)
{
    if (NULL == arr || len <= 1) {
        return;
    }

    int outIdx = 0;
    int innIdx = 0;
    unsigned int save = 0;

    for (outIdx = 1; outIdx < len; outIdx++) {
        for (innIdx = outIdx-1; innIdx >= 0; innIdx--) {
            if (arr[innIdx+1] < arr[innIdx]) {
                save = arr[innIdx+1];
                arr[innIdx+1] = arr[innIdx];
                arr[innIdx] = save;
            }
        }
    }
}

void SheSort(int *arr, const int len)
{
    if (NULL == arr || len <= 1) {
        return;
    }

    int oIdx = 0;
    int iIdx = 0;
    int save = 0;
    int gap = len / 2;

    while (gap > 0) {
        for (oIdx = gap; oIdx < len; oIdx++) {
            for (iIdx = oIdx - gap; iIdx >= 0; iIdx -=gap) {
                if (arr[iIdx + gap] < arr[iIdx]) {
                    save = arr[iIdx + gap];
                    arr[iIdx + gap] = arr[iIdx];
                    arr[iIdx] = save;
                }
            }
        }
        gap /= 2;
    }
}

/*
 数组下标使用一定要仔细
 内外层下标赋值一定要仔细
 */
void SelSort(int *arr, const int len)
{
    if (NULL == arr || len <= 1) {
        return;
    }

    int oIdx = 0;
    int iIdx = 0;
    int saveIdx = 0;
    int save = 0;
    
    for (oIdx = 0; oIdx < len; oIdx++) {
        saveIdx = oIdx;
        for (iIdx = oIdx + 1; iIdx < len; iIdx++) {
            if (arr[iIdx] < arr[saveIdx]) {
                saveIdx = iIdx;
            }
        }
        save = arr[oIdx];
        arr[oIdx] = arr[saveIdx];
        arr[saveIdx] = save;
    }
}

void Merge(int *arr, int low, int mid, int high)
{
    if (NULL == arr || low < 0 || high < 0 || low >= high) {
        return;
    }

    int i = low;
    int j = mid + 1;
    int p = 0;

    int *arrT = (int *)malloc((high - low + 1) * sizeof(int));
    if (NULL == arrT) {
        printf("arrT malloc fail\n");
        return;
    }

    while (i <= mid && j <= high) {
        arrT[p++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];
    }

    while (i <= mid) {
        arrT[p++] = arr[i++];
    }

    while (j <= high) {
        arrT[p++] = arr[j++];
    }

	//拷贝到源数组时,要注意这里使用的是下标,所以上限是需要处理等于的场景,要么会导致赋值缺失
    for (i = low, p = 0; i <= high; i++, p++) {
        arr[i] = arrT[p];
    }

    free(arrT);
    arrT = NULL;
}

void MergeSort(int *arr, int low, int high)
{
    if (NULL == arr || low < 0 || high < 0 || low >= high) {
        return;
    }

    int mid = (low + high) / 2;

    if (low < high) {
        MergeSort(arr, low, mid); 
        MergeSort(arr, mid + 1, high); 
        Merge(arr, low, mid, high);
    }
}

void SiftDown(int *arr, int mid, int len)
{
    if (NULL == arr || len <= 1) {
        return;
    }
    
    int leftChild = 2 * mid + 1;
    int rightChild = 2 * mid + 2;
    int present = mid;

    if (leftChild < len && arr[leftChild] > arr[present]) {
        present = leftChild;
    }

    if (rightChild < len && arr[rightChild] > arr[present]) {
        present = rightChild;
    }

    if (present != mid) {
        int tmp = arr[mid];
        arr[mid] = arr[present];
        arr[present] = tmp;

        //不断的下沉处理,直到无子节点
        SiftDown(arr, present, len);
    }
}

void BuildHeap(int *arr, int len)
{
    if (NULL == arr || len <= 1) {
        printf("params err\n");
        return;
    }

    for (int idx = len / 2; idx >= 0; idx--) {
        SiftDown(arr, idx, len);
    }
}

//最大堆(升序)
void HeapSort(int *arr, int len)
{
    if (NULL == arr || len <= 1) {
        printf("params err\n");
        return;
    }
    //堆化数组
    BuildHeap(arr, len);

    //取出堆头节点,放置到数组尾部,数组长度减一,继续下沉处理
    for (int idx = len - 1; idx > 0; idx--) {
        int tmpValue = arr[idx];
        arr[idx] = arr[0];
        arr[0] = tmpValue;

        len--;

        SiftDown(arr, 0, len);
    }
}

int FindMaxAndMin(int *arr, int len, int *maxNum, int *minNum)
{
    if (NULL == arr || len < 0) {
        printf("params err\n");
        return -1;
    }
    *maxNum = arr[0];
    *minNum = arr[0];

    for (int idx = 0; idx < len; idx++) {
        if (arr[idx] > *maxNum) {
            *maxNum = arr[idx];
        }

        if (arr[idx] < *minNum) {
            *minNum = arr[idx];
        }
    }
    return 0;
}

void CountingSort(int *arr, int len)
{
    if (NULL == arr || len < 0) {
        printf("params err\n");
        return;
    }

    int max = 0;
    int min = 0;

    int ret = FindMaxAndMin(arr, len, &max, &min);
    if (ret < 0) {
        printf("find max or min num err\n");
        return;
    }

    //申请计数数组空间
    int lenT = max + 1;
    int *arrT = (int *)malloc(lenT * sizeof(int));
    if (NULL == arrT) {
        printf("malloc fail\n");
        return;
    }
    memset(arrT, 0, lenT * sizeof(int));

    //根据源数组计数
    int idx = 0;
    for (; idx < len; idx++) {
        arrT[arr[idx]]++;
    }

    //读取计数数组并逐个赋值到源数组
    for (int idxT = min, idx = 0; idxT <= max; idxT++) {
        if (arrT[idxT] > 0) {
            while (arrT[idxT]--) {
                arr[idx++]  = idxT;
            }
        }
    }

    free(arrT);
    arrT = NULL;
}

void BucketSort(int *arr, int len)
{
    if (NULL == arr || len <= 1) {
        return; 
    }

    int maxNum = 0;
    int minNum = 0;

    //取得待排序集合的最大以及最小元素    
    int ret = FindMaxAndMin(arr, len, &maxNum, &minNum);
    if (ret < 0) {
        return;
    }

    //计算桶数量
    int bucketNum = (maxNum - minNum) / BUCKET_STEP + 1;
    if (bucketNum == 1) {
        printf("no need to sort data\n");
        return;
    }
    
    //申请空间存储实际所需桶内存
    int (*bucket)[10] = (int (*)[10])malloc(bucketNum * BUCKET_STEP * sizeof(int));
    if (NULL == bucket) {
        printf("malloc fail\n");
        return;
    }
    memset(bucket, 0, bucketNum * BUCKET_STEP * sizeof(int));

    //申请空间记录每个桶中实际存储元素个数
    int *bucketLenSet = (int *)malloc(bucketNum * sizeof(int));
    if (NULL == bucketLenSet) {
        printf("malloc fail\n");
        return;
    }
    memset(bucketLenSet, 0, bucketNum * sizeof(int));

    //将待排序集合中的元素存储到指定值域的桶中
    int idx = 0;
    for (; idx < len; idx++) {
        int bn = (arr[idx] - minNum) / BUCKET_STEP;
        bucket[bn][bucketLenSet[bn]++] = arr[idx];
    }

    //依次遍历各个桶,并对其进行排序
    idx = 0;
    for (int bucketNumIdx = 0; bucketNumIdx < bucketNum; bucketNumIdx++) {
        if (bucketLenSet[bucketNumIdx]) {

            //使用选择排序处理各个桶中的数据
            SelSort(bucket[bucketNumIdx], bucketLenSet[bucketNumIdx]);         

            //最终将各个桶中排序后的元素重新赋值到源数组中
            for (int bucketIdx = 0; bucketIdx < bucketLenSet[bucketNumIdx]; bucketIdx++) {
                arr[idx++] = bucket[bucketNumIdx][bucketIdx];
            }
        }
    }

    //释放手动申请的内存
    free(bucketLenSet);
    bucketLenSet = NULL;

    free(bucket);
    bucket = NULL;
}
