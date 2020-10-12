/*
 * =====================================================================================
 *
 *       Filename:  1012-64-minPathSum.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/10/12 23时14分59秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>

int minPathSum(int **grid, int gridSize, int *gridColSize) 
{
    int row = gridSize, col = gridColSize[0];
    int **dp = grid;

    // row
    for (int i = 1; i < row; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    // col
    for (int j = 1; j < col; j++) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    for (int i = 1; i < row; i++) {
        for (int j = 1; j < col; j++) {
            dp[i][j] = fmin(dp[i - 1][j], dp[i][j -1]) + grid[i][j];
        }
    }

    return dp[row - 1][col - 1];
}
