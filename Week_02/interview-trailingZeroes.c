/*
 * =====================================================================================
 *
 *       Filename:  interview-trailingZeroes.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/09/20 22时50分07秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
int trailingZeroes(int n){
    //数学题：关键在于， 阶乘末尾 0 的个数就是因数中 5 的个数
    int result = 0;
    while (n) {
        n /= 5;
        result += n;
    }

    return result;
}
