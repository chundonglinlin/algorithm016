/*
 * =====================================================================================
 *
 *       Filename:  0928-46-permute.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/09/28 20时07分31秒
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


void dfs(int *nums, int numsSize, int depth, int *cur, bool *used, int *count, int **res){
    // deeply need copy array.
    if (depth == numsSize) {
        res[*count] = (int*)malloc(sizeof(int) * numsSize);
        memcpy(res[(*count)++], cur, sizeof(int) * numsSize);
        return;
    }

    for(int i = 0; i < numsSize; ++i) {
        // array item is used
        if(used[i] == true) {
            continue;
        }
        
        cur[depth] = nums[i];
        used[i] = true;
        //++depth;

        dfs(nums, numsSize, depth + 1, cur, used, count, res);
        
        //--depth;
        used[i] = false;
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    // calc space (n!)
    int size = 0, count = 1;
    for(int i = 1; i <= numsSize; ++i) {
        count *= i;
    }
    // init
    *returnSize = count;
    *returnColumnSizes = (int*)malloc(sizeof(int) * count);
    for(int i = 0; i < count; ++i) {
        (*returnColumnSizes)[i] = numsSize;
    }

    int **result = (int**)malloc(sizeof(int*) * count);
    int *cur = (int*)malloc(sizeof(int) * numsSize);//each array
    bool *used = (bool*)calloc(numsSize, sizeof(bool));//each array item flag

    dfs(nums, numsSize, 0, cur, used, &size, result);

    return result;
}

