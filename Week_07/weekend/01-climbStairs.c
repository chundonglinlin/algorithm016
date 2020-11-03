/*
 * =====================================================================================
 *
 *       Filename:  01-climbStairs.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/11/01 16时17分39秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>

int climbStairs(int n){
    // 第n层，等于第n-1层+第n-2层
    if (n <= 2) {
        return n;
    }

    int step1 = 1, step2 = 2, temp;
    for (int i = 3; i <= n; i++) {
        temp = step1;
        step1 = step2;
        //当前current = step1 + step2
        step2 = temp + step1;
    }

    return step2;
}

