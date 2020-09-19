/*
 * =====================================================================================
 *
 *       Filename:  589-preorder.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/09/19 20时49分31秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
void visit(struct Node* root, int *res, int *len)
{
    if (root == NULL) {
        return;
    }

    // store
    res[(*len)++] = root->val;

    for (int i = 0; i < root->numChildren; i++) {
        visit(root->children[i], res, len);
    }
}

int* preorder(struct Node* root, int* returnSize) {
    // 递归
#define MAX_SIZE 10240
    int *result = malloc(sizeof(int) * MAX_SIZE);
    *returnSize = 0;

    visit(root, result, returnSize);

    return result;
}
