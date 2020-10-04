/*
 * =====================================================================================
 *
 *       Filename:  02-122-maxProfit.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/10/04 12时18分30秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>

int maxProfit(int *prices, int pricesSize)
{
    int max = 0;
    for (int i = 1; i < pricesSize; i++) {
        int delta = prices[i] - prices[i - 1];
        if (delta > 0) {
            max += delta;
        }
    }

    return max;
}
