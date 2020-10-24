/*
 * =====================================================================================
 *
 *       Filename:  20201023-127-ladderLength.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/10/24 20时54分31秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
int canChange(char *word, char *match, int len)
{
    int ret = 0;
    for (int i = 0; i < len; i++) {
        // 出现两个字母不同时，返回0
        if (word[i] != match[i]) {
            if (ret == 1) {
                // 第二次不相同时，直接返回0
                return 0;
            } else {
                // 出现一次不相同，标识ret=1
                ret = 1;
            }
        }
    }

    return ret;
}

int ladderLength(char *beginWord, char *endWord, char **wordList, int wordListSize)
{
#define MAX_SIZE 10240
    char *queue[MAX_SIZE] = {0}, mark[MAX_SIZE] = {0}, *wordTemp;
    int head = 0, tail = 0;

    int count = 1, queSize = 0;
    int wordLen = strlen(wordList[0]);

    /*  判断结束符在不在list 中 */
    for (int i = 0; i < wordListSize; i++) {
        if(strcmp(endWord, wordList[i]) == 0) {
            break;
        }

        if (i == wordListSize - 1) {
            // 无匹配
            return 0;
        }
    }

    /* beginWord 入队 */
    queue[tail++]  = beginWord;

    while (head != tail) {
        queSize = (tail - head + MAX_SIZE) % MAX_SIZE;
        for (int i = 0; i < queSize; i++) {
            /* 出队 */
            wordTemp = queue[head];
            if (strcmp(wordTemp, endWord) == 0) {
                return count;
            }
            head = (head + 1) % MAX_SIZE;

            for (int j = 0; j < wordListSize; j++) {
                if (mark[j] == 0 && canChange(wordTemp, wordList[j], wordLen) == 1) {
                    mark[j] = 1;
                    if ((tail + 1) % MAX_SIZE != head) {
                        queue[tail] = wordList[j];
                        tail = (tail + 1) % MAX_SIZE;
                    }
                }
            }
        }
        count++;
    }
    return 0;
}

