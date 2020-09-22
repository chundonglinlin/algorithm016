/*
 * =====================================================================================
 *
 *       Filename:  sword-05-replaceSpace.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/09/22 09时18分07秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
char* replaceSpace(char* s){
    //最简单思路: copy src to dst array
    int len = strlen(s);
    if (len == 0) {
        return "";
    }

    // 申请空间时，需要注意是3倍*原字符串长度 + 1
    char *result = malloc(3 * len + 1);
    memset(result, 0, 3 * len + 1);

    for (int i = 0, j = 0; i < len; i++) {
        if (s[i] == ' ') {
            strcpy(result + j, "%20");
            j += 3;
        } else {
            result[j++] = s[i];
        }
    }

    return result;
}

