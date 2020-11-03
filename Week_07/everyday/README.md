学习笔记

## 2020-11-01

> - 今天睡了一上午，哎，老是值班，中午洗衣服/拖地，好吧，收拾收拾，我的小屋还挺冷的，看了一下王者直播，哎，该死的时间过的好快////  
* Day56每日一题推荐：[最长重复子数组](https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray/)  
* 思路：  
> - 方法一：// 滑动窗口
/* 枚举 A 和 B 所有的对齐方式。对齐的方式有两类：
   第一类为 A 不变，B 的首元素与 A 中的某个元素对齐；
   第二类为 B 不变，A 的首元素与 B 中的某个元素对齐。
   对于每一种对齐方式，我们计算它们相对位置相同的重复子数组即可。
*/
```bash
int maxLength(int* A, int* B, int addA, int addB, int len) {
    int ret = 0, k = 0;
    for (int i = 0; i < len; i++) {
        //相对位置相同的重复子数组
        if (A[addA + i] == B[addB + i]) {
            k++;
        } else {
            k = 0;
        }
        ret = fmax(ret, k);
    }
    return ret;
}

// 滑动窗口
/* 枚举 A 和 B 所有的对齐方式。对齐的方式有两类：
   第一类为 A 不变，B 的首元素与 A 中的某个元素对齐；
   第二类为 B 不变，A 的首元素与 B 中的某个元素对齐。
   对于每一种对齐方式，我们计算它们相对位置相同的重复子数组即可。
*/
int findLength(int* A, int ASize, int* B, int BSize) {
    int ret = 0;
    for (int i = 0; i < ASize; i++) {
        //第一类
        int len = fmin(BSize, ASize - i);
        int maxlen = maxLength(A, B, i, 0, len);
        ret = fmax(ret, maxlen);
    }

    for (int i = 0; i < BSize; i++) {
        //第二类
        int len = fmin(ASize, BSize - i);
        int maxlen = maxLength(A, B, 0, i, len);
        ret = fmax(ret, maxlen);
    }
    return ret;
}
```
> - 方法二： 动态规划   
```bash
int findLength(int* A, int ASize, int* B, int BSize) {
    int dp[ASize + 1][BSize + 1];
    memset(dp, 0, sizeof(dp));
    int ans = 0;
    for (int i = ASize - 1; i >= 0; i--) {
        for (int j = BSize - 1; j >= 0; j--) {
            dp[i][j] = A[i] == B[j] ? dp[i + 1][j + 1] + 1 : 0;
            ans = fmax(ans, dp[i][j]);
        }
    }
    return ans;
}

```

## 2020-10-31

> - 今天同事离职了，哎，工作的事情不好说，晚上公司重保，加油，青春挥洒热血。。。  
* Day55每日一题推荐：[数组的相对排序](https://leetcode-cn.com/problems/relative-sort-array/)  
* 思路：  
```bash
int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize){
#define MAX_SIZE 1024
    int arr[MAX_SIZE] = {0};
    int i, j=0;
    for(i = 0; i < arr1Size; i++){//记录arr1数字出现的次数次数
        arr[arr1[i]]++;
    }
    for(i = 0; i < arr2Size; i++){//找到在arr2和arr1都出现的数字
        while(arr[arr2[i]] > 0){
            arr1[j] = arr2[i];
            j++;
            arr[arr2[i]]--;
        }
    }
    for(i = 0; i < MAX_SIZE; i++){//找arr1有，arr2没有的
        while(arr[i] > 0){
            arr1[j++] = i;
            arr[i]--;
        }
    }
    *returnSize = arr1Size;
    return arr1;
}
```

## 2020-10-30

> - 今天工作上详细梳理了全流程，详细的规划了实现过程，哎，年底的冲刺开始了。。。。
* Day 54每日一题推荐：[两两交换链表中的节点](https://leetcode-cn.com/problems/swap-nodes-in-pairs/)  
* 思路：  
```bash
struct ListNode* swapPairs(struct ListNode* head){
    // 增加第一个节点
    struct ListNode* first = malloc(sizeof(struct ListNode));
    first->next = head;
    struct ListNode* result = first;
    while (head && head->next != NULL) {
        // second
        first->next = head->next;
        // third
        struct ListNode* third = head->next->next;

        //reverse
        first->next->next = head;
        head->next = third;

        /*
            | first | head   | 
            | first | second | third |
        */
        //reset
        first = head;
        head = head->next;
    }

    return result->next;
}
```

## 2020-10-29 

> - 昨晚熬夜值班了，睡得有点晚，还是习惯一早起来，到公司开始一天的工作，今天效率有点低，梳理了一下近期的工作内容，方案上还是需要讨论充分后再动手做，下午重新梳理，对了一下实现细节。。。  
* Day53每日一题推荐：[颠倒二进制位](https://leetcode-cn.com/problems/reverse-bits/)  
* 思路：  
```bash
uint32_t reverseBits(uint32_t n) {
    /*
    步骤实现该算法：
    首先，我们将原来的 32 位分为 2 个 16 位的块。
    然后我们将 16 位块分成 2 个 8 位的块。
    然后我们继续将这些块分成更小的块，直到达到 1 位的块。
    在上述每个步骤中，我们将中间结果合并为一个整数，作为下一步的输入。
           b1b0
         10/  \01
        b1 0   0 b0
        0  b1  b0 0
            b1b0
    */
    n = (n >> 16) | (n << 16);
    n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
    n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
    n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
    n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
    return n;
}
```

## 2020-10-28

> - 今天一觉睡得挺好，洗漱一下去上班，将nginx端口保持功能梳理了一下，增加了一下配置，以便进行其他相关操作。。。  
* Day52 每日一题推荐：[打家劫舍](https://leetcode-cn.com/problems/house-robber/)  
* 思路：  
```bash
int rob(int* nums, int numsSize){
    if(numsSize == 0) {
        return 0;
    }

    if (numsSize == 1) {
        return nums[0];
    }

    int first = nums[0], second = fmax(nums[0], nums[1]);
    for(int i = 2; i < numsSize; i++) {
        int temp = second;
        second = fmax(first + nums[i], second);
        first = temp;
    }
    return second;
}
```


## 2020-10-27

> - 凌晨5点抵京，还是有点小冷，在公司喝了口热水，扒拉着手机，困得不行，睡了一个小时，白天相对有点效率，推进了相关功能，六点去跑了5公里，真冷（得穿外套跑比较合适），回家收拾一下刷题。  
* Day51 每日一题推荐：[有效的完全平方数](https://leetcode-cn.com/problems/valid-perfect-square/)  
* 思路：这道题目还是挺简单的，使用二分法取中值，计算中值的平方是否等于num；还有一种解法是[牛顿迭代法](http://www.matrix67.com/blog/archives/361)
```bash
bool isPerfectSquare(int num)
{
    int left = 1, right = num;
    while (left <= right) {
        long mid = (left + right) / 2;
        long sqrt = mid * mid;
        if (sqrt == num) {
            return true;
        } else if (sqrt < num) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return false;
}
```

## 2020-10-26

> - 今天一早起床赶飞机，结果说需要核酸检测才行，没办法只能退票，去定点医院做个检测后，等结果出来再买票了，卧铺一晚上（临铺鼾声不停）  
* Day50 每日一题推荐：[朋友圈](https://leetcode-cn.com/problems/friend-circles/)  
* 思路：  
```bash
void Visist(int** M, int MSize, int *visit, int num) //用来标记&&访问一个起点开始的朋友圈
{
    for(int i = 0; i< MSize; i++) {
        if(M[num][i] == 1 && visit[i]==0) {
            visit[i] = 1;
            Visist(M, MSize, visit, i);
        }
    }
}

int findCircleNum(int** M, int MSize, int* MColSize) {
#define MAX_SIZE 1024
    int *visit = calloc(MAX_SIZE, sizeof(int));//用来标记一个节点是否被访问过！
    int circleNum = 0;
    for(int i = 0; i < MSize; i++) {
        if(visit[i] == 0) {
            Visist(M, MSize, visit, i);
            circleNum++;
        }
    }

    return circleNum;
}
```
