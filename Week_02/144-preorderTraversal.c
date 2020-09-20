/*
 * =====================================================================================
 *
 *       Filename:  144-preorderTraversal.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/09/20 13时07分14秒
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
 * Note: The returned array must be malloced, assume caller calls free().
 */
 void visit(struct TreeNode* root, int *res, int *len)
 {
     if (root == NULL) {
         return;
     }

     //存储根点
     res[(*len)++] = root->val;

     //左子树
     visit(root->left, res, len);

     //右子树
     visit(root->right, res, len);
 }

int* preorderTraversal(struct TreeNode* root, int* returnSize){
#define MAX_SIZE 1024
    int *result = (int*)malloc(sizeof(int*) * MAX_SIZE);
    *returnSize = 0;

    //递归
    visit(root, result, returnSize);

    return result;
}
