/*
 * =====================================================================================
 *
 *       Filename:  1005-127-ladderLength.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/10/05 21时08分51秒
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
        if (word[i] != match[i]) {
            if (ret == 1) {
                // 至少出现两次不相同
                return 0;
            } else {
                ret = 1;
            }
        }
    }

    // 包含某个字母不同相同的情况（ret=1）
    return ret;
}

int ladderLength(char *beginWord, char *endWord, char **wordList, int wordListSize)
{
#define MAX_SIZE 10000
    char *queue[MAX_SIZE], mark[MAX_SIZE];
    int head = 0, tail = 0, count = 1, queueSize;

    for (int i = 0; i < wordListSize; i++) {
        // 查找结束字符串
        if (strcmp(wordList[i], endWord) == 0) {
            break;
        }

        if (i == wordListSize - 1) {
            // 没找到结束字符串
            return 0;
        }
    }

    // 队列存储head
    queue[tail++] = beginWord;

    while (head != tail) {
        queueSize = (tail - head + MAX_SIZE) % MAX_SIZE;

        for (int i = 0; i < queueSize; i++) {
            char *temp = queue[head];
            if (strcmp(temp, endWord) == 0) {
                return count;
            }
            // 队列下标后移
            head = (head + 1) % MAX_SIZE;

            for (int j = 0; j < wordListSize; j++) {
                if (mark[j] == 0 && canChange(wordList[j], temp, wordLen) == 1) {
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
