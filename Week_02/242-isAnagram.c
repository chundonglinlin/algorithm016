/*
 * =====================================================================================
 *
 *       Filename:  242-isAnagram.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/09/19 19时35分42秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>

bool isAnagram(char * s, char * t){
    //字母异位词
    //考虑使用hash统计字母出现的次数
#define MAX_SIZE 1024
    int hash_s[MAX_SIZE], hash_t[MAX_SIZE];
    memset(hash_s, 0, sizeof(hash_s));
    memset(hash_t, 0, sizeof(hash_t));

    for (int i = 0; i < strlen(s); i++) {
        hash_s[s[i] - '0']++;
    }

    for (int i = 0; i < strlen(t); i++) {
        hash_t[t[i] - '0']++;
    }

    for (int i = 0; i < MAX_SIZE; i++) {
        if (hash_s[i] != hash_t[i]) {
            return false;
        }
    }

    return true;
}
