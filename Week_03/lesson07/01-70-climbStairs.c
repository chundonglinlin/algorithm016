/*
 * =====================================================================================
 *
 *       Filename:  01-70-climbStairs.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/09/22 09时41分47秒
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
    // clime n 层 = n-1层 + n-2层
    if (n <= 2) {
        return n;
    }

    int step1 = 1, step2 = 2, current;
    for (int i = 3; i <= n; i++) {
        //当前楼层等上一楼层+上上楼层
        current = step1 + step2;

        //swap
        step1 = step2;
        step2 = current;
    }

    return current;
}

