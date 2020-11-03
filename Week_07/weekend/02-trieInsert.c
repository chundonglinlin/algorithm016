/*
 * =====================================================================================
 *
 *       Filename:  02-trieInsert.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/11/01 16时22分38秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#define MAX_TRIE_COUNT 26

typedef struct _Trie{
    int end;
    struct _Trie *next[MAX_TRIE_COUNT];
} Trie;

/** Initialize your data structure here. */

Trie* trieCreate() {
    return calloc(1, sizeof(Trie));
}

/** Inserts a word into the trie. */
void trieInsert(Trie* obj, char * word) {
    Trie *node = obj;

    for (int i = 0; word[i] != '\0'; i++) {
        int pos = word[i] - 'a';
        if ( node->next[pos] == NULL){
            node->next[pos] = trieCreate();
        }
        node = node->next[pos];
    }
    node->end = 1;
}

/** Returns if the word is in the trie. */
bool trieSearch(Trie* obj, char * word) {
    Trie *node = obj;
    for (int i = 0; word[i] != '\0'; i++){
        int pos = word[i] - 'a';
        if ( node->next[pos] == NULL){
            return false;
        }
        node = node->next[pos];
    }
    return node->end > 0;
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWith(Trie* obj, char * prefix) {
    Trie *node = obj;
    for (int i = 0; prefix[i] != '\0'; i++){
        int pos = prefix[i] - 'a';
        if ( node->next[pos] == NULL){
            return false;
        }
        node = node->next[pos];
    }
    return true;
}

void trieFree(Trie* obj) {
    if (obj == NULL ) 
        return;
    for (int i = 0; i < MAX_TRIE_COUNT; i++) {
        if (obj->next[i]) {
            trieFree(obj->next[i]);
        }
    }
    free(obj);
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 
 * bool param_2 = trieSearch(obj, word);
 
 * bool param_3 = trieStartsWith(obj, prefix);
 
 * trieFree(obj);
*/
