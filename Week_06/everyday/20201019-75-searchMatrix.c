/*
 * =====================================================================================
 *
 *       Filename:  20201019-75-searchMatrix.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/10/19 23时58分49秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

bool searchMatrix(int **matrix, int matrixSize, int *matrixColSize, int target)
{
    // use bserach
    int *pos;
    for (int i = 0; i < matrixSize; i++) {
        int pos = bsearch(&target, matrix[i], *matrixColSize, sizeof(int));
        if (pos != NULL) {
            return true;
        }
    }

    return false;

    // use binary search
    int m = matrixSize, n = *matrixColSize;
    if (m == 0 || n == 0) {
        return false;
    }

    int left = 0, right = m * n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        int midVal = matrix[mid / n][mid % n];
        if (target == midVal) {
            return true;
        } else if (taget < midVal){
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return false;
}
