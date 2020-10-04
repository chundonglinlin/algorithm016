/*
 * =====================================================================================
 *
 *       Filename:  03-455-findContentChildren.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/10/04 12时40分39秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

int findContentChildren(int *g, int gSize, int *s, intsSize)
{
    int count = 0;

    //快排
    qsort(g, gSize, sizeof(int), compare);
    qsort(s, sSize, sizeof(int), compare);

    //双指针
    int gIndex = 0, sIndex = 0;
    while (gIndex < gSize && sIndex < sSize) {
        if (s[sIndex] >= g[gIndex]) {
            sIndex++;
            gIndex++;
            count++;
        } else {
            sIndex++;
        }
    }

    return count;
}
