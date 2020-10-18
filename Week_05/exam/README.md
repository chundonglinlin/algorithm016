学习笔记

第五周（考试）

## Tips

* 15 道单项选择题，2 道编程题
* 时长3个小时
* [领扣测评系统考生需知 0828](https://shimo.im/docs/786914580242497f/read)


### 单选题

1.将10阶对称矩阵压缩存储到一位数组A中，则数组A的长度最少为（）  
- [ ] A:100  
- [ ] B:40  
- [x] C:55  
- [ ] D:80  

2.下面哪项不是链表由于数组的特点？（）  
- [ ] A:方便删除  
- [ ] B:方便插入  
- [ ] C:长度可变  
- [x] D:存储空间小  

3.对于长度为n的线性表，建立其对应的单链表的时间复杂度为（）  
- [ ] A:O(1)  
- [ ] B:O(log2n)  
- [x] C:O(n)  
- [ ] D:O(n^2)  

4.需要频繁的插入删除操作使用什么结构比较合适？（）  
- [ ] A:数组  
- [ ] B:队列  
- [x] C:链表  
- [ ] D:栈 

5.已知循环队列存储在一维数组A[0, ..., n - 1]中，且队列非空时front和rear分别指向队头和队尾元素、若初始时队列为空，且要求第一个进入队列的元素存储在
A[0]处， 则初始时front和rear的值分别是（）  
- [ ] A:0, 0  
- [x] B:0, n-1  
- [ ] C:n-1, 0  
- [ ] D:n-1, n-1

6.在一个长度为n的顺序表中删除第i个元素，要移动（）个元素，如果要在第i个元素前插入一个元素，要后移（）个元素。  
- [ ] A:n-1, n-i+1  
- [x] B:n-i+1, n-i  
- [ ] C:n-i, n-i  
- [ ] D:n-i+1, n-i+1

7.二叉树的线序遍历和中序遍历如下，先序遍历：EFHIGJK；中序遍历：HFIEJKG，则二叉树根节点为（）  
- [X] A:E  
- [ ] B:F  
- [ ] C:G  
- [ ] D:H

8.在一棵二叉树上第四层的节点数最多是（）
- [X] A:8  
- [ ] B:9  
- [ ] C:10  
- [ ] D:11

9.下列关于书的深度优先搜索算法描述错误的是（）
- [ ] A:按照某种条件往前试探搜索，如果前进中遭到失败，则退回头另选通路继续搜索，直到找到条件的目标为止。  
- [X] B:先访问该节点所有的子节点，遍历完毕后选取它未访问过的子节点重复上述过程，直到找到条件的目标为止。  
- [ ] C:假设树的顶点数为V，则算法的空间复杂度为O（V）  
- [ ] D:深度优先算法非常适合使用递归来实现

10.有关贪心法叙述正确的是（）
- [X] A:采用局部最优策略  
- [ ] B:  
- [ ] C:  
- [ ] D:

11.二分查找的时间复杂度（）
- [ ] A:O()  
- [ ] B:(N)  
- [X] C:O(logN)  
- [ ] D:

12.对有序数组（2、11、15、19、30、32、61、72、88、90、96）进行二分查找，则成功找到15需比较（）次
- [ ] A:3  
- [ ] B:4  
- [X] C:2  
- [ ] D:5

13.以下哪个不属于单向哈希表的特征（假设没有冲突）
- [ ] A:它把任意长度的信息转换成固定的长度输出  
- [X] B:它把固定的信息转换成任意长度信息输出  
- [ ] C:根据特定的哈希值，它可以找到对应的原信息值  
- [ ] D:不同的信息很难产生一样的哈希值

14.下面那个不是使用分治法的特征（）
- [ ] A:该问题可以分解为若干个规模较小的相同问题  
- [ ] B:子问题的解可以合并为该问题的解  
- [X] C:子问题必须是一样的  
- [ ] D:子问题之间不包含公共的子问题

15.n皇后最坏情况下的时间复杂度为（）
- [ ] A:O(n)  
- [ ] B:O(n^2)  
- [X] C:O(n^n)  
- [ ] D:O(n^3)


### 编程题

#### 16. [45. 跳跃游戏 II](https://leetcode-cn.com/problems/jump-game-ii/)
**解题思路**
> 贪心算法，使用局部最优解，每次跳跃时都去找能跳的范围内最大的那个然后继续比如[2,3,1,1,4,7]
当前为2时，可以跳到3或1的位置，那么选其中最大，跳到3，然后选能跳的3步中最大的4，如此往复，如果能跳到最后，那么跳的次数一定是最少的。
代码方面，因为有跳的动作，所以需要知道什么时候该跳，往哪跳，那就需要两个变量来不断的告诉程序如何执行跳的动作。
先说往哪跳，可以确定的知道是在某个范围内能跳的最远的下标，能跳的最远计算应该为index（当前在哪）+nums[index]（能跳多远）; 可用三目或Max函数不断求得即可。
另外什么时候跳，仔细想下就是上面提到的那某个范围的终点，这个范围也好理解，其实就是上次跳到的那个位置的下标。在循环里，用（curIndex == i）判断就可得知是不是该跳了，当然，这个值一开始为0；
```bash
int jump(int *nums, int numsSize)
{
    if (numsSize == 0) {
      return 0;
    }
    
    int jumpCount = 0, cur = 0, next = 0;
    for (int i = 0; i < numsSize - 1; i++) {
      next  = fmax(nums[i] + i, next);
      if (cur = i) {
         cur = next;
         jumpCount++;
      }
    }
    
    return jumpCount;
}
```

#### 17. [18. 四数之和](https://leetcode-cn.com/problems/4sum/)  
**解题思路**
> 选用快排加双指针

```bash
int comp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (numsSize < 4) {
        return NULL;
    }

#define MAX_SIZE 1024
    int** result = malloc(sizeof(int*) * MAX_SIZE);
    *returnColumnSizes = malloc(sizeof(int) * MAX_SIZE);

    qsort(nums, numsSize, sizeof(int), comp);

    int length = numsSize;
    for (int i = 0; i < length - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
            break;
        }
        if (nums[i] + nums[length - 3] + nums[length - 2] + nums[length - 1] < target) {
            continue;
        }
        for (int j = i + 1; j < length - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) {
                continue;
            }
            if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) {
                break;
            }
            if (nums[i] + nums[j] + nums[length - 2] + nums[length - 1] < target) {
                continue;
            }

            int left = j + 1, right = length - 1;
            while (left < right) {
                int sum = nums[i] + nums[j] + nums[left] + nums[right];
                if (sum == target) {
                    int* tmp = malloc(sizeof(int) * 4);
                    tmp[0] = nums[i], tmp[1] = nums[j], tmp[2] = nums[left], tmp[3] = nums[right];
                    (*returnColumnSizes)[(*returnSize)] = 4;
                    result[(*returnSize)++] = tmp;

                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    left++;
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }
    return result;
}

```











