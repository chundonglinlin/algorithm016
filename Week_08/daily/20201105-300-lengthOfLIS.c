/*
 * =====================================================================================
 *
 *       Filename:  20201105-300-lengthOfLIS.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/11/05 22时32分51秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>

/*int lengthOfLIS(int* nums, int numsSize){
    if (numsSize == 0) {
        return 0;
    }
    // 动态规划
    int dp[numsSize];
    dp[0] = 1;
    int maxans = 1;
    for (int i = 1; i < numsSize; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = fmax(dp[i], dp[j] + 1);
            }
        }
        maxans = fmax(maxans, dp[i]);
    }
    return maxans;
}*/
int lengthOfLIS(int *nums, int numsSize)
{
    int len = 1, n = numsSize;
    if (n == 0) {
        return 0;
    }

    // 动态规划 + 二分查找
    int dp[n + 1];
    dp[len] = nums[0];
    for (int i = 1; i < n; ++i) {
        if (nums[i] > dp[len]) {
            dp[++len] = nums[i];
        } else {
            int l = 1, r = len, pos = 0; // 如果找不到说明所有的数都比 nums[i] 大，此时要更新 dp[1]，所以这里将 pos 设为 0
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (dp[mid] < nums[i]) {
                    pos = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            dp[pos + 1] = nums[i];
        }
    }
    return len;
}

