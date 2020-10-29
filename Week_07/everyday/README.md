学习笔记

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
