学习笔记

每日一记

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

