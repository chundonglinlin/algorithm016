/*
 * =====================================================================================
 *
 *       Filename:  283-moveZeroes.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/09/13 23时59分39秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
void moveZeroes(int* nums, int numsSize){
    int pos = 0;
    for (int i = pos + 1; i < numsSize; i++) {
        if (nums[pos] == 0) {
            if (nums[i] != 0) {
                int temp = nums[pos];
                nums[pos] = nums[i];
                nums[i] = temp;
                pos++;
            } else {
                // do nothing
            }
        } else {
            // follow i sequence
            pos++;
        }
    }

    return pos;
}

