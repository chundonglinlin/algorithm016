/*
 * =====================================================================================
 *
 *       Filename:  0930-122-maxProfit.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/10/01 00时04分15秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
int maxProfit(int* prices, int pricesSize){
    int maxprofit = 0;
    for (int i = 1; i < pricesSize; i++) {
        //当天比上一天涨
        int delta = prices[i] - prices[i - 1];
        if (delta > 0)
            maxprofit += delta;
    }
    return maxprofit;
}
