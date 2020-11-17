/*
 * =====================================================================================
 *
 *       Filename:  20201111-127-ladderLength.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/11/12 21时31分40秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
struct Trie {
    int ch[27];
    int val;
} trie[50001];

int size, nodeNum;

void insert(char* s, int num) {
    int sSize = strlen(s), add = 0;
    for (int i = 0; i < sSize; ++i) {
        int x = s[i] - '`';
        if (trie[add].ch[x] == 0) {
            trie[add].ch[x] = ++size;
            memset(trie[size].ch, 0, sizeof(trie[size].ch));
            trie[size].val = -1;
        }
        add = trie[add].ch[x];
    }
    trie[add].val = num;
}

int find(char* s) {
    int sSize = strlen(s), add = 0;
    for (int i = 0; i < sSize; ++i) {
        int x = s[i] - '`';
        if (trie[add].ch[x] == 0) {
            return -1;
        }
        add = trie[add].ch[x];
    }
    return trie[add].val;
}

int addWord(char* word) {
    if (find(word) == -1) {
        insert(word, nodeNum++);
    }
    return find(word);
}

int edge[30001][26];

int edgeSize[30001];

void addEdge(char* word) {
    int wordSize = strlen(word), id1 = addWord(word);
    for (int i = 0; i < wordSize; ++i) {
        char tmp = word[i];
        word[i] = '`';
        int id2 = addWord(word);
        edge[id1][edgeSize[id1]++] = id2;
        edge[id2][edgeSize[id2]++] = id1;
        word[i] = tmp;
    }
}

int ladderLength(char* beginWord, char* endWord, char** wordList, int wordListSize) {
    size = nodeNum = 0;
    memset(trie[size].ch, 0, sizeof(trie[size].ch));
    trie[size].val = -1;
    memset(edgeSize, 0, sizeof(edgeSize));
    for (int i = 0; i < wordListSize; ++i) {
        addEdge(wordList[i]);
    }
    addEdge(beginWord);
    int beginId = find(beginWord), endId = find(endWord);
    if (endId == -1) {
        return 0;
    }

    int disBegin[nodeNum];
    memset(disBegin, -1, sizeof(disBegin));
    disBegin[beginId] = 0;
    int queBegin[nodeNum];
    int leftBegin = 0, rightBegin = 0;
    queBegin[rightBegin++] = beginId;

    int disEnd[nodeNum];
    memset(disEnd, -1, sizeof(disEnd));
    disEnd[endId] = 0;
    int queEnd[nodeNum];
    int leftEnd = 0, rightEnd = 0;
    queEnd[rightEnd++] = endId;

    while (leftBegin < rightBegin && leftEnd < rightEnd) {
        int queBeginSize = rightBegin - leftBegin;
        for (int i = 0; i < queBeginSize; ++i) {
            int nodeBegin = queBegin[leftBegin++];
            if (disEnd[nodeBegin] != -1) {
                return (disBegin[nodeBegin] + disEnd[nodeBegin]) / 2 + 1;
            }
            for (int j = 0; j < edgeSize[nodeBegin]; ++j) {
                if (disBegin[edge[nodeBegin][j]] == -1) {
                    disBegin[edge[nodeBegin][j]] = disBegin[nodeBegin] + 1;
                    queBegin[rightBegin++] = edge[nodeBegin][j];
                }
            }
        }
        int queEndSize = rightEnd - leftEnd;
        for (int i = 0; i < queEndSize; ++i) {
            int nodeEnd = queEnd[leftEnd++];
            if (disBegin[nodeEnd] != -1) {
                return (disBegin[nodeEnd] + disEnd[nodeEnd]) / 2 + 1;
            }
            for (int j = 0; j < edgeSize[nodeEnd]; ++j) {
                if (disEnd[edge[nodeEnd][j]] == -1) {
                    disEnd[edge[nodeEnd][j]] = disEnd[nodeEnd] + 1;
                    queEnd[rightEnd++] = edge[nodeEnd][j];
                }
            }
        }
    }
    return 0;
}
