/*
 * =====================================================================================
 *
 *       Filename:  offer-49.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/09/20 15时46分34秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
//解析思路：
//丑数就是2、3、5的倍数，且依次将其存入到指定数组里

int min(int a,int b,int c){
    if (a < b)
    {
        return a < c?a:c;
    }
    else
    {
        return b < c?b:c;
    }
}
int nthUglyNumber(int n){
    int p1 = 0;
    int p2 = 0;
    int p3 = 0;

    int *arr = (int *)malloc(n*sizeof(int));
    arr[0] = 1;

    if (n == 0) {
        return 0;
    }

    for (int index = 1; index < n; index++) {
        arr[index] = min(2*arr[p1],3*arr[p2],5*arr[p3]);
        if (arr[index] == 2*arr[p1]) {
            p1++;
        }

        if (arr[index] == 3*arr[p2]) {
            p2++;
        }

        if (arr[index] == 5*arr[p3]) {
            p3++;
        }
    }

    return arr[n - 1];
}
