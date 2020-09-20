/*
 * =====================================================================================
 *
 *       Filename:  49-groupAnagrams.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/09/19 21时08分13秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>

/*解题思路：
    1.先排序字符串，以判断是否是异位词；
    2.在hashtable中存放异位词的从小到大的字符串;
    3.在hashtable中查找，以此判断是否需要创建result的新行；
    4.存在hashtable中，则通过Str->id插入字符串即可；
    5.不存在hashtable中，则在result中创建新行；

    #include “uthash.h”
    HASH_FIND_STR()
    HASH_ADD_STR()
    HASH_CLEAR(hh, users); //删除所有项目，但不释放它们或进行每个元素的清理
    参考：https://blog.csdn.net/qq_16933601/article/details/107188223
*/
#define STR_MAX_LEN 1020
static int compare(const void* x, const void* y)
{
    return *(char*)x - *(char*)y;
}

struct Ut_hash {
    char key[STR_MAX_LEN];
    int id;
    UT_hash_handle hh;
};

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes)
{
    if (strs == NULL || strsSize < 0) {
        return NULL;
    }
    struct Ut_hash *keyStrsHash = NULL, *strTemp = NULL;
    char ***result = (char ***)malloc(sizeof(char **) * strsSize);
    char **sortedStrs = (char **)malloc(sizeof(char *) * strsSize);
    *returnSize = 0;
    *returnColumnSizes = (int *)malloc(sizeof(int) * strsSize);

    for (int i = 0; i < strsSize; i++) {
        int len = strlen(strs[i]);
        sortedStrs[i] = (char*)malloc(len + 1);
        (void)strcpy(sortedStrs[i], strs[i]);
        qsort(sortedStrs[i], len, sizeof(char), compare);
        //若无，则返回NULL
        HASH_FIND_STR(keyStrsHash, sortedStrs[i], strTemp);
        if (!strTemp) {
            //not exist
            // init strTemp and hash_add
            strTemp = (struct Ut_hash*)malloc(sizeof(struct Ut_hash));
            strcpy(strTemp->key, sortedStrs[i]);
            strTemp->id = *returnSize;
            HASH_ADD_STR(keyStrsHash, key, strTemp);

            //copy
            result[*returnSize] = (char**)malloc(sizeof(char*) * strsSize);
            result[*returnSize][0] = (char*)malloc(len + 1);
            strcpy(result[*returnSize][0], strs[i]);

            (*returnColumnSizes)[*returnSize] = 1;
            (*returnSize)++;
        } else {
            //exist
            int row = strTemp->id;
            int col = (*returnColumnSizes)[row];
            result[row][col] = (char*)malloc(len + 1);
            strcpy(result[row][col], strs[i]);
            ((*returnColumnSizes)[row])++;
        }
    }

    HASH_CLEAR(hh, keyStrsHash);
    for (int i = 0; i < strsSize; i++) {
            free(sortedStrs[i]);
    }
    return result;
}
