/*
 * =====================================================================================
 *
 *       Filename:  20201102-387-findUniqNum.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/11/02 20时52分15秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
int findUniqNum(char *s)
{
    int result[26], len = strlen(s), i;
    for (i = 0; i < len; i++) {
        result[s[i] - 'a']++;
    }
    for (i = 0; i < len; i++) {
        if (result[s[i] - 'a'] == 1) {
            return i;
        }
    }

    return i;
}
