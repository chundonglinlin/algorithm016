/*
 * =====================================================================================
 *
 *       Filename:  04-numIsland.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/11/01 16时26分21秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
void dfs(char** grid, int row, int col, int rowSize, int colSize)
{
    grid[row][col] = '0';

    if (row - 1 >= 0 && grid[row - 1][col] == '1') {
        dfs(grid, row - 1, col, rowSize, colSize);
    }

    if (row + 1 < rowSize && grid[row + 1][col] == '1') {
        dfs(grid, row + 1, col, rowSize, colSize);
    }

    if (col - 1 >= 0 && grid[row][col - 1] == '1') {
        dfs(grid, row, col - 1, rowSize, colSize);
    }

    if (col + 1 < colSize && grid[row][col + 1] == '1') {
        dfs(grid, row, col + 1, rowSize, colSize);
    }
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    // 考虑使用深度优先
    if (gridSize == 0) {
        return 0;
    }

    int num_islands = 0;
    for (int row = 0; row < gridSize; row++) {
        for (int col = 0; col < gridColSize[row]; col++) {
            if (grid[row][col] == '1') {
                num_islands++;
                dfs(grid, row, col, gridSize, gridColSize[row]);
            }
        }
    }

    return num_islands;
}
