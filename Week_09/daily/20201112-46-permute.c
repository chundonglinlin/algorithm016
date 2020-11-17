/*
 * =====================================================================================
 *
 *       Filename:  20201112-46-permute.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/11/12 21时37分01秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
void CopyDate(int *ans, int *nums, int numsSize)
{
    for (int i = 0; i < numsSize; i++) {
        ans[i] = nums[i];
    }

    return;
}

void Swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void compute(int *nums, int numsSize, int index, int **arr, int *row)
{
    if (index == numsSize - 1) {
        arr[*row] = (int *)malloc(numsSize * sizeof(int));
        CopyDate(arr[(*row)++], nums, numsSize);
        return;
    }

    for (int i = index; i < numsSize; i++) {
        Swap(&nums[index], &nums[i]);
        compute(nums, numsSize, index + 1, arr, row);
        Swap(&nums[i], &nums[index]);
    }

    return;
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    *returnSize = 0;
    if (nums == NULL || numsSize == 0) {
        return NULL;
    }

#define MAX_SIZE 10000
    int **arr = (int **)malloc(MAX_SIZE * sizeof(int *));
    int *cols = (int *)malloc(MAX_SIZE * sizeof(int));

    compute(nums, numsSize, 0, arr, returnSize);

    for (int i = 0; i < *returnSize; i++) {
        cols[i] = numsSize;
    }
    *returnColumnSizes = cols;

    return arr;
}
