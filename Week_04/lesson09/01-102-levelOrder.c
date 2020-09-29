/*
 * =====================================================================================
 *
 *       Filename:  01-102-levelOrder.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/09/29 11时30分36秒
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
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
#define MAX_SIZE 10240
    // out params
    int **result = (int**)calloc(MAX_SIZE , sizeof(int*));
    *returnColumnSizes = (int*)calloc(MAX_SIZE, sizeof(int));
    *returnSize = 0;

    // 判断异常输入，进入while循环之前初始化
    if (root == NULL) {
        // 必须初始化returnSize, returnColumnSizes
        return NULL;
    }

    // 建立指向节点的指针队列和两个索引
    struct TreeNode *queue[MAX_SIZE];//数组模拟队列所有node
    int outIndex = 0;//每个节点的索引
    int inIndex = 0;//队列下标

    queue[inIndex++] = root;
    int levelcount = inIndex - outIndex;//第几层
    int count = 0;

    // BFS
    while (levelcount > 0){
        count++;
        result[*returnSize] = (int*)calloc(levelcount,sizeof(int));
        (*returnColumnSizes)[*returnSize] = levelcount;

        // 每一层的动作
        for (int i = 0; i < levelcount; i++){
            if (queue[outIndex]->left != NULL){
                queue[inIndex++] = queue[outIndex]->left;
            }
            if (queue[outIndex]->right != NULL){
                queue[inIndex++] = queue[outIndex]->right;
            }
            result[*returnSize][i] = queue[outIndex++]->val;
        }

        // 进入下一层之前的动作
        (*returnSize)++;
        levelcount = inIndex - outIndex;
    }
    return result;
}
