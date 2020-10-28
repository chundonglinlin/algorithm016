学习笔记

## 2020-10-28

> - 今天一觉睡得挺好，洗漱一下去上班，  
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
