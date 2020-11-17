学习总结

### 2020-11-16

> - 今天优化了代码，推进测试进度，刷刷题
* Day 71 每日一题推荐：[406. 根据身高重建队列](https://leetcode-cn.com/problems/queue-reconstruction-by-height/)
* 思路：将每个人按照身高从大到小进行排序，处理身高相同的人使用的方法类似，即：按照 h_ih 
```bash
int cmp(const void* _a, const void* _b) {
    int *a = *(int**)_a, *b = *(int**)_b;
    return a[0] == b[0] ? a[1] - b[1] : b[0] - a[0];
}

int** reconstructQueue(int** people, int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes) {
    // 快排
    qsort(people, peopleSize, sizeof(int*), cmp);

    int** ans = malloc(sizeof(int*) * peopleSize);
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int) * peopleSize);
    for (int i = 0; i < peopleSize; i++) {
        (*returnColumnSizes)[i] = 2;
    }

    for (int i = 0; i < peopleSize; ++i) {
        int* person = people[i];
        (*returnSize)++;
        for (int j = (*returnSize) - 1; j > person[1]; j--) {
            ans[j] = ans[j - 1];
        }
        int* tmp = malloc(sizeof(int) * 2);
        tmp[0] = person[0], tmp[1] = person[1];
        ans[person[1]] = tmp;
    }

    return ans;
}

```
