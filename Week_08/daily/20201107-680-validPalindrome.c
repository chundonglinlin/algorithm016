/*
 * =====================================================================================
 *
 *       Filename:  20201107-680-validPalindrome.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/11/08 11时35分36秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
bool checkSubString(char *s, int left, int right)
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
bool validPalindrome(char *s)
{
	int left = 0, right = strlen(s) - 1;
    while (left < right) {
    	if (s[left] == s[right]) {
        	left++;
            right--;
        } else {
        	//返回子串
            return checkSubString(s, left + 1, right) || checkSubString(s, left, right - 1);
        }
    }
    return true;
}
