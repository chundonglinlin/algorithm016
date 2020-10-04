/*
 * =====================================================================================
 *
 *       Filename:  01-69-mySqrt.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/10/04 11时05分06秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
int mySqrt(int x){
    // 暴力循环
    /*int result = 0;
    for (long i = 1;; i++) {
        long temp = i * i;
        if (temp > x) {
            result = i - 1;
            break;
        } 
    }*/

    // 二分查找
    int result = 0;
    int low = 0, high = x;
    while (low <= high) {
        long mid = (low + high) / 2;
        long sqrt = mid * mid;
        if (sqrt <= x) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return result;
}
