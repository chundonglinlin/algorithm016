/*
 * =====================================================================================
 *
 *       Filename:  20201022-53-maxSubArray.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/10/22 11时38分17秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#define fmax(a, b) (a > b ? a : b)
int maxSubArray(int *nums, int numsSize)
{
    int result = nums[0], sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum = fmax(sum + nums[i], nums[i]);
        result = fmax(result, sum);
    }

    return result;
}
