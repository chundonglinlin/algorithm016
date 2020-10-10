学习笔记

每日一记

## 2020-10-10

今天组内同事都来了，布置了一下下半年的规划，还是很多工作等待去完成，希望快速输出更有效率的产品，现在先刷题了。。。
* Day34每日一题推荐：[搜索二维矩阵](https://leetcode-cn.com/problems/search-a-2d-matrix/submissions/)

```bash
bool searchMatrix(int **matrix, int matrixSize, int *matrixColSize, int target)
{
   int row = matrixSize;
   if (row == 0) {
      return false;
   }
   
   int col = *matrixColSize;
   
   // 二分查找
   //当前元素下标以及值
   int idx, element;
   //左右边界
   int left = 0, right = row * col - 1;
   while (left <= right) {
      idx = (left + right) / 2;
      element = matrix[idx / n][ idx % n];
      
      if (element == target) {
         return true;
      } else if ( element < target) {
         left = idx + 1;
      } else {
         right = idx -1;
      }
   }
   
   return false;
}
```

## 2020-10-09

开始上班了，昨晚到京挺晚，半夜吃了个饭，昨天的题目没认真对待，今天挤时间；22点开始刷题。。。

* Day33每日一题推荐：[最长公共子序列](https://leetcode-cn.com/problems/longest-common-subsequence/)

思路： 
状态转移方程：dp
```bash
#define max(a, b) (a > b ? a : b)
int longestCommonSubSequence(char *text1, char *text2)
{
   int len1 = strlen(text1), len2 = strlen(text2);
   int *dp = calloc(len2 + 1, sizeof(int));
   
   for (int i = 1; i < len1; i++) {
      int pre = 0;//1.每行起始作为dp[i-1][j-1] 
      for (int j = 1; j < len2; j++) {
         int next = dp[j]; // dp[i-1][j]:目的是j++后变成左上角dp[i-1][j-1]
         if (text1[i - 1] == text2[j - 1]) {
            dp[j] = pre + 1;// 两个相等+1，状态是dp[i-1][j-1]即pre
         } else {
            dp[j] = max(dp[j], dp[j - 1]);
         }
         
         pre = next;
      }
   }
   
   return dp[len2];
}
```

## 2020-10-08

上午陪老婆规整了一下客厅，闺女自己在那玩的不亦乐乎，下午收拾下启程准备上班。。。

* Day32每日一题推荐：[最大子序和](https://leetcode-cn.com/problems/maximum-subarray/)

解法一：参考官方解法，使用动态规划（状态转移方程 max = max(f(n-1) + an, an）
```bash
#define max(a, b) (a > b ? a : b)
int maxSubArray(int *nums, int numsSize)
{
   int maxSub = nums[0], pre = 0;
   for (int i = 0; i < numsSize; i++) {
      pre = max(nums[i] + pre, nums[i]);
      maxSub = max(maxSub, pre);
   }
   
   return maxSub;
}
```

## 2020-10-07

今天开启单独带娃模式，上午陪娃上英语课，下午陪娃在家刷手机、玩球，然后出去玩了一会轮滑，晚上和家人一起吃了一顿小龙虾（哈哈，闺女的最爱，我只能吃点串串了）

* Day31每日一题推荐：[模拟行走机器人](https://leetcode-cn.com/problems/walking-robot-simulation/)
```bash
#define max(a, b) (a > b ? a : b)

typedef struct {
   int x;
   int y;
} Node;

int cmp(const void *a, const void *b)
{
   Node *temp1 = (Node*)a;
   Node *temp2 = (Node*)b;
   
   int delta = temp1->x - temp2->x;
   if (delta != 0) {
      return delta;
   }
   
   return temp1->y - temp1->y;
}

int robotSim(int *commands, int commandsSize, int **obstacles, int obstaclesSize, int *obstaclesColSize)
{
   //0.定义每步移动方向
   int dx[4] = {0, 1, 0, -1};
   int dy[4] = {1, 0, -1, 0};
   
   //1.定义node存储障碍物坐标，用于将其排序
   Node *node = malloc(sizeof(Node) * obstaclesSize);
   for (int i = 0; i < obstaclesSize; i++) {
      node[i] = obstacles[i];
   }
   
   //2.快排障碍物坐标
   qsort(node, obstaclesSize, sizeof(Node), cmp);
   
   //3.遍历cmd，计算每步的坐标以及是否处于障碍物坐标(di朝向)
   int x = 0, y = 0, di = 0;
   Node cur;
   for (int i = 0; i < commandsSize; i++) {
      if (commands[i] == -2) {
         di = （di + 3） % 4;
      } else if (commands[i] == -1) {
         di = （di + 1） % 4;
      } else {
         for (int j = 0; i < commands[i]; i++) {
            cur.x = x + dx[di];
            cur.y = y + dy[di];
            if (bsearch(&cur, node, obstaclesSize, sizeof(Node), cmp) == NULL) {
               x = cur.x;
               y = cur.y;
               result = max(result, x * x + y * y);
            }
         }
      }
   }
   return result;
}

```


## 2020-10-06

昨晚刷题又打了一局游戏，今早起的有点晚，娃说要去跳蹦床，我们急急忙忙出发去，顺便团购代打卡票，玩了蹦床、海洋球、沙子，吃了个午饭，下午娃竟然非要滑冰，我被迫陪娃进滑冰场，娃第一次滑冰竟然就会了（把我给惊得不行，真是厉害！），晚上回家刷题

* Day30每日一题推荐：[两数之和](https://leetcode-cn.com/problems/two-sum/submissions/)
```bash
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    *returnSize = 0;

    // hash
#define MAX_SIZE 10240
    int hash[MAX_SIZE];
    memset(hash, -1, sizeof(int) * MAX_SIZE);
    
    for (int i = 0; i < numsSize; i++) {
        int pos = hash[(target - nums[i] + MAX_SIZE) % MAX_SIZE];
        if (pos != -1) {
            int * result = malloc(sizeof(int) * 2);
            result[0] = pos;
            result[1] = i;
            *returnSize = 2;
            return result;
        }
    }
    
    return NULL;
}
```

## 2020-10-05

今天一早起来，准备带娃去爬山，到了山底下人山人海，经历千辛万苦最终我们登顶（爬山真累，她们娘俩早早睡了，我还得刷题）

* Day29每日一题推荐：[单词接龙](https://leetcode-cn.com/problems/word-ladder/description/)

**思路** 有点难的一道题目
```bash
int canChange(char *word, char *match, int len)
{
    int ret = 0;
    for ( int i = 0; i < len; i++) {
        if (word[i] != match[i]) {
            if (ret == 1) {
                 return 0;
            } else {
                ret =  1;
            }
        }
    }

    return ret;
}
int ledderLength(char *beginWord, char *endWord, char **wordList, int wordListSize)
{
#define MAX_SIZE 100000
    char *queue[MAX_SIZE], mark[MAX_SIZE] = {0};
    int head = 0, tail = 0, ledder = 1, wordLen = 0, queueSize = 0;

    for (int i = 0; i < wordListSize; i++) {
        if (strcmp(wordList[i], endWord) == 0) {
            break;
        }

        if (i == wordListSize - 1) {
            // no search result
            return 0;
        }
    }

    wordLen = strlen(wordList[0]);

    queue[tail++] = beginWord;

    while (head != tail) {
        queueSize = (tail - head + MAX_SIZE) % MAX_SIZE;

        for (int i = 0; i < queueSize; i++) {
            char *temp = queue[head];
            if (strcmp(temp, endWord) == 0) {
                return ledder;
            }
            head = (head + 1) % MAX_SIZE;

            for (int j = 0; j < wordListSize; j++) {
                if (mark[j] == 0 && canChange(wordList[j], temp, wordLen) == 1) {
                    mark[j] = 1;
                    if (((tail + 1) % MAX_SIZE) != head) {
                        queue[tail] = wordList[j];
                        tail = (tail + 1) % MAX_SIZE;
                    }
                }
            }
        }
        ledder++;
    }

    return 0;
}
```