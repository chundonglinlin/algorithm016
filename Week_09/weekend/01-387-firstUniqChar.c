/*
 * =====================================================================================
 *
 *       Filename:  01-387-firstUniqChar.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/11/14 16时19分49秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
int firstUniqChar(char * s){
    // hash
    int result[26] = {0}, len = strlen(s), i;
    // build hash : character and how often it appears
    for (i = 0; i < len; i++) {
        result[s[i] - 'a']++;
    }

    for (i = 0; i < len; i++) {
        if (result[s[i] - 'a'] == 1) {
            return i;
        }
    }

    return -1;
}
