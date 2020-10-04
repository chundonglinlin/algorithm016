/*
 * =====================================================================================
 *
 *       Filename:  1004-169-majorElement.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/10/04 16时54分09秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>

int majorElement(int *nums, int numsSize)
{
    //摩尔投票
    int count = 1, major = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (major == nums[i]) {
            count++;
        } else {
            count--;
        }

        if (count == 0) {
            major = nums[i + 1];
        }
    }

    return major;
}
