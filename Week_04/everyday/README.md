学习笔记

每日一记

## 2020-10-04

昨天去游乐园转了一圈，玩的很刺激，下午下起了小雨，不得不提前回家。今天刮起了大风，索性不出门在家刷题，陪娃练字、看电视、睡懒觉。

* Day28每日一题推荐：[多数元素](https://leetcode-cn.com/problems/majority-element/description/)

**解法一** （摩尔投票法，遇到相同的数，就投一票，遇到不同的数，就减一票，最后还存在票的数就是众数）
```bash
int majorElement(int *nums, int numsSize)
{
    int count = 1, maj = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (maj == nums[i]) {
            count++;
        } else { 
            count--;
        }
        
        if (count == 0) {
            maj = nums[i + 1];
        }
    }
    return maj;
}
```
**解法二** (如果将数组 nums 中的所有元素按照单调递增或单调递减的顺序排序，那么下标为`n/2`的元素（下标从 0 开始）一定是众数。)
```bash
int compare(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

int majorElement(int *nums, int numsSize)
{
    //快排
    qsort(nums, numsSize, sizeof(int), compare);
    
    //获取
    return nums[numsSize / 2];
}
```
**解法三** （使用hash是第一想法，不过c里面的数组是固定的，容易溢出）
```bash
int majorElement(int *nums, int numsSize)
{
#define MAX_SIZE 10240
    int hash[MAX_SIZE];
    memset(hash, 0, sizeof(int) * MAX_SIZE);
    int maxCount = 0, maxValue = 0;;
    for (int i = 0; i < numsSize; i++) {
        int pos = (nums[i] + MAX_SIZE) % MAX_SIZE;
        hash[pos]++:
        if (hash[pos] > maxCount) {
            maxCount = hash[pos];
            maxValue = nums[i];
        }
    }
    
    if (maxCount <= (numsSize / 2)) {
        maxValue = 0;
    }
    
    return maxValue
}
```

## 2020-10-03

一大早陪娃一起做作业，我刷题，她鬼哭狼嚎写作业

* Day27每日一题推荐：[有效的完全平方数](https://leetcode-cn.com/problems/valid-perfect-square/)
```bash
bool isPerfectSqrt(int num)
{
    bool result = false;
    //二分法
    long low = 1, high = num;
    while (1) {
        if (low > high) {
            break;
        }
        
        long mid = (low + high) / 2;
        long sqrt = mid * mid;
        if (sqrt > num) {
            high = mid - 1;
        } else if (sqrt == num) {
            result = true;
            break;
        } else {
            low = mid + 1;
        }
    }
    return result;
}
```

## 2020-10-02

今天陪娃观影《姜子牙》有感，难意会主题，但3D画面效果还可

* Day26每日一题推荐：[岛屿数量](https://leetcode-cn.com/problems/number-of-islands/)
此题目挺难，还需多多练习
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

## 2020-10-01

今天双节，开心陪娃，晚上陪家人一起吃饭

* Day25 每日一题推荐：[柠檬水找零](https://leetcode-cn.com/problems/lemonade-change/submissions/)
```bash
bool lemonadeChange(int* bills, int billsSize){
    int money[2] = {0};
    for (int i = 0; i < billsSize; i++) {
        if (bills[i] == 5) {
            money[0]++; 
        } else if (bills[i] == 10) {
            if (money[0] == 0) {
                return false;
            }
            money[0]--;
            money[1]++; 
        } else if (bills[i] == 20) {
            //10+5;5+5+5
            if (money[1] >= 1) {
                if (money[0] >= 1) {
                    money[0]--;
                    money[1]--;
                } else {
                    return false;
                }
            } else {
                if (money[0] >= 3) {
                    money[0] -= 3;
                } else {
                    return false;
                }
            }
        }
    }
    return true;
}
```


## 2020-09-30 

放假啦，坚持刷题

* Day24每日一题推荐：[买卖股票的最佳时机](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/submissions/)
```bash
int maxProfit(int* prices, int pricesSize){
    int maxprofit = 0;
    for (int i = 1; i < pricesSize; i++) {
        //当天比上一天涨
        int delta = prices[i] - prices[i - 1];
        if (delta > 0)
            maxprofit += delta;
    }
    return maxprofit;
}
```

## 2020-09-29

* Day23每日一题推荐：[爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/)
```bash
int climbStairs(int n){
    // fib 公式
    // f(n) = f(n-1) + f(n-2)
    if (n <= 2) {
        return n;
    }

    int pre = 1, cur = 2, next;
    for (int i = 3; i <= n; i++) {
        next = pre + cur;
        pre = cur;
        cur = next;
    }

    return cur;
}
```

## 2020-09-28

* Day22每日一题推荐：[全排列](https://leetcode-cn.com/problems/permutations)
```bash
void dfs(int *nums, int numsSize, int depth, int *cur, bool *used, int *count, int **res){
    // deeply need copy array.
    if (depth == numsSize) {
        res[*count] = (int*)malloc(sizeof(int) * numsSize);
        memcpy(res[(*count)++], cur, sizeof(int) * numsSize);
        return;
    }

    for(int i = 0; i < numsSize; ++i) {
        // array item is used
        if(used[i] == true) {
            continue;
        }

        cur[depth] = nums[i];
        used[i] = true;
        //++depth;

        dfs(nums, numsSize, depth + 1, cur, used, count, res);

        //--depth;
        used[i] = false;
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    // calc space (n!)
    int size = 0, count = 1;
    for(int i = 1; i <= numsSize; ++i) {
        count *= i;
    }
    // init
    *returnSize = count;
    *returnColumnSizes = (int*)malloc(sizeof(int) * count);
    for(int i = 0; i < count; ++i) {
        (*returnColumnSizes)[i] = numsSize;
    }

    int **result = (int**)malloc(sizeof(int*) * count);
    int *cur = (int*)malloc(sizeof(int) * numsSize);//each array
    bool *used = (bool*)calloc(numsSize, sizeof(bool));//each array item flag

    dfs(nums, numsSize, 0, cur, used, &size, result);

    return result;
}
```

