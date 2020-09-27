/*
 * =====================================================================================
 *
 *       Filename:  03-226-invertTree.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/09/27 22时50分14秒
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

struct TreeNode* invertTree(struct TreeNode* root){
    if (root == NULL) {
        return NULL;
    }

    struct TreeNode* left = invertTree(root->left);
    struct TreeNode* right = invertTree(root->right);

    root->left = right;
    root->right = left;

    return root;
}
