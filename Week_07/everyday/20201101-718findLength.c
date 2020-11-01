/*
 * =====================================================================================
 *
 *       Filename:  20201101-718findLength.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/11/01 15时07分39秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
int maxLength(int* A, int* B, int addA, int addB, int len) {
    int ret = 0, k = 0;
    for (int i = 0; i < len; i++) {
        //相对位置相同的重复子数组
        if (A[addA + i] == B[addB + i]) {
            k++;
        } else {
            k = 0;
        }
        ret = fmax(ret, k);
    }
    return ret;
}

// 滑动窗口
/* 枚举 A 和 B 所有的对齐方式。对齐的方式有两类：
   第一类为 A 不变，B 的首元素与 A 中的某个元素对齐；
   第二类为 B 不变，A 的首元素与 B 中的某个元素对齐。
   对于每一种对齐方式，我们计算它们相对位置相同的重复子数组即可。
*/
int findLength(int* A, int ASize, int* B, int BSize) {
    int ret = 0;
    for (int i = 0; i < ASize; i++) {
        //第一类
        int len = fmin(BSize, ASize - i);
        int maxlen = maxLength(A, B, i, 0, len);
        ret = fmax(ret, maxlen);
    }

    for (int i = 0; i < BSize; i++) {
        //第二类
        int len = fmin(ASize, BSize - i);
        int maxlen = maxLength(A, B, 0, i, len);
        ret = fmax(ret, maxlen);
    }
    return ret;
}

