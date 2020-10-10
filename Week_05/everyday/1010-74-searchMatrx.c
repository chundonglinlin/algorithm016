/*
 * =====================================================================================
 *
 *       Filename:  1010-74-searchMatrx.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/10/10 23时47分48秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>

bool searchMatrix(int **matrix, int matrixSize, int *matrixColSize, int target)
{
    int row = matrixSize;
    if (row == 0) {
        return false;
    }

    int col = *matrixColSize;

    int left = 0, right = row * col - 1;
    int idx, element;

    while (left <= right) {
        idx = (left + right) / 2;
        element = matrx[idx / n][idx % n];
        if (element == target) {
            return true;
        } else if (element < target) {
            left = idx + 1;
        } else {
            right = idx - 1;
        }
    }

    return false;
}
