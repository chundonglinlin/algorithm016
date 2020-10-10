/*
 * =====================================================================================
 *
 *       Filename:  1009-1143-longestCommonSubsequence.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/10/10 23时33分56秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>

int longestCommonSubsequence(char *text1, char *text2)
{
    int len1 = strlen(text1);
    int len2 = strlen(text2);

    int *dp = calloc(len2 + 1, sizeof(int));
    for (int i = 1; i <= len1; i++) {
        int pre = 0;
        for (int j = 1; j <= len2; j++) {
            int next = dp[j];
            if (text1[i - 1] == text2[j - 1]) {
                dp[j] = pre + 1;
            } else {
                dp[j] = max(dp[j], dp[j - 1]);
            }

            pre = next;
        }
    }

    return dp[len2];
}
