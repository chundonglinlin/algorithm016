/*
 * =====================================================================================
 *
 *       Filename:  1003-367-isPerfectSquare.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/10/03 08时26分28秒
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
    //二分法
    bool result = false;
    long low = 1, high = num;
    while (true) {
        if (low > high) {
            break;
        }

        long mid = (low + high) / 2;
        long sqrt = mid * mid;

        if (sqrt > num) {
            high = mid - 1;
        } else if (sqrt == num) {
            result = true;
            break;
        } else {
            low = mid + 1;
        }
    }

    return result;
}
