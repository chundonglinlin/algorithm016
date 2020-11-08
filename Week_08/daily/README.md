学习笔记

## 2020-11-08

> - 今天起的很晚，陪娃玩会，然后再一起吃饭、作业，刷题。。。
* Day 62每日一题推荐：[最长有效括号](https://leetcode-cn.com/problems/longest-valid-parentheses/)
* 思路：  
> - 方法一：需遍历整个字符串一次，即可将 \textit{dp}dp 数组求出来
```bash
int longestValidParentheses(char* s) {
    int maxans = 0, n = strlen(s);
    if (n == 0) return 0;
    int dp[n];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i < n; i++) {
        if (s[i] == ')') {
            if (s[i - 1] == '(') {
                dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
            } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                dp[i] = dp[i - 1] +
                        ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
            }
            maxans = fmax(maxans, dp[i]);
        }
    }
    return maxans;
}
```

> - 方法二：要正反遍历两边字符串即可
```bash
int longestValidParentheses(char* s) {
    int n = strlen(s);
    int left = 0, right = 0, maxlength = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }
        if (left == right) {
            maxlength = fmax(maxlength, 2 * right);
        } else if (right > left) {
            left = right = 0;
        }
    }
    left = right = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }
        if (left == right) {
            maxlength = fmax(maxlength, 2 * left);
        } else if (left > right) {
            left = right = 0;
        }
    }
    return maxlength;
}
```

## 2020-11-07

> - 今早5点半到家，哎，坐夜车就是累，白天睡觉陪娃完会，现在刷题交作业。
* Day 62每日一题推荐：[验证回文字符号串II](https://leetcode-cn.com/problems/valid-palindrome-ii/)
* 思路：头尾开始比较，当遇到不相同时，开始比较子串是否回文串
```bash
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
```

## 2020-11-06

> - 今天终于提测了，哎，开发效率太低了，刷刷题，晚上回家。。。  
* Day 61每日一题推荐：[三数之和](https://leetcode-cn.com/problems/3sum/)  
* 思路：快排+二分查找  
```bash
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if (nums == NULL || numsSize < 3) {
        return NULL;
    }
    
    int low, high, now = 0;
    long maxSize = (long)numsSize * 6;
    int **res = (int **)malloc(sizeof(int *) * maxSize);
    *returnColumnSizes = (int *)malloc(sizeof(int) * maxSize);

    // 快排
    qsort(nums, numsSize, sizeof(int), compare);
    
    while (nums[now] <= 0 && (now + 2) < numsSize) {
        while (now > 0 && (now + 2) < numsSize&& nums[now] == nums[now - 1]) {
            now++;
        }
        if ((now + 2) >= numsSize) {
            break;
        }
        low = now + 1;
        high = numsSize - 1;
        int target = -nums[now];
        while(low < high) {
            if (nums[low] + nums[high] == target) {
                res[(*returnSize)] = (int *)malloc(sizeof(int) * 3);
                res[(*returnSize)][0] = nums[now];
                res[(*returnSize)][1] = nums[low];
                res[(*returnSize)][2] = nums[high];
                (*returnColumnSizes)[(*returnSize)] = 3;
                (*returnSize)++;
                int temp_low = nums[low];
                int temp_high = nums[high];
                while (low < numsSize && nums[low] == temp_low) {
                    low++;
                }
                while (high > now && nums[high] == temp_high) {
                    high--;
                }
                if (high <= low) {
                    break;
                }else {
                    continue;
                }
            } 
            
            if (nums[low] + nums[high] < target) {
                low++;
                continue;
            }
            
            if (nums[low] + nums[high] > target) {
                high--;
                continue;
            }
        }
        
        now++;
        low = now + 1;
        high = numsSize - 1;
        continue;
    }
    
    return res;
}
```

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
