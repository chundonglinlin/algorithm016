/*
 * =====================================================================================
 *
 *       Filename:  20201113-1122-maxProfit.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/11/14 17时50分12秒
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
        if (prices[i] > prices[i - 1])
            maxprofit += prices[i] - prices[i - 1];
    }
    return maxprofit;
}
