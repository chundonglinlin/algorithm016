/*
 * =====================================================================================
 *
 *       Filename:  07-680-validPalindrome.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/11/14 16时49分21秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
bool checkSubstring(char *s, int left, int right)
{
    while (left < right) {
        if (s[left] == s[right]) {
            left++;
            right--;
        } else {
            return false;
        }
    }
    return true;
}

bool validPalindrome(char * s){
    int len = strlen(s);
    int left = 0, right = len - 1;
    int max = 0;
    while (left < right) {
        if (s[left] == s[right]){
            left++;
            right--;
        } else {
            // 判断子串是否符合回文串
            // 跳过第一个或者最后一个字符
            return checkSubstring(s, left + 1, right) || checkSubstring(s, left, right - 1);
        }
    }

    return true;
}
