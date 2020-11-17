/*
 * =====================================================================================
 *
 *       Filename:  20201116-406-reconstructQueue.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/11/16 23时36分33秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
int cmp(const void* _a, const void* _b) {
    int *a = *(int**)_a, *b = *(int**)_b;
    return a[0] == b[0] ? a[1] - b[1] : b[0] - a[0];
}

int** reconstructQueue(int** people, int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes) {
    // 快排
    qsort(people, peopleSize, sizeof(int*), cmp);

    int** ans = malloc(sizeof(int*) * peopleSize);
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int) * peopleSize);
    for (int i = 0; i < peopleSize; i++) {
        (*returnColumnSizes)[i] = 2;
    }

    for (int i = 0; i < peopleSize; ++i) {
        int* person = people[i];
        (*returnSize)++;
        for (int j = (*returnSize) - 1; j > person[1]; j--) {
            ans[j] = ans[j - 1];
        }
        int* tmp = malloc(sizeof(int) * 2);
        tmp[0] = person[0], tmp[1] = person[1];
        ans[person[1]] = tmp;
    }

    return ans;
}
