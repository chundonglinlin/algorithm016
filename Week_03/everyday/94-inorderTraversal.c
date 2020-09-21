/*
 * =====================================================================================
 *
 *       Filename:  94-inorderTraversal.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/09/21 13时59分55秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
void visit(struct TreeNode* root, int *res, int *len)
{
    if (root == NULL) {
        return;
    }

    // 存储左子树
    visit(root->left, res, len);
    // 存储根节点
    res[(*len)++] = root->val;
    // 存储右子树
    visit(root->right, res, len);
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize){
#define MAX_SIZE 1024
    int *result = (int*)malloc(sizeof(int) * MAX_SIZE);
    *returnSize = 0;

    visit(root, result, returnSize);
    
    return result;
}
