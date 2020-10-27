/*
 * =====================================================================================
 *
 *       Filename:  20201027-367-isPerfectSquare.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/10/27 22时52分24秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
bool isPerfectSquare(int num) 
{
    int left = 1, right = num;
    while (left <= right) {
        long mid = (left + right) / 2;
        long sqrt = mid * mid;
        if (sqrt == num) {
            return true;
        } else if (sqrt < num) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return false;
}
