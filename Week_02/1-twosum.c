/*
 * =====================================================================================
 *
 *       Filename:  1-twosum.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/09/19 20时20分39秒
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
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    // 暴力递归
/*    for (int i  = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                *returnSize = 2;
                int *result = malloc(sizeof(int) * (*returnSize));
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }

    *returnSize = 0;
    return NULL;
*/
    // hash
#define MAX_SIZE 10240
    int hash[MAX_SIZE];
    memset(hash, -1, sizeof(int) * MAX_SIZE);
    for (int i = 0; i < numsSize; i++) {
        int pos = hash[(target - nums[i] + MAX_SIZE) % MAX_SIZE];
        if (pos != -1) {
             *returnSize = 2;
            int *result = malloc(sizeof(int) * (*returnSize));
            result[0] = pos;
            result[1] = i;
            return result;
        }

        hash[(nums[i] + MAX_SIZE) % MAX_SIZE] = i;
    }

    *returnSize = 0;
    return NULL;
}
