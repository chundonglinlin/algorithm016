/*
 * =====================================================================================
 *
 *       Filename:  20201028-128-rob.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/10/28 23时06分23秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
int rob(int* nums, int numsSize){
    if(numsSize == 0) {
        return 0;
    }

    if (numsSize == 1) {
        return nums[0];
    }

    int first = nums[0], second = fmax(nums[0], nums[1]);
    for(int i = 2; i < numsSize; i++) {
        int temp = second;
        second = fmax(first + nums[i], second);
        first = temp;
    }
    return second;
}
