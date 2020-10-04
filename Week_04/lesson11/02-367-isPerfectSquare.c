/*
 * =====================================================================================
 *
 *       Filename:  02-367-isPerfectSquare.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/10/04 11时48分49秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
bool isPerfectSquare(int num){
    bool result = false;
    int low = 0, high = num;
    while (low <= high) {
        long mid = (low + high) / 2;
        long sqrt = mid * mid;
        if (sqrt < num) {
            low = mid + 1;
        } else if (sqrt == num) {
            result = true;
            break;
        } else {
            high = mid - 1;
        }
    }

    return result;
}
