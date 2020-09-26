/*
 * =====================================================================================
 *
 *       Filename:  02-105-buildTree.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/09/26 20时47分54秒
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


struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    if (preorderSize <= 0 || inorderSize <= 0) {
        return NULL;
    }

    struct TreeNode *p = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    p->val = *preorder;
    p->left = NULL;
    p->right = NULL;

    int pos = 0;
    for (pos = 0; pos < inorderSize; pos++) {
        if (inorder[pos] == *preorder) {
            break;
        }
    }

    // left
    p->left = buildTree(preorder + 1, pos, inorder, pos);
    // right
    p->right = buildTree(preorder + pos + 1, inorderSize - pos - 1, inorder + pos + 1, inorderSize - pos - 1);
    return p;
}
