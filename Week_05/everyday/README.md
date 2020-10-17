学习笔记

每日一记

## 2020-10-17

今天主要是睡觉，感觉一周没睡醒，所以一直睡到了下午两点，然后来公司加班一会，结果朋友要一起打游戏，哎，玩了一下午，懈怠了，疲了，现在准备刷题  
* Day41每日一题推荐：[搜索旋转排序数组](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/)
```bash
int search(int* nums, int numsSize, int target){
    int n = numsSize;
    if (!n) {
        return -1;
    }

    if (n == 1) {
        return nums[0] == target ? 0 : -1;
    }

    // 二分法查找
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (nums[mid] == target) {
            return mid;
        }

        if (nums[0] <= nums[mid]) {
            if (nums[0] <= target && target < nums[mid]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        } else {
            if (nums[mid] < target && target <= nums[n - 1]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }
    return -1;
}
```

## 2020-10-16

今天忙忙啥，提测，方案推进等，晚上一起吃了个饭，吼吼，导致回家洗漱完不想刷题了，（老师的直播答疑参与了10分钟忙着吃饭去了，哎，）  
* Day40每日一题推荐：[矩形区域不超过K的最大数值](https://leetcode-cn.com/problems/max-sum-of-rectangle-no-larger-than-k/)  
思路：
1、题目翻译：题目意思是求一个二维数组内的一个矩形的和res（1 ×1，1×2，2×2…），且res 是小于等于k的最大值。
如果里面某一个元素或者一个求和等于k的话，那么res直接就是k。
2、解题思路：采用暴力破解法，
先是最左列left到最右列right的遍历，
然后最top行到最bottom行的遍历求助，且保存最大的res值，最后返回即可。
3、知识点：二维数组的内存分配，sum[m]是定义的每行的求和值，
第一步：0与0~matrixSize的组成的矩形块，求出最大的res值；
第二步：1与 1：matrixSize的行组成的矩形块的最大值。
第三步: 列也是按照这个思路求解。
```bash
int maxSumSubMatrix(int **matrix, int matrixSize, int *matrixColSize, int k)
{
   int *sum = (int*)malloc(sizeof(int) * matrixSize);
   int res = -100000;
   int tmp;
   for(int i = 0; i < *matrixColSize; i++){
     memset(sum, 0, sizeof(int) * matrixSize);    
     for(int j = i; j < *matrixColSize; j++){ //组成一个列矩阵，[i,j],从左往右遍历。i固定，j移动
         for(int  m = 0; m < matrixSize; m++){
             sum[m] += matrix[m][j];  //按照每行计算的规则，求每一行的和（j）
         }

         for(int m = 0; m < matrixSize; m++){
             int tmp = sum[m];
             if(tmp <= k && tmp > res ) res = tmp;
             for(int n = m + 1; n < matrixSize; n++) {
                 tmp += sum[n];
                 if(tmp <= k && tmp > res) res = tmp;
              }
         }
     }
   }
   free(sum);
   return res;
}
```bash


## 2020-10-15

今天有点瞎忙活，乱七八糟的，没有产出，哎，一定要严格自律，开始刷题吧。。。

* Day39每日一题推荐：[N叉树的前序遍历](https://leetcode-cn.com/problems/n-ary-tree-preorder-traversal/submissions/)
```bash
struct Node {
   int val;
   int numChildren;
   struct Node *children;
}

void recusive(int *result, int *size, struct Node *root)
{
   if (root == NULL) {
      return;
   }
   
   result[(*size)++] = root->val;
   
   for (int i = 0; i < root->numChildren; i++) {
      recusive(result, size, root->children);
   }
   
   return;
}
int* preoder(struct Node *root, int *returnSize)
{
#define MAX_SIZE 10240
   int *result = malloc(sizeof(int) * MAX_SIZE);
   *returnSize = 0;
   
   recusive(result, returnSize, root);
   
   return result;
}

```


## 2020-10-14

今天似乎有点偷懒，工作上就完成一点，还有很多事情等着做，一直在思考和总结能输出一款牛逼产品，晚上和同事吃了饭（喜得二胎，羡慕），现在才刷题。。。

* Day38每日一题推荐：[打家劫舍II](https://leetcode-cn.com/problems/house-robber-ii/description/)
```bash
int rob(int *nums, int numsSize)
{
   if (numsSize == 1) {
      return nums[0];
   }
   
   int *dp1 = calloc(numsSize + 1, sizeof(int));
   int *dp2 = calloc(numsSize + 1, sizeof(int));
   for (int i = 2; i < numsSize; i++) {
      dp1[i] = fmax(dp1[i - 1], dp1[i - 2] + nums[i - 2]);
      dp2[i] = fmax(dp1[i - 1], dp2[i - 2] + nums[i - 1]);
   }
   
   return fmax(dp1[numsSize], dp2[numsSize]);
}
```

## 2020-10-13

今天挺冷，终于认真的写了代码又测试了一下，中午又做了个核酸，哎，浪费

* Day37每日一题推荐：[零钱兑换](https://leetcode-cn.com/problems/coin-change/)
```bash
int coinsChange(int *coins, int coinsSize, int amount)
{
   int dp[amount + 1];
   dp[0] = 0;
   for (int i = 1; i <= amount; i++) {
      for (int j = 0; j < coinsSize; j++) {
         if (coins[j] <= i) {
            dp[i] = min[dp[i], dp[i - conins[j]] + 1);
         }
      }
   }
   
   return dp[amount] > amount ?  -1 : dp[amount];
}
```

## 2020-10-12

今天起的挺早，困得不行，坐着公交车去上班，然后发现全网在刷青疫情，把我给急的不行，中午临时决定去定点做个检测，到了地方后发现人超级多，都是有青旅史，哎，晚上回来刷题吧
* Day36每日一题推荐：[最小路径和](https://leetcode-cn.com/problems/minimum-path-sum/submissions/)

思路：
参考了一下官方解法，先分别按行列，累计加得出到达当前节点的值，然后开始从当前节点选择临近上一节点的最小值。并累加，直至得出所有节点累计值，选择最后一个值返回。
```bash
int minPathSum(int **grid, int gridSize, int *greoColSize)
{
   int row = gridSize, col = gridColSize[0];
   int **dp = grid;
   
   // row
   for (int i = 1; i < row; i++) {
      dp[i][0] = dp[i - 1][0] + grid[i][0];
   }
   
   // col
   for (int j = 0; j < col; j++) {
      dp[0][j] = dp[0][j - 1] + grid[0][j];
   }
   
   // 累计值
   for (int i = 1; i < row; i++) {
      for (int j = 1; j < col; j++) {
         dp[i][j] = fmin(dp[i - 1][j], dp[i][j -1) + grid[i][j];
      }
   }
   
   return dp[row - 1][col -1];
}
```

## 2020-10-11

今天早上得早点起来，和朋友一起去趟天津挂牌，正好刷完题目再睡吧。。
* Day35每日一题推荐：[替换空格](https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/submissions/)

思路：比较简单的题目，从字符串s拷贝到新申请的数组里
```bash
char *replaceSpace(char *s) 
{
   int len = strlen(s);
   char *result = malloc(3 * len + 1);
   char *p = result;
   for (int i = 0; i < len; i++) {
      if (s[i] == ' ') {
         strcpy(p, "%20");
         p += 3;
      } else {
         *p++ = s[i];
      }
   }
   
   return result;
}
```

## 2020-10-10

今天组内同事都来了，布置了一下下半年的规划，还是很多工作等待去完成，希望快速输出更有效率的产品，现在先刷题了。。。
* Day34每日一题推荐：[搜索二维矩阵](https://leetcode-cn.com/problems/search-a-2d-matrix/submissions/)

思路：将二维数组看成一维数组来遍历，使用二分法查找，注意下标转换
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
