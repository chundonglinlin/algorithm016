/*
 * =====================================================================================
 *
 *       Filename:  offer-levelOrder.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/09/20 15时51分43秒
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
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAX_NODES 5000
#define MAX_DEEPS 1000

typedef struct Node *Elemtype;
typedef struct {
    Elemtype *data;
    int capacity;
    int front;
    int rear;
    int size;
}Queue;

Queue q;

void init(Queue *q, int capacity) {
    q->data = (Elemtype *)malloc(sizeof(Elemtype) * capacity);
    q->capacity = capacity;
    q->front    = 0;
    q->rear     = 0;
    q->size     = 0;
}

void uninit(Queue *q) {
    free(q->data);
    q->capacity = 0;
    q->front    = 0;
    q->rear     = 0;
    q->size     = 0;    
}

void enQueue(Queue *q, const Elemtype e) {
    q->data[q->rear] = e;
    q->rear = (q->rear + 1) % q->capacity;
    q->size++;    
}

void deQueue(Queue *q, Elemtype *e) {
    *e = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
}

int getQueueSize(Queue *q) {
    return q->size;
}

int empty(Queue *q) {
    int ret = q->size == 0 ? 1 : 0;    
    return ret;
}

void helper(struct Node *root, int *returnSize, int **returnColumnSizes, int **res) {
    enQueue(&q, root);      

    while (!empty(&q)) {
        int nums = getQueueSize(&q);               
       
        (*returnColumnSizes)[*returnSize] = nums;        
        res[*returnSize] = (int *)malloc(sizeof(int) * nums);
        
        for (int i = 0; i < nums; i++) {
            struct Node *node;
            deQueue(&q, &node);
            res[*returnSize][i] = node->val;            
            
            for (int j = 0; j < node->numChildren; j++) {
                enQueue(&q, node->children[j]);
            }
        }   
        (*returnSize)++; 
    }
}

int** levelOrder(struct Node* root, int* returnSize, int** returnColumnSizes) {    
    *returnSize = 0;
    if (root == NULL) {        
        *returnColumnSizes = NULL;
        return NULL;
    }    
    
    init(&q, MAX_NODES);

    int **res = (int **)malloc(sizeof(int *) * MAX_DEEPS);
    *returnColumnSizes = (int *)malloc(sizeof(int *) * MAX_DEEPS);    

    helper(root, returnSize, returnColumnSizes, res);
    return res;
}
