/*
 * =====================================================================================
 *
 *       Filename:  01-64-minPathSum.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/10/25 15时36分36秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
int minPathSum(int** grid, int gridSize, int* gridColSize){
    int m = gridSize, n = gridColSize[0];
    int** dp = grid;
    dp[0][0] = grid[0][0];
    for (int i = 1; i < m; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    for (int j = 1; j < n; j++) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = fmin(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }
    return dp[m-1][n-1];
}
