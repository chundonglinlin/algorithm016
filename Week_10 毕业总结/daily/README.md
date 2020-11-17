学习总结

### 2020-11-17

> - 今天最后的修改，准备全部提测后，测试，
* Day72 每日一题：[1030. 距离顺序排列矩阵单元格](https://leetcode-cn.com/problems/matrix-cells-in-distance-order/)
* 思路： 桶排序
```
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int dist(int r1, int c1, int r2, int c2) {
    return fabs(r1 - r2) + fabs(c1 - c2);
}

int** allCellsDistOrder(int R, int C, int r0, int c0, int* returnSize, int** returnColumnSizes) {
    // 桶排序
    int maxDist = fmax(r0, R - 1 - r0) + fmax(c0, C - 1 - c0);
    int* bucket[maxDist + 1][2 * (R + C)];
    int bucketSize[maxDist + 1];
    memset(bucketSize, 0, sizeof(bucketSize));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            int d = dist(i, j, r0, c0);
            int* tmp = malloc(sizeof(int) * 2);
            tmp[0] = i, tmp[1] = j;
            bucket[d][bucketSize[d]++] = tmp;
        }
    }

    int** ret = malloc(sizeof(int*) * R * C);
    *returnColumnSizes = malloc(sizeof(int) * R * C);
    for (int i = 0; i < R * C; i++) {
        (*returnColumnSizes)[i] = 2;
    }
    *returnSize = 0;
    for (int i = 0; i <= maxDist; i++) {
        for (int j = 0; j < bucketSize[i]; j++) {
            ret[(*returnSize)++] = bucket[i][j];
        }
    }
    return ret;
}
```
---
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
