/*
 * =====================================================================================
 *
 *       Filename:  20201109-83-deleteDuplicates.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/11/09 23时57分33秒
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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode* temp = head;
    while (temp && temp->next) {
        struct ListNode* next = temp->next;
        if (temp->val == next->val) {
            temp->next = next->next;
            free(next);
        } else {
            temp = temp->next;
        }
    }

    return head;
}
