学习笔记

每日一记

## 2020-10-22

今天一早起来去现场，看起来北京城也是很大，坐车1个小时才到达目的地（不如打车快），在现场刷一道简单的题目  
* Day46每日一题推荐：[最大子序和](https://leetcode-cn.com/problems/maximum-subarray/)  
* 思路： 寻找连续子序列之和的最大值，定义初始化sum，每加一个元素判定是否符合最大值，若是则加上，否则重置从当前值开始重新累计
```bash
int maxSubSum(int *nums, int numsSize)
{
    int result = nums[0], sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum = fmax(sum + nums[i], nums[i]);
        result = fmax(result, sum);
    }
    
    return result;
}
```

## 2020-10-21

今天现场支持，很累，发现了延播的很多bug，急需找时间优化一下，完善完善，凌晨起来刷题吧，明天一早去现场。。。  
* Day45每日一题推荐：[岛屿数量](https://leetcode-cn.com/problems/number-of-islands/)
* 思路：xxxx
```bash
void dfs(char** grid, int row, int col, int rowSize, int colSize)
{
    grid[row][col] = '0';

    if (row - 1 >= 0 && grid[row - 1][col] == '1') {
        dfs(grid, row - 1, col, rowSize, colSize);
    }

    if (row + 1 < rowSize && grid[row + 1][col] == '1') {
        dfs(grid, row + 1, col, rowSize, colSize);
    }

    if (col - 1 >= 0 && grid[row][col - 1] == '1') {
        dfs(grid, row, col - 1, rowSize, colSize);
    }

    if (col + 1 < colSize && grid[row][col + 1] == '1') {
        dfs(grid, row, col + 1, rowSize, colSize);
    }
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    // 考虑使用深度优先
    if (gridSize == 0) {
        return 0;
    }

    int num_islands = 0;
    for (int row = 0; row < gridSize; row++) {
        for (int col = 0; col < gridColSize[row]; col++) {
            if (grid[row][col] == '1') {
                num_islands++;
                dfs(grid, row, col, gridSize, gridColSize[row]);
            }
        }
    }

    return num_islands;
}
```

## 2020-10-20

今天临时叫去现场支持，排查hls无发播放问题，ios很神奇，最终发现是推流软件没关闭“消除隔行”，哇哇。。。。。  
*Day44每日一题推荐：[实现Trie (前缀树）](https://leetcode-cn.com/problems/implement-tri)-prefix-tree/#/description）
```bash

```

