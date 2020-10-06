/*
 * =====================================================================================
 *
 *       Filename:  1006-1-twoSum.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/10/06 20时09分19秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    *returnSize = 0;

    // 暴力循环
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (target == nums[i] + nums[j]) {
                int *result = malloc(sizeof(int) * 2);
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }

    return NULL;

    // hash
#define MAX_SIZE 10240
    int hash[MAX_SIZE];
    memset(hash, -1, sizeof(int) * MAX_SIZE);

    for (int i = 0; i < numsSize; i++) {
        int pos = hash[(target - nums[i] + MAX_SIZE) % MAX_SIZE];
        if (pos != -1) {
            int *result = malloc(sizeof(int) * 2);
            result[0] = pos;
            result[1] = i;
            *resturSize = 2;
            return result;
        }

        hash[(nums[i] + MAX_SIZE) % MAX_SIZE] = i;
    }

    return NULL;
}
