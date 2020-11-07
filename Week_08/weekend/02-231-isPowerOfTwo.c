/*
 * =====================================================================================
 *
 *       Filename:  02-231-isPowerOfTwo.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/11/07 18时13分24秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
bool isPowerOfTwo(int n){
    if (n == 0) {
        return false;
    }

    while (n % 2 == 0) {
        n /= 2;
    }

    return n == 1;
}
