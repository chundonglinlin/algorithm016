/*
 * =====================================================================================
 *
 *       Filename:  0929-70-climbStairs.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/09/29 10时19分32秒
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
    // fib 公式
    // f(n) = f(n-1) + f(n-2)
    if (n <= 2) {
        return n;
    }

    int pre = 1, cur = 2, next;
    for (int i = 3; i <= n; i++) {
        next = pre + cur;
        pre = cur;
        cur = next;
    }

    return cur;
}
