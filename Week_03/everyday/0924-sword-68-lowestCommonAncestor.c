/*
 * =====================================================================================
 *
 *       Filename:  0924-sword-68-lowestCommonAncestor.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/09/24 21时59分57秒
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


struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q){
    // 题目解析：
    // p/q分别在左右子树，则root为祖先
    // p/q均在左子树，则查找左子树
    // p/q均在右子树，则查找右子树
    if (root == NULL) {
        return root;
    }

    if (p == root || q == root) {
        return root;
    }

    struct TreeNode* left = lowestCommonAncestor(root->left, p, q);
    struct TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if (left == NULL) {
        return right;
    } else if (right == NULL) {
        return left;
    } else {
        return root;
    }
}
