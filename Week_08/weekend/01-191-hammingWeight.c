/*
 * =====================================================================================
 *
 *       Filename:  01-191-hammingWeight.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/11/06 18时38分37秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>

int hammingWeight(int num)
{
    int count = 0;
    while (num) {
        count++;
        num = num & (num - 1);
    }
    return count;
}
