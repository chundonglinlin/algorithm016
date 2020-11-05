学习笔记

## 2020-11-05

> - 今天把相关的直播链路优化打通了，明天提测，加油，刷题。。。
* Day 60每日一题推荐：[最长上升子序列](https://leetcode-cn.com/problems/longest-increasing-subsequence/)
* 思路：  
 > - 方法一：动态规划，双层循环
 ```bash
 int lengthOfLIS(int* nums, int numsSize){
    if (numsSize == 0) {
        return 0;
    }
    // 动态规划
    int dp[numsSize];
    dp[0] = 1;
    int maxans = 1;
    for (int i = 1; i < numsSize; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = fmax(dp[i], dp[j] + 1);
            }
        }
        maxans = fmax(maxans, dp[i]);
    }
    return maxans;
}
 ```
> - 方法二：动态规划+二分查找，单层循环，提高时间复杂度
```bash
int lengthOfLIS(int *nums, int numsSize)
{
    int len = 1, n = numsSize;
    if (n == 0) {
        return 0;
    }

    // 动态规划 + 二分查找
    int dp[n + 1];
    dp[len] = nums[0];
    for (int i = 1; i < n; ++i) {
        if (nums[i] > dp[len]) {
            dp[++len] = nums[i];
        } else {
            int l = 1, r = len, pos = 0; // 如果找不到说明所有的数都比 nums[i] 大，此时要更新 dp[1]，所以这里将 pos 设为 0
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (dp[mid] < nums[i]) {
                    pos = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            dp[pos + 1] = nums[i];
        }
    }
    return len;
}
```

## 2020-11-04

> - 今天效率很高，刷题目。。。
* Day59 每日一题推荐：[反转字符串 II](https://leetcode-cn.com/problems/reverse-string-ii/)
* 思路：  
```bash
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
```

## 2020-11-03

> - 新的一天开始啦，昨天搬货还是挺累的，一早墨迹半天出门，到公司后梳理了一遍又一遍的，哎，开发效率怎么这么低，赶紧赶紧，晚上跑了步，还是挺冷，刷刷题。。
* Day58每日一题推荐：[不同路径](https://leetcode-cn.com/problems/unique-paths/)  
* 思路：状态转移方程  
```bash
int uniquePaths(int m, int n){
    // 状态转移方程
    int dp[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || j == 0) {     //最上一行或者最左一列
                dp[i][j] = 1;
            } else {
                /*
                dp[i][j]的值就是第 i 行第 j 列这个格子的上面那个格子的值加上左边那个格子的值，
                也就是dp[i][j] = dp[i-1][j] + dp[i][j-1]，
                因为这两个格子都可以走到dp[i][j]这个格子，那么他们的路径数之和就是dp[i][j]的值。
                状态转移方程是dp[i][j] = dp[i-1][j] + dp[i][j-1]，
                当 i == 0 或者 j == 0 的时候无外乎就是最上一行或者最左一列，我们在最上一行的路径数只能是一条（因为只能一直往左走），
                所以 dp[0][j]的值全为 1，同理最左一列的值也是1（因为只能一直往下走），
                其余的值按照状态转移方程就可以填满了，最后返回最右下角的值（dp[n-1][m-1]）就可以了。
                */
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }
    
    return dp[n-1][m-1];
}
```


## 2020-11-02

> - 今天闺女过生日，哎，没法回去陪呀，今天报名来一线支援，非常的辛苦的工作，刮着大风，一车一车的卸货，哎，刷题吧。。。
* Day 57 每日一题推荐：[字符串中的第一个唯一字符](https://leetcode-cn.com/problems/first-unique-character-in-a-string/)
* 思路： 优先想到了hash，将各个字母减去'a'，得到ASCII码，0-26, 然后放在数组里，初始值为0，遇到对应字母，则加加  
```bash
int findUniqNum(char *s)
{
    int result[26] = {0}, len = strlen{s), i;
    for (i = 0; i < len; i++) {
        result[s[i] - 'a'] ++;
    }
    for (i = 0; i < len; i++) {
        if (result[s[i] - 'a'] == 1) {
            return i;
        }
    }

    return -1;
}
```
