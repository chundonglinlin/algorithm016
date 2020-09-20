/*
 * =====================================================================================
 *
 *       Filename:  283-moveZeroes.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/09/20 16时10分56秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
//解析思路：
//选用双指针
//pre指向非零
//i遍历所有数组
void moveZeroes(int* nums, int numsSize){
    // 双指针
    int pre = 0;//指向非零下标
    for (int i = 1; i < numsSize; i++) {
        if (nums[pre] == 0) {
            if (nums[i] == 0) {
                //do nothing
            } else {
                //swap
                nums[pre] = nums[i];
                nums[i] = 0;
                // 后移
                pre++;
            }
        } else {
            // 后移
            pre++;
        }
    }
}

