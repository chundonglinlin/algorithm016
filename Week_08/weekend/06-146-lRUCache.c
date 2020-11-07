/*
 * =====================================================================================
 *
 *       Filename:  06-146-lRUCache.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/11/07 18时26分43秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
//方法一：Hash表 + 双向链表
//1,使用Hash表实现 key值的直接存取
//2,使用双向链表维护key值的操作顺序

#define     HASH_SIZE       1999

//////////////////////////////////////////////////////////////////////
//链表元素
struct Link_Node{
    int                     key;                //key值
    struct Link_Node*       pNodePre;           //前指针
    struct Link_Node*       pNodeNext;          //后指针
};

//链表实现最久未使用的key的保存
struct Link_List{
    int                     iListSize;          //链表大小
    int                     iNodeNum;           //存入元素个数
    struct Link_Node*       pLinkHead;          //链表头指针
    struct Link_Node*       pLinkTail;          //链表尾指针
};
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//元素定义
 struct HashListNode{
    int                     key;                //key值
    int                     val;                //value值
    struct Link_Node*       pLinkNode;          //key值在链表中的位置
 };

//二维哈希链表元素定义
struct Hash_Node {
    struct HashListNode*    pNode;              //当前值
    struct Hash_Node*       pNext;              //下一个指针
};

//哈希表定义
struct Hash_Table {
    int                     iNodeSize;          //存入元素个数
    struct Hash_Node**      pHashHead;          //Hash表指针
};
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//LRU结构体
typedef struct {
    int                     capacity;           //LRU容量大小
    struct Link_List        LinkList;           //存储key链表
    struct Hash_Table       HashTable;          //存储key的Hash表
} LRUCache;
//////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////
//函数一：哈希表初始化
bool hashTableInit(struct Hash_Table* pHashTable, int capacity) {
    if(NULL == pHashTable) return false;

    pHashTable->iNodeSize = 0;
    pHashTable->pHashHead = (struct Hash_Node**)malloc(sizeof(struct Hash_Node*) * HASH_SIZE);
    if(NULL == pHashTable->pHashHead) return false;
    memset(pHashTable->pHashHead, 0x00, sizeof(struct Hash_Node*) * HASH_SIZE);
    return true;
}

//函数二：哈希表元素插入
bool hashTableInsert(struct Hash_Table* pHashTable, struct HashListNode* pNode){
    unsigned int     iKey        = 0;
    struct Hash_Node*   pTmpNode    = NULL;

    printf("1:hashTableInsert iNodeSize=%d\n", pHashTable->iNodeSize);
    
    iKey = pNode->key % HASH_SIZE;
    if(NULL == pHashTable->pHashHead[iKey])
    {
        pHashTable->pHashHead[iKey] = (struct Hash_Node*)malloc(sizeof(struct Hash_Node));
        if(NULL == pHashTable->pHashHead[iKey]) return false;

        pHashTable->pHashHead[iKey]->pNode = pNode;
        pHashTable->pHashHead[iKey]->pNext = NULL;
    }
    else
    {
        pTmpNode = pHashTable->pHashHead[iKey];
        while((NULL != pTmpNode) && (NULL != pTmpNode->pNext))
        {            
            pTmpNode = pTmpNode->pNext;
        }

        pTmpNode->pNext = (struct Hash_Node*)malloc(sizeof(struct Hash_Node));
        if(NULL == pTmpNode->pNext) return false;

        pTmpNode = pTmpNode->pNext;
        pTmpNode->pNode = pNode;
        pTmpNode->pNext = NULL;
    }
    pHashTable->iNodeSize += 1;
    return true;
}

//函数三：取出哈希表元素
struct Hash_Node* getHashNode(struct Hash_Table* pHashTable, int key){
    unsigned int     iKey        = 0;
    struct Hash_Node*   pTmpNode    = NULL;
    
    iKey = key % HASH_SIZE;
    pTmpNode = pHashTable->pHashHead[iKey];

    while(NULL != pTmpNode)
    {
        if((NULL != pTmpNode->pNode) && (key == pTmpNode->pNode->key))
        {
            return pTmpNode;
        }
        else
        {
            pTmpNode = pTmpNode->pNext;
        }
    }

    return NULL;
}

//函数四：hash表元素删除
bool hashTableDel(struct Hash_Table* pHashTable, int key){
    unsigned int     iKey        = 0;
    long int         value       = 0;
    struct Hash_Node*   pTmpNode    = NULL;
    struct Hash_Node*   pNextNode   = NULL;

    if(NULL == pHashTable) return false;

    iKey = key % HASH_SIZE;
    pTmpNode = pHashTable->pHashHead[iKey];

    while(NULL != pTmpNode)
    {
        if((NULL != pTmpNode->pNode) && (key == pTmpNode->pNode->key))
        {
            pNextNode = pTmpNode->pNext;
            free(pTmpNode->pNode);
            pTmpNode->pNode = NULL;
            pTmpNode->pNext = pNextNode;
            pHashTable->iNodeSize -= 1;
            break;
        }
        else
        {
            pTmpNode = pTmpNode->pNext;
        }
    }

    return true;
}

//函数五：Hash表的释放
void freeHashTable(struct Hash_Table* pHashTable){
    int     i       = 0;
    struct Hash_Node*   pTmpNode    = NULL;
    struct Hash_Node*   pNextNode    = NULL;

    if(NULL == pHashTable) return;

    for(i = 0; i < HASH_SIZE; i++)
    {
        pTmpNode = pHashTable->pHashHead[i];
        while(NULL != pTmpNode)
        {
            pNextNode = pTmpNode->pNext;
            if(NULL != pTmpNode->pNode)
            {
                free(pTmpNode->pNode);
                pTmpNode->pNode = NULL;
            }
            free(pTmpNode);
            pTmpNode = pNextNode;
        }
        pHashTable->pHashHead[i] = NULL;
    }
    return;
}
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//函数一：链表的初始化
bool LinkListInit(struct Link_List* pLinkList, int capacity){
    if(NULL == pLinkList) return false;

    pLinkList->iListSize = capacity;
    pLinkList->iNodeNum = 0;
    pLinkList->pLinkHead = NULL;
    pLinkList->pLinkTail = NULL;
    return true;
}

//函数二：更新key链表，将当前位置移植链表尾
bool UpdateLinkOfKey(struct Link_List* pLinkList, struct Link_Node* pLinkNode){

    if((NULL == pLinkList) || (NULL == pLinkNode)) return false;

    if(1 == pLinkList->iNodeNum) return true;
    if(pLinkNode == pLinkList->pLinkTail) return true;

    if(pLinkNode == pLinkList->pLinkHead)
    {
        pLinkList->pLinkHead = pLinkNode->pNodeNext;
        pLinkList->pLinkHead->pNodePre = NULL;

        pLinkNode->pNodePre = pLinkList->pLinkTail;
        pLinkList->pLinkTail->pNodeNext = pLinkNode;
        pLinkList->pLinkTail = pLinkNode;
        pLinkList->pLinkTail->pNodeNext = NULL;
    }
    else
    {
        pLinkNode->pNodePre->pNodeNext = pLinkNode->pNodeNext;
        pLinkNode->pNodeNext->pNodePre = pLinkNode->pNodePre;

        pLinkList->pLinkTail->pNodeNext = pLinkNode;
        pLinkNode->pNodePre = pLinkList->pLinkTail;
        pLinkList->pLinkTail = pLinkNode;
        pLinkNode->pNodeNext = NULL;
    }
    return true;
}

//函数三：向 key 链表中增加一个元素
struct Link_Node* LinkLiskInsert(struct Link_List* pLinkList, int key){
    struct Link_Node*   pTmpNode = NULL;

    if(NULL == pLinkList) return NULL;
    if(pLinkList->iNodeNum >= pLinkList->iListSize) return NULL;

    pTmpNode = (struct Link_Node*)malloc(sizeof(struct Link_Node));
    if(NULL == pTmpNode) return NULL;

    pTmpNode->key = key;
    pTmpNode->pNodePre = NULL;
    pTmpNode->pNodeNext = NULL;

    if((0 == pLinkList->iNodeNum) || (NULL == pLinkList->pLinkHead) || (NULL == pLinkList->pLinkTail))
    {
        pLinkList->pLinkHead = pTmpNode;
        pLinkList->pLinkTail = pTmpNode;
    }
    else
    {
        //将新增元素加在链表尾部
        pTmpNode->pNodePre = pLinkList->pLinkTail;
        pLinkList->pLinkTail->pNodeNext = pTmpNode;
        pLinkList->pLinkTail = pTmpNode;
    }
    
    pLinkList->iNodeNum += 1;
    return pTmpNode;
}

//函数四：删除key链表元素
bool DelLinkOfKey(struct Link_List* pLinkList, struct Link_Node* pLinkNode){

    if((NULL == pLinkList) || (NULL == pLinkNode)) return false;
    if(pLinkList->iNodeNum == 0) return false;

    if(pLinkList->iNodeNum == 1)
    {
        pLinkList->iNodeNum = 0;
        free(pLinkList->pLinkHead);
        pLinkList->pLinkHead = NULL;
        pLinkList->pLinkTail = NULL;
        pLinkNode = NULL;
    }
    else
    {
        if(pLinkList->pLinkTail == pLinkNode)
        {
            pLinkList->pLinkTail = pLinkNode->pNodePre;
            pLinkList->pLinkTail->pNodeNext = NULL;
        }
        else if(pLinkList->pLinkHead == pLinkNode)
        {
            pLinkList->pLinkHead = pLinkNode->pNodeNext;
            pLinkList->pLinkHead->pNodePre = NULL;
        }
        else
        {
            pLinkNode->pNodePre->pNodeNext = pLinkNode->pNodeNext;
            pLinkNode->pNodeNext->pNodePre = pLinkNode->pNodePre;
        }

        free(pLinkNode);
        pLinkNode = NULL;
        pLinkList->iNodeNum -= 1;
    }
    return true;
}

//函数五：key链表的释放
void freeLinkOfKey(struct Link_List* pLinkList){

    struct Link_Node*   pTmpNode    = NULL;
    struct Link_Node*   pNextNode   = NULL;

    if(NULL == pLinkList) return;

    pTmpNode = pLinkList->pLinkHead;
    while(NULL != pTmpNode)
    {
        pNextNode = pTmpNode->pNodeNext;
        free(pTmpNode);
        pTmpNode = pNextNode;
    }
    return;
}
//////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////
//函数一：LRU结构的初始化
bool LRUCacheInit(LRUCache* pLRU, int capacity){
    if(NULL == pLRU) return false;

    pLRU->capacity = capacity;
    if(false == LinkListInit(&(pLRU->LinkList), capacity)) return false;
    if(false == hashTableInit(&(pLRU->HashTable), capacity)) return false;
    return true;
}

//函数二：新增关键字
bool lRUCacheAdd(LRUCache* obj, int key, int value) {
    struct HashListNode*    pNode       = NULL;

    pNode = (struct HashListNode*)malloc(sizeof(struct HashListNode));
    memset(pNode, 0x00, sizeof(struct HashListNode));

    pNode->key = key;
    pNode->val = value;

    //在 key 链表中增加一个元素
    pNode->pLinkNode = LinkLiskInsert(&obj->LinkList, key);
    if(NULL == pNode->pLinkNode) return false;

    //在 key Hash表中增加一个元素
    return hashTableInsert(&obj->HashTable, pNode);
}
//////////////////////////////////////////////////////////////////////


//主函数一：LRU的创建
LRUCache* lRUCacheCreate(int capacity) {
    LRUCache*   pLRU    = NULL;

    pLRU = (LRUCache*)malloc(sizeof(LRUCache));
    if(NULL == pLRU) return NULL;

    if(false == LRUCacheInit(pLRU, capacity)) return NULL;
    return pLRU;
}

//主函数二：获取函数
int lRUCacheGet(LRUCache* obj, int key) {
    int     iRet    = -1;
    struct Hash_Node*   pHashNode   = NULL;

    if((NULL == obj) || (key < 0)) return iRet;

    pHashNode = getHashNode(&obj->HashTable, key);
    if((NULL == pHashNode) || (key != pHashNode->pNode->key)) return iRet;

    //更新key值在 链表 中的位置
    if(false == UpdateLinkOfKey(&obj->LinkList, pHashNode->pNode->pLinkNode)) return iRet;

    iRet = pHashNode->pNode->val;
    return iRet;
}

//主函数三：存入函数
void lRUCachePut(LRUCache* obj, int key, int value) {
    struct Hash_Node*   pHashNode   = NULL;

    if((NULL == obj) || (key < 0)) return;

    pHashNode = getHashNode(&obj->HashTable, key);
    if(NULL != pHashNode)
    {
        //关键字已经存在，变更数据值
        pHashNode->pNode->val = value;

        //更新key值在 链表 中的位置
        UpdateLinkOfKey(&obj->LinkList, pHashNode->pNode->pLinkNode);
    }
    else
    {
        if(obj->HashTable.iNodeSize >= obj->capacity)
        {
            //缓存容量达到了上限
            //hash表删除元素
            hashTableDel(&obj->HashTable, obj->LinkList.pLinkHead->key);

            //key链表删除元素
            DelLinkOfKey(&obj->LinkList, obj->LinkList.pLinkHead);
        }

        //新增关键字
        lRUCacheAdd(obj, key, value);
    }
    return;
}

//主函数四：释放函数
void lRUCacheFree(LRUCache* obj) {
    if(NULL == obj) return;

    freeLinkOfKey(&obj->LinkList);
    freeHashTable(&obj->HashTable);
    return;
}
//////////////////////////////////////////////////////////////////////

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/
