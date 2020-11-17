/*
 * =====================================================================================
 *
 *       Filename:  02-541-reverseStr.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/11/14 16时21分17秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
char * reverseStr(char * s, int k){
    /* 
     * 2k 一组，翻转 k 个，如果不够 k ，全部翻转该组。即条件判断是否满 k 个即可。
     * 双指针反转字符串常规操作，可以是 while (left < right), 也可以是 for i -> 一半 方式。
     */
    int len = strlen(s);
    for (int i = 0; i < len; i += 2 * k) {
        int left = i;
        int right = (i + k - 1 < len) ? i + k - 1 : len - 1;  //是否超界？
        while (left < right) {
            char tmp = s[left];
            s[left++] = s[right];
            s[right--] = tmp;
        }
    }
    return s;
}
