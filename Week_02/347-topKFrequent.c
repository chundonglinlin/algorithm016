/*
 * =====================================================================================
 *
 *       Filename:  347-topKFrequent.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/09/20 14时54分14秒
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
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define Hash_SIZE 20001
#define OFFSET 10000//对下标为负数进行偏移使数组下标>=0

typedef struct 
{
    int val;
    int cnt;
}HashTable;

HashTable hash[Hash_SIZE];
//比较函数，对cnt出现次数进行排序
int comp(const void *a, const void *b) {
    //return (((HashTable *)a)->cnt - ((HashTable *)b)->cnt);//递增
    return (((HashTable *)b)->cnt - ((HashTable *)a)->cnt);//递减
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize){
    memset(hash,0,sizeof(hash));//初始化sizeof(hash)个字节
    int i = 0,j = 0;
    for(i = 0;i < numsSize; i++) {//将nums数组的值和出现的次数放入hash表中
        int pos = (nums[i]+OFFSET)%Hash_SIZE;
        hash[pos].cnt++;
        hash[pos].val=nums[i];
    }
    
    //对原hash表进行优化
    for(i = 0; i < Hash_SIZE; i++) {
        if(hash[i].cnt != 0) {
            hash[j].cnt=hash[i].cnt;
            hash[j].val=hash[i].val;
            j++;
        }
    }

    //对hash表中的cnt进行快速排序
    //出现次数少的在前面，次数多的在后面
    qsort(hash, j, sizeof(HashTable), comp);//注意sizeof里面是hashtable

    *returnSize = 0;
    /*for(i = j - 1; i >= j - k; i--) {//输出前k个高频元素
        nums[(*returnSize)++] = hash[i].val;//倒序输出
    }*/
    for (i = 0; i < k; i++) {
        nums[i] = hash[i].val;
    }
    *returnSize = k;

    return nums;
}

