/*
 * =====================================================================================
 *
 *       Filename:  04-557-reverseWords.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/11/14 16时29分01秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
char* reverseWords(char* s) {
    int length = strlen(s);
    int i = 0;
    while (i < length) {
        int start = i;
        while (i < length && s[i] != ' ') {
            i++;
        }

        int left = start, right = i - 1;
        while (left < right) {
            char tmp = s[left];
            s[left] = s[right], s[right] = tmp;
            left++;
            right--;
        }
        while (i < length && s[i] == ' ') {
            i++;
        }
    }
    return s;
}
