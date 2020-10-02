/*
 * =====================================================================================
 *
 *       Filename:  1002-200-numIslands.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/10/02 20时47分35秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
//deepth first search
void dfs(int **grid, int row, int col, int rowSize, int colSize)
{
    grid[row][col] = '0';

    if (row - 1 >= 0 && grid[row - 1][col] == '1') {
        dfs(row - 1, col, rowSize, colSize);
    }
    if (row + 1 < rowSize && grid[row + 1][col] == '1') {
        dfs(row + 1, col, rowSize, colSize);
    }
    if (col - 1 >= 0 && grid[row][col - 1] == '1') {
        dfs(row, col - 1, rowSize, colSize);
    }
    if (col + 1 < colSize && grid[row][col + 1] == '1') {
        dfs(row, col + 1, rowSize, colSize);
    }
}

int numsIslands(int **grid, int gridSize, int *gridColumeSize)
{
    if (gridSize == 0) {
        return 0;
    }

    int nums_islands = 0;
    for (int row = 0; row < gridSize; row++) {
        for (int col = 0; col < gridColumeSize[row]; col++) {
            if (grid[row][col] == '1') {
                nums_islands++;
                dfs(grid, row, col, gridSize, gridColumsSize[row]);
            }
        }
    }

    return nums_islands;
}
