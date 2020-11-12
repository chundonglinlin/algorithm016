学习笔记

## Lesson19 高级动态规划

### 1. 动态规划、状态转移方程串讲
* **参考链接**
> - [爬楼梯（阿里巴巴、腾讯、字节跳动在半年内面试常考）](https://leetcode-cn.com/problems/climbing-stairs/)
> - [不同路径（亚马逊、微软、Facebook 在半年内面试中考过）](https://leetcode-cn.com/problems/unique-paths/)
> - [打家劫舍（字节跳动、谷歌、苹果在半年内面试中考过）](https://leetcode-cn.com/problems/house-robber/)
> - [最小路径和（字节跳动、谷歌、亚马逊在半年内面试中考过）](https://leetcode-cn.com/problems/minimum-path-sum/)
> - [股票买卖（字节跳动、亚马逊、Facebook 在半年内面试常考）](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/)

* **课后作业
> - 在学习总结中，[写出不同路径 2](https://leetcode-cn.com/problems/unique-paths-ii/) 这道题目的状态转移方程。
* 思路：方法一：动态规划

```bash
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize,
                             int* obstacleGridColSize) {
    int n = obstacleGridSize, m = obstacleGridColSize[0];
    int f[m];
    memset(f, 0, sizeof(f));
    f[0] = (obstacleGrid[0][0] == 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (obstacleGrid[i][j] == 1) {
                f[j] = 0;
                continue;
            }
            if (j - 1 >= 0 && obstacleGrid[i][j - 1] == 0) {
                f[j] += f[j - 1];
            }
        }
    }

    return f[m - 1];
}
```

### 2. 高级动态规划题目详解
* **参考链接
> - [爬楼梯（阿里巴巴、腾讯、字节跳动在半年内面试常考）](https://leetcode-cn.com/problems/climbing-stairs/)

> - [使用最小花费爬楼梯（亚马逊在半年内面试中考过）](https://leetcode-cn.com/problems/min-cost-climbing-stairs/)

> - [编辑距离（字节跳动、亚马逊、谷歌在半年内面试中考过）](https://leetcode-cn.com/problems/edit-distance/)

* **课后作业
> - [最长上升子序列（字节跳动、亚马逊、微软在半年内面试中考过）](https://leetcode-cn.com/problems/longest-increasing-subsequence/)

> - [解码方法（Facebook、亚马逊、字节跳动在半年内面试中考过）](https://leetcode-cn.com/problems/decode-ways/)

> - [最长有效括号（华为、亚马逊、字节跳动在半年内面试中考过）](https://leetcode-cn.com/problems/longest-valid-parentheses/)

> - [最大矩形（谷歌、微软、字节跳动在半年内面试中考过）](https://leetcode-cn.com/problems/maximal-rectangle/)

> - [不同的子序列（MathWorks 在半年内面试中考过）](https://leetcode-cn.com/problems/distinct-subsequences/)

> - [赛车（谷歌在半年内面试中考过）](https://leetcode-cn.com/problems/race-car/)

## Lesson20 字符串算法
### 1. 字符串基础知识和引申题目
* **参考链接
> - [不可变字符串](https://lemire.me/blog/2017/07/07/are-your-strings-immutable/)

> - [Atoi 代码示例](https://shimo.im/docs/5kykuLmt7a4DdjSP/read)
```bash
//C/C++
int myAtoi(string str) {
   int res = 0;
   int sign = 1;
   size_t index = 0;
   if(str.find_first_not_of(' ') != string::npos) 
       index = str.find_first_not_of(' ');
   if(str[index] == '+' || str[index] == '-')
       sign = str[index] == '-' ? -1 : 1;
    
    while(index < str.size() && isdigit(str[index])) {
        res = res * 10 + (str[index++] - '0');
        if(res*sign > INT_MAX) return INT_MAX;
        if(res*sign < INT_MIN) return INT_MIN; 
    }

   return res*sign;
}
```
* **字符串基础问题
> - [转换成小写字母（谷歌在半年内面试中考过）]()
> - [最后一个单词的长度（苹果、谷歌、字节跳动在半年内面试中考过）]()
> - [宝石与石头（亚马逊在半年内面试中考过）]()
> - [字符串中的第一个唯一字符(亚马逊、微软、Facebook 在半年内面试中考过）]()
> - [字符串转换整数 (atoi) （亚马逊、微软、Facebook 在半年内面试中考过）]()

* **字符串操作问题
> - [最长公共前缀（亚马逊、谷歌、Facebook 在半年内面试中考过）]()
> - [反转字符串（亚马逊、谷歌、苹果在半年内面试中考过）]()
> - [反转字符串 II （亚马逊在半年内面试中考过）]()
> - [翻转字符串里的单词（微软、字节跳动、苹果在半年内面试中考过）]()
> - [反转字符串中的单词 III （微软、字节跳动、华为在半年内面试中考过）]()
> - [仅仅反转字母（字节跳动在半年内面试中考过）]()

* **异位词问题
> - [有效的字母异位词（Facebook、亚马逊、谷歌在半年内面试中考过）]()
> - [字母异位词分组（亚马逊在半年内面试中常考）]()
> - [找到字符串中所有字母异位词（Facebook 在半年内面试中常考）]()

* **回文串问题
> - [验证回文串（Facebook 在半年内面试中常考）]()
> - [验证回文字符串 Ⅱ（Facebook 在半年内面试中常考）]()
> - [最长回文子串（亚马逊、字节跳动、华为在半年内面试中常考）]()

### 2. 高级字符串算法


### 3. 字符串匹配算法


## 本周作业
