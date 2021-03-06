/*
 * =====================================================================================
 *
 *       Filename:  03-77-combine.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/09/26 22时57分16秒
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
int* temp;
int tempSize;

int** ans;
int ansSize;

void dfs(int cur, int n, int k) {
    // 剪枝：temp 长度加上区间 [cur, n] 的长度小于 k，不可能构造出长度为 k 的 temp
    if (tempSize + (n - cur + 1) < k) {
        return;
    }
    // 记录合法的答案
    if (tempSize == k) {
        int* tmp = malloc(sizeof(int) * k);
        for (int i = 0; i < k; i++) {
            tmp[i] = temp[i];
        }
        ans[ansSize++] = tmp;
        return;
    }
    // 考虑选择当前位置
    temp[tempSize++] = cur;
    dfs(cur + 1, n, k);
    tempSize--;
    // 考虑不选择当前位置
    dfs(cur + 1, n, k);
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes) {
    temp = malloc(sizeof(int) * k);
    ans = malloc(sizeof(int*) * 10001);
    tempSize = ansSize = 0;
    dfs(1, n, k);
    *returnSize = ansSize;
    *returnColumnSizes = malloc(sizeof(int) * ansSize);
    for (int i = 0; i < ansSize; i++) {
        (*returnColumnSizes)[i] = k;
    }
    return ans;
}
