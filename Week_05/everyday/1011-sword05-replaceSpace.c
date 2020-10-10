/*
 * =====================================================================================
 *
 *       Filename:  1011-sword05-replaceSpace.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/10/11 00时19分57秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>

char *replaceSpace(char *s)
{
    int len = strlen(s);
    char *result = malloc(3 * len + 1);
    char *p = result;
    for (int i = 0; i < len; i++) {
        if (s[i] ==' ') {
            strcpy(p, "%20");
            p += 3;
        } else {
            *p++ = s[i];
        }
    }

    return result;
}
