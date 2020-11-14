学习笔记

## 2020-11-14

> - 周六了，起不来呀/睡不醒，睡得晚一天没精神，只能下午起来做作业了，刷刷题。。。
* Day 69每日一题推荐：[除自身以外数组的乘积](https://leetcode-cn.com/problems/product-of-array-except-self/)
* 思路：遍历三遍，计算每个元素左侧的乘积，计算每个元素右侧的乘积，最后再左右相乘  
```bash
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize){
	*returnSize = 0;
    if (nums == NULL || numsSize <= 0) {
		return NULL;
	}

    int n = numsSize;
	int *result = (int *)malloc(sizeof(int) * n);
	if (result == NULL) {
		return NULL;
	}

	int left[n], right[n];

    // i元素左侧的乘积
    left[0] = 1;
	for (int i = 1; i < n; i++) {
		left[i] = left[i - 1] * nums[i - 1];
	}

    // 右侧乘积
	right[n - 1] = 1;
	for (int i = n - 2; i >= 0; i--) {
		right[i] = right[i + 1] * nums[i + 1];
	}

    // 两侧乘积
	for (int i = 0; i < n; i++) {
		result[i] = left[i] * right[i] ;
	}
	*returnSize = n;
	return result;
}
```

## 2020-11-13

> - 周五没有写周报，团建，哎，玩游戏，忘记刷题了。。。
* Day68 每日一题推荐：[买卖股票的最佳时机 II](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/)
* 思路： 贪心算法，图当前挣钱再出手  
```bash
int maxProfit(int* prices, int pricesSize){
    int maxprofit = 0;
    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] > prices[i - 1])
            maxprofit += prices[i] - prices[i - 1];
    }
    return maxprofit;
}
```

## 2020-11-12

> - 
* Day 67每日一题推荐：[全排列](https://leetcode-cn.com/problems/permutations/)
* 思路：  
```bash
void CopyDate(int *ans, int *nums, int numsSize)
{
    for (int i = 0; i < numsSize; i++) {
        ans[i] = nums[i];
    }

    return;
}

void Swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void compute(int *nums, int numsSize, int index, int **arr, int *row)
{
    if (index == numsSize - 1) {
        arr[*row] = (int *)malloc(numsSize * sizeof(int));
        CopyDate(arr[(*row)++], nums, numsSize);
        return;
    }

    for (int i = index; i < numsSize; i++) {
        Swap(&nums[index], &nums[i]);
        compute(nums, numsSize, index + 1, arr, row);
        Swap(&nums[i], &nums[index]);
    }

    return;
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    *returnSize = 0;
    if (nums == NULL || numsSize == 0) {
        return NULL;
    }

#define MAX_SIZE 10000
    int **arr = (int **)malloc(MAX_SIZE * sizeof(int *));
    int *cols = (int *)malloc(MAX_SIZE * sizeof(int));

    compute(nums, numsSize, 0, arr, returnSize);

    for (int i = 0; i < *returnSize; i++) {
        cols[i] = numsSize;
    }
    *returnColumnSizes = cols;

    return arr;
}
```


## 2020-11-11

> - 熬夜值班，赶进度，数据上大屏幕，刷刷。。。
* Day 66 每日一题推荐：[单词接龙](https://leetcode-cn.com/problems/word-ladder/description/)
* 思路：  
```bash
struct Trie {
    int ch[27];
    int val;
} trie[50001];

int size, nodeNum;

void insert(char* s, int num) {
    int sSize = strlen(s), add = 0;
    for (int i = 0; i < sSize; ++i) {
        int x = s[i] - '`';
        if (trie[add].ch[x] == 0) {
            trie[add].ch[x] = ++size;
            memset(trie[size].ch, 0, sizeof(trie[size].ch));
            trie[size].val = -1;
        }
        add = trie[add].ch[x];
    }
    trie[add].val = num;
}

int find(char* s) {
    int sSize = strlen(s), add = 0;
    for (int i = 0; i < sSize; ++i) {
        int x = s[i] - '`';
        if (trie[add].ch[x] == 0) {
            return -1;
        }
        add = trie[add].ch[x];
    }
    return trie[add].val;
}

int addWord(char* word) {
    if (find(word) == -1) {
        insert(word, nodeNum++);
    }
    return find(word);
}

int edge[30001][26];

int edgeSize[30001];

void addEdge(char* word) {
    int wordSize = strlen(word), id1 = addWord(word);
    for (int i = 0; i < wordSize; ++i) {
        char tmp = word[i];
        word[i] = '`';
        int id2 = addWord(word);
        edge[id1][edgeSize[id1]++] = id2;
        edge[id2][edgeSize[id2]++] = id1;
        word[i] = tmp;
    }
}

int ladderLength(char* beginWord, char* endWord, char** wordList, int wordListSize) {
    size = nodeNum = 0;
    memset(trie[size].ch, 0, sizeof(trie[size].ch));
    trie[size].val = -1;
    memset(edgeSize, 0, sizeof(edgeSize));
    for (int i = 0; i < wordListSize; ++i) {
        addEdge(wordList[i]);
    }
    addEdge(beginWord);
    int beginId = find(beginWord), endId = find(endWord);
    if (endId == -1) {
        return 0;
    }

    int disBegin[nodeNum];
    memset(disBegin, -1, sizeof(disBegin));
    disBegin[beginId] = 0;
    int queBegin[nodeNum];
    int leftBegin = 0, rightBegin = 0;
    queBegin[rightBegin++] = beginId;

    int disEnd[nodeNum];
    memset(disEnd, -1, sizeof(disEnd));
    disEnd[endId] = 0;
    int queEnd[nodeNum];
    int leftEnd = 0, rightEnd = 0;
    queEnd[rightEnd++] = endId;

    while (leftBegin < rightBegin && leftEnd < rightEnd) {
        int queBeginSize = rightBegin - leftBegin;
        for (int i = 0; i < queBeginSize; ++i) {
            int nodeBegin = queBegin[leftBegin++];
            if (disEnd[nodeBegin] != -1) {
                return (disBegin[nodeBegin] + disEnd[nodeBegin]) / 2 + 1;
            }
            for (int j = 0; j < edgeSize[nodeBegin]; ++j) {
                if (disBegin[edge[nodeBegin][j]] == -1) {
                    disBegin[edge[nodeBegin][j]] = disBegin[nodeBegin] + 1;
                    queBegin[rightBegin++] = edge[nodeBegin][j];
                }
            }
        }
        int queEndSize = rightEnd - leftEnd;
        for (int i = 0; i < queEndSize; ++i) {
            int nodeEnd = queEnd[leftEnd++];
            if (disBegin[nodeEnd] != -1) {
                return (disBegin[nodeEnd] + disEnd[nodeEnd]) / 2 + 1;
            }
            for (int j = 0; j < edgeSize[nodeEnd]; ++j) {
                if (disEnd[edge[nodeEnd][j]] == -1) {
                    disEnd[edge[nodeEnd][j]] = disEnd[nodeEnd] + 1;
                    queEnd[rightEnd++] = edge[nodeEnd][j];
                }
            }
        }
    }
    return 0;
}
```

## 2020-11-10

> - 一年一度的双十一来了，熬夜值班备战，来吧
* Day 65每日一题推荐：[三角形最小路径和](https://leetcode-cn.com/problems/triangle/)
* 思路：动态规划
```
int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
    // 动态规划
    int f[2][triangleSize];
    memset(f, 0, sizeof(f));
    f[0][0] = triangle[0][0];
    for (int i = 1; i < triangleSize; ++i) {
        int curr = i % 2;
        int prev = 1 - curr;
        f[curr][0] = f[prev][0] + triangle[i][0];
        for (int j = 1; j < i; ++j) {
            f[curr][j] = fmin(f[prev][j - 1], f[prev][j]) + triangle[i][j];
        }
        f[curr][i] = f[prev][i - 1] + triangle[i][i];
    }
    int ret = f[(triangleSize - 1) % 2][0];
    for (int i = 1; i < triangleSize; i++) {
        ret = fmin(ret, f[(triangleSize - 1) % 2][i]);
    }
    return ret;
}
```

## 2020-11-09

> - 今天回来上班，哎，早起赶车，路上玩手机，加油加油，
* Day 64每日一题推荐：[删除排序链表中的重复元素](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/)  
* 思路：1）有序 2）相邻元素比较即可  
```bash
struct ListNode* deleteDuplicates(struct ListNode* head){
{
    struct ListNode *temp = head;
    while (temp && temp->next) {
        struct ListNode *next = temp->next;
        if (temp->val == next->val) {
            temp->next = next->next;
            free(next);
        } else {
            temp = next;
        }
    }
    return head;
}
```
