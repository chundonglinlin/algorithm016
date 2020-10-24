/*
 * =====================================================================================
 *
 *       Filename:  20201024-15-threeSum.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/10/24 21时05分29秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if (nums == NULL || numsSize < 3) {
        return NULL;
    }
    
    int low, high, now = 0;
    long maxSize = (long)numsSize * 6;
    int **res = (int **)malloc(sizeof(int *) * maxSize);
    *returnColumnSizes = (int *)malloc(sizeof(int) * maxSize);

    // 快排
    qsort(nums, numsSize, sizeof(int), compare);
    
    while (nums[now] <= 0 && (now + 2) < numsSize) {
        while (now > 0 && (now + 2) < numsSize&& nums[now] == nums[now - 1]) {
            now++;
        }
        if ((now + 2) >= numsSize) {
            break;
        }
        low = now + 1;
        high = numsSize - 1;
        int target = -nums[now];
        while(low < high) {
            if (nums[low] + nums[high] == target) {
                res[(*returnSize)] = (int *)malloc(sizeof(int) * 3);
                res[(*returnSize)][0] = nums[now];
                res[(*returnSize)][1] = nums[low];
                res[(*returnSize)][2] = nums[high];
                (*returnColumnSizes)[(*returnSize)] = 3;
                (*returnSize)++;
                int temp_low = nums[low];
                int temp_high = nums[high];
                while (low < numsSize && nums[low] == temp_low) {
                    low++;
                }
                while (high > now && nums[high] == temp_high) {
                    high--;
                }
                if (high <= low) {
                    break;
                }else {
                    continue;
                }
            } 
            
            if (nums[low] + nums[high] < target) {
                low++;
                continue;
            }
            
            if (nums[low] + nums[high] > target) {
                high--;
                continue;
            }
        }
        
        now++;
        low = now + 1;
        high = numsSize - 1;
        continue;
    }
    
    return res;
}
