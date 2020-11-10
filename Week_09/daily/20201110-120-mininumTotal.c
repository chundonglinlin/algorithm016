/*
 * =====================================================================================
 *
 *       Filename:  20201110-120-mininumTotal.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/11/11 01时31分50秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
    // 动态规划
    int f[2][triangleSize];
    memset(f, 0, sizeof(f));
    f[0][0] = triangle[0][0];
    for (int i = 1; i < triangleSize; ++i) {
        int curr = i % 2;
        int prev = 1 - curr;
        f[curr][0] = f[prev][0] + triangle[i][0];
        for (int j = 1; j < i; ++j) {
            f[curr][j] = fmin(f[prev][j - 1], f[prev][j]) + triangle[i][j];
        }
        f[curr][i] = f[prev][i - 1] + triangle[i][i];
    }
    int ret = f[(triangleSize - 1) % 2][0];
    for (int i = 1; i < triangleSize; i++) {
        ret = fmin(ret, f[(triangleSize - 1) % 2][i]);
    }
    return ret;
}
