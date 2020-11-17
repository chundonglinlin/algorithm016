/*
 * =====================================================================================
 *
 *       Filename:  20201114-238-productExceptSelf.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/11/14 17时50分37秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize){
	*returnSize = 0;
    if (nums == NULL || numsSize <= 0) {
		return NULL;
	}

    int n = numsSize;
	int *result = (int *)malloc(sizeof(int) * n);
	if (result == NULL) {
		return NULL;
	}

	int left[n], right[n];

    // i元素左侧的乘积
    left[0] = 1;
	for (int i = 1; i < n; i++) {
		left[i] = left[i - 1] * nums[i - 1];
	}

    // 右侧乘积
	right[n - 1] = 1;
	for (int i = n - 2; i >= 0; i--) {
		right[i] = right[i + 1] * nums[i + 1];
	}

    // 两侧乘积
	for (int i = 0; i < n; i++) {
		result[i] = left[i] * right[i] ;
	}
	*returnSize = n;
	return result;
}
