/*
 * =====================================================================================
 *
 *       Filename:  02-91-numDecodings.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/10/25 15时37分07秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
int numDecodings(char * s){
    int length=strlen(s);
    int dp[length+1];
    memset(dp,0,sizeof(int)*(length+1));

    if(s[0]=='0')//考虑给的是0的情况。
        return 0;

    dp[0]=1;
    if(s[length-1]!='0')
        dp[1]=1;
    for (int i=2;i<=length;i++) {
        if (s[length-i]=='0')//判断首位是0的情况，这里其实对于的是单独给的0的情况
            continue;
        int tmp=(s[length-i]-'0')*10+(s[length-i+1]-'0');
        if (tmp <= 26 && tmp)
            dp[i]=dp[i]+dp[i-2];
        dp[i]=dp[i]+dp[i-1];
    }
    //dp[length+1]='\0';
    return dp[length];
}
