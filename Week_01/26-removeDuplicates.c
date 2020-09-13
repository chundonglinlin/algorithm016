/*
 * =====================================================================================
 *
 *       Filename:  26-removeDuplicates.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/09/13 23时48分10秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
int removeDuplicates(int* nums, int numsSize)
{
    if (numsSize <= 0) {
        return 0;
    }

    int pos = 0;
    for (int i = pos + 1; i < numsSize; i++) {
        if (nums[pos] != nums[i]) {
            pos++;
            if(pos < i) {
                nums[pos] = nums[i];
            }
        }
    }

    return pos + 1;
}
