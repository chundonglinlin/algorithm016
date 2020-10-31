/*
 * =====================================================================================
 *
 *       Filename:  20201031-swapPairs.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/10/31 16时33分53秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
struct ListNode* swapPairs(struct ListNode* head){
    // 增加第一个节点
    struct ListNode* first = malloc(sizeof(struct ListNode));
    first->next = head;
    struct ListNode* result = first;
    while (head && head->next != NULL) {
        // second
        first->next = head->next;
        // third
        struct ListNode* third = head->next->next;

        //reverse
        first->next->next = head;
        head->next = third;

        /*
            | first | head   | 
            | first | second | third |
        */
        //reset
        first = head;
        head = head->next;
    }

    return result->next;
}
