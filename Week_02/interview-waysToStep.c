/*
 * =====================================================================================
 *
 *       Filename:  interview-waysToStep.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/09/20 21时54分23秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
int waysToStep(int n){
    // 解析思路
    // f(n) = f(n-1) + f(n-2) + f(n-3)

    if (n < 3) {
        return n;
    }

    if (n == 3) {
        return 4;
    }

    unsigned long *result = calloc(n + 1, sizeof(unsigned long));
    result[1] = 1;
    result[2] = 2;
    result[3] = 4;

    for (int i = 4; i <= n; i++) {
        result[i] = (result[i - 1] + result[i -2] + result[i - 3]) % 1000000007;
    }

    return result[n];
}

作者：chundonglinlin
链接：https://leetcode-cn.com/problems/three-steps-problem-lcci/solution/shang-tai-jie-wen-ti-du-shi-fei-bo-na-qi-shu-lie-g/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
