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
