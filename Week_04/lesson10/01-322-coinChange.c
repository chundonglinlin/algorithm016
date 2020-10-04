/*
 * =====================================================================================
 *
 *       Filename:  01-322-coinChange.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/10/04 10时24分00秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>

#define MIN(a, b) a < b ? a : b
int coinChange(int* coins, int coinsSize, int amount){
    int dp[amount + 1];
    dp[0] = 0;

    // 计算顺序，从小到大 i表示需要凑的总数
    for (int i = 1; i <= amount; ++i) {
        // 初始化
        dp[i] = INT_MAX;
        for (int j = 0; j < coinsSize; ++j) {
            // 边界情况
            if (coins[j] <= i) {
                dp[i] = MIN(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}


