/*
 * =====================================================================================
 *
 *       Filename:  07-56-merge.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/11/07 19时39分22秒
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
int cmp(const void * a,const void * b)
{//按起始点从小到大排序
    int ** p1 = (int **)a;
    int ** p2 = (int **)b;
    return (** p1) - (** p2);
}

int Cmp(int **a, int **b)
{
    return (*a)[0] - (*b)[0];
}

int Max(int a, int b)
{
    return a > b ? a : b;
}
int **merge(int **intervals, int intervalsSize, int *intervalsColSize, int *returnSize, int **returnColumnSizes)
{
    *returnSize = 0;
    if (intervals == NULL) {
        
        return intervals;
    }

    qsort(intervals, intervalsSize, sizeof(intervals[0]), Cmp);

    int **res = (int **)malloc(sizeof(int *) * intervalsSize);
    *returnColumnSizes = (int *)malloc(intervalsSize * sizeof(int));

    for (int i = 0; i < intervalsSize; i++) {
        if (i == intervalsSize - 1) {
            res[*returnSize] = (int *)malloc(sizeof(int) * 2);
            (*returnColumnSizes)[*returnSize] = 2;
            memcpy(res[*returnSize], intervals[i], sizeof(intervals[i]));
            (*returnSize)++;
            break;
        }
        if (intervals[i][1] >= intervals[i + 1][0]) {
            intervals[i + 1][0] = intervals[i][0];
            intervals[i + 1][1] = Max(intervals[i][1], intervals[i + 1][1]);
        } else {
            res[*returnSize] = (int *)malloc(sizeof(int) * 2);
            (*returnColumnSizes)[*returnSize] = 2;
            memcpy(res[*returnSize], intervals[i], sizeof(intervals[i]));
            (*returnSize)++;
        }
    }
    return res;
}

