/*
 * =====================================================================================
 *
 *       Filename:  20201117-1030-allCellsDistOrder.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/11/17 13时44分46秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int dist(int r1, int c1, int r2, int c2) {
    return fabs(r1 - r2) + fabs(c1 - c2);
}

int** allCellsDistOrder(int R, int C, int r0, int c0, int* returnSize, int** returnColumnSizes) {
    // 桶排序
    int maxDist = fmax(r0, R - 1 - r0) + fmax(c0, C - 1 - c0);
    int* bucket[maxDist + 1][2 * (R + C)];
    int bucketSize[maxDist + 1];
    memset(bucketSize, 0, sizeof(bucketSize));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            int d = dist(i, j, r0, c0);
            int* tmp = malloc(sizeof(int) * 2);
            tmp[0] = i, tmp[1] = j;
            bucket[d][bucketSize[d]++] = tmp;
        }
    }

    int** ret = malloc(sizeof(int*) * R * C);
    *returnColumnSizes = malloc(sizeof(int) * R * C);
    for (int i = 0; i < R * C; i++) {
        (*returnColumnSizes)[i] = 2;
    }
    *returnSize = 0;
    for (int i = 0; i <= maxDist; i++) {
        for (int j = 0; j < bucketSize[i]; j++) {
            ret[(*returnSize)++] = bucket[i][j];
        }
    }
    return ret;
}
