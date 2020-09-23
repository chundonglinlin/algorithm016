/*
 * =====================================================================================
 *
 *       Filename:  0923-sword-06-reversePrint.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/09/23 22时51分00秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
int* reversePrint(struct ListNode* head, int* returnSize){
    // 倒序
    int *result = NULL;
    *returnSize = 0;
    int size = 0;
    struct ListNode* tmp = head;
    while (tmp) {
        tmp = tmp->next;
        size++;
    }
    
    if (size == 0) {
        return result;
    }

    result = (int*)malloc(sizeof(int) * size);
    *returnSize = size;
    while (head) {
        result[--size] = head->val;
        head = head->next;
    }

    return result;
}
