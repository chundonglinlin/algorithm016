/*
 * =====================================================================================
 *
 *       Filename:  1008-53-maxSubArray.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/10/10 23时29分42秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>

#define max(a, b) (a > b ? a : b)

int maxSubArray(int *nums, int numsSize)
{
    int maxSub = nums[0], pre = 0;
    for (int i = 0; i < numsSize; i++) {
        pre = max(pre + nums[i], nums[i]);
        maxSub = max(maxSub, pre);
    }


    return maxSub;
}
