/*
 * =====================================================================================
 *
 *       Filename:  05-917-reverseOnlyLetters.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/11/14 16时32分56秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
char * reverseOnlyLetters(char * s){
    if (s == NULL) {
        return NULL;
    }

    int len = strlen(s);
    char *a = (char*)malloc(sizeof(char) * (len + 1));
    memcpy(a, s, sizeof(char) * (len + 1));
    int i = 0, j = len - 1; // 首尾指针 
    while(i < j) { // 双指针往中间移动 
        while (i < j && !isalpha(a[i])) {
            i++;
        } 
        while (i < j && !isalpha(a[j])) {
            j--;
        } 
        if (i < j ) {
            char t = a[i];
            a[i] = a[j];
            a[j] = t;
            i++, j--;
        }
    }
    return a;
}
