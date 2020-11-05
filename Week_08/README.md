学习笔记

## Lesson16-位运算

### 1. 位运算基础及实战要点
* 参考链接：[如何从十进制转换为二进制](https://zh.wikihow.com/%E4%BB%8E%E5%8D%81%E8%BF%9B%E5%88%B6%E8%BD%AC%E6%8D%A2%E4%B8%BA%E4%BA%8C%E8%BF%9B%E5%88%B6)


### 2. 位运算实战题目解析
* 参考链接：[N 皇后位运算代码示例](https://shimo.im/docs/YzWa5ZZrZPYWahK2/read)  
```bash
class Solution {
public:
    int totalNQueens(int n) {
        dfs(n, 0, 0, 0, 0);
        
        return this->res;
    }
    
    void dfs(int n, int row, int col, int ld, int rd) {
        if (row >= n) { res++; return; }
        
        // 将所有能放置 Q 的位置由 0 变成 1，以便进行后续的位遍历
        int bits = ~(col | ld | rd) & ((1 << n) - 1);
        while (bits > 0) {
            int pick = bits & -bits; // 注: x & -x
            dfs(n, row + 1, col | pick, (ld | pick) << 1, (rd | pick) >> 1);
            bits &= bits - 1; // 注: x & (x - 1)
        }
    }


private:
    int res = 0;
};
```

* 实战题目 / 课后作业  
> - [位 1 的个数（Facebook、苹果在半年内面试中考过）](https://leetcode-cn.com/problems/number-of-1-bits/)  
> - [2 的幂（谷歌、亚马逊、苹果在半年内面试中考过）](https://leetcode-cn.com/problems/power-of-two/)  
> - [颠倒二进制位（苹果在半年内面试中考过）](https://leetcode-cn.com/problems/reverse-bits/)  
> - [N 皇后（字节跳动、亚马逊、百度在半年内面试中考过）](https://leetcode-cn.com/problems/n-queens/description/)  
> - [N 皇后 II （亚马逊在半年内面试中考过）](https://leetcode-cn.com/problems/n-queens-ii/description/)  
> - [比特位计数（字节跳动、Facebook、MathWorks 在半年内面试中考过）](https://leetcode-cn.com/problems/counting-bits/description/)



## Lesson17-布隆过滤器和LRU缓存

### 1. 布隆过滤器的实现及应用
* 参考链接：  
> - [布隆过滤器的原理和实现](https://www.cnblogs.com/cpselvis/p/6265825.html)

> - [使用布隆过滤器解决缓存击穿、垃圾邮件识别、集合判重](https://blog.csdn.net/tianyaleixiaowu/article/details/74721877)

> - [布隆过滤器 Python 代码示例](https://shimo.im/docs/UITYMj1eK88JCJTH/read)

> - [布隆过滤器 Python 实现示例](https://www.geeksforgeeks.org/bloom-filters-introduction-and-python-implementation/)

> - [高性能布隆过滤器 Python 实现示例](https://github.com/jhgg/pybloof)

> - [布隆过滤器 Java 实现示例 1](https://github.com/lovasoa/bloomfilter/blob/master/src/main/java/BloomFilter.java)

> - [布隆过滤器 Java 实现示例 2](https://github.com/Baqend/Orestes-Bloomfilter)

### 2. LRU Cache的实现、应用和题解
* 参考链接:
> - [Understanding the Meltdown exploit](https://www.sqlpassion.at/archive/2018/01/06/understanding-the-meltdown-exploit-in-my-own-simple-words/)
> - [替换算法总揽](https://en.wikipedia.org/wiki/Cache_replacement_policies)
> - [LRU Cache Python 代码示例](https://shimo.im/docs/CoyPAyXooGcDuLQo/read)

* 实战题目 / 课后作业
> - [LRU 缓存机制（亚马逊、字节跳动、Facebook、微软在半年内面试中常考）](https://leetcode-cn.com/problems/lru-cache/#/)

## Lesson18-排序算法

### 1. 初级排序和高级排序的实现和特性
* 参考链接：
> - [十大经典排序算法](https://www.cnblogs.com/onepixel/p/7674659.html)

> - [快速排序代码示例](https://shimo.im/docs/TX9bDbSC7C0CR5XO/read)
```bash
//C/C++
int random_partition(vector<int>& nums, int l, intr) {
  int random_pivot_index = rand() % (r - l +1) + l;  //随机选择pivot
  int pivot = nums[random_pivot_index];
  swap(nums[random_pivot_index], nums[r]);
  int i = l - 1;
  for (int j=l; j<r; j++) {
    if (nums[j] < pivot) {
      i++;
      swap(nums[i], nums[j]);
    }
  }
  int pivot_index = i + 1;
  swap(nums[pivot_index], nums[r]);
  return pivot_index;
}
void random_quicksort(vector<int>& nums, int l, int r) {
  if (l < r) {
    int pivot_index = random_partition(nums, l, r);
    random_quicksort(nums, l, pivot_index-1);
    random_quicksort(nums, pivot_index+1, r);
  }
}
```

> - [归并排序代码示例](https://shimo.im/docs/sDXxjjiKf3gLVVAU/read)  
```bash
void mergeSort(vector<int> &nums, int left, int right) {
	if (left >= right) return;
	
	int mid = left + (right - left) / 2;
	mergeSort(nums, left, mid);
	mergeSort(nums, mid+1, right);
	
	merge(nums, left, mid, right);
}


void merge(vector<int> &nums, int left, int mid, int right) {
	vector<int> tmp(right-left+1);
	int i = left, j = mid+1, k = 0;
	
	while (i <= mid && j <= right) {
		tmp[k++] = nums[i] < nums[j] ? nums[i++] : nums[j++];
	}
	while (i <= mid) tmp[k++] = nums[i++];
	while (j <= right) tmp[k++] = nums[j++];
	
	for (i = left, k = 0; i <= right;) nums[i++] = tmp[k++];
}
```

> - [堆排序代码示例](https://shimo.im/docs/M2xfacKvwzAykhz6/readd)
```bash
void heapify(vector<int> &array, int length, int i) {
    int left = 2 * i + 1, right = 2 * i + 2;
    int largest = i;

    if (left < length && array[left] > array[largest]) {
        largest = left;
    }
    if (right < length && array[right] > array[largest]) {
        largest = right;
    }

    if (largest != i) {
        int temp = array[i]; array[i] = array[largest]; array[largest] = temp;
        heapify(array, length, largest);
    }


    return ;
}

void heapSort(vector<int> &array) {
    if (array.size() == 0) return ;

    int length = array.size();
    for (int i = length / 2 - 1; i >= 0; i--) 
        heapify(array, length, i);

    for (int i = length - 1; i >= 0; i--) {
        int temp = array[0]; array[0] = array[i]; array[i] = temp;
        heapify(array, i, 0);
    }

    return ;
}
```

> - **课后作业**  
用自己熟悉的编程语言，手写各种初级排序代码，提交到学习总结中。

### 2. 特殊排序及实战题目详解
* 参考链接:
> - [十大经典排序算法](https://www.cnblogs.com/onepixel/p/7674659.html)

> - [9 种经典排序算法可视化动画](https://www.bilibili.com/video/av25136272)

> - [6 分钟看完 15 种排序算法动画展示](https://www.bilibili.com/video/av63851336)

> - **实战题目 / 课后作业**  
[数组的相对排序（谷歌在半年内面试中考过）](https://leetcode-cn.com/problems/relative-sort-array/)  
[有效的字母异位词（Facebook、亚马逊、谷歌在半年内面试中考过）](https://leetcode-cn.com/problems/valid-anagram/)  
[力扣排行榜（此题选做；Bloomberg 在半年内面试中考过）](https://leetcode-cn.com/problems/design-a-leaderboard/)  
[合并区间（Facebook、字节跳动、亚马逊在半年内面试中常考）](https://leetcode-cn.com/problems/merge-intervals/)  
[翻转对（字节跳动在半年内面试中考过）](https://leetcode-cn.com/problems/reverse-pairs/)  


##  本周作业及下周预习
### 本周作业
* **简单**

[位 1 的个数（Facebook、苹果在半年内面试中考过）](https://leetcode-cn.com/problems/number-of-1-bits/)  
[2 的幂（谷歌、亚马逊、苹果在半年内面试中考过）](https://leetcode-cn.com/problems/power-of-two/)  
[颠倒二进制位（苹果在半年内面试中考过）](https://leetcode-cn.com/problems/reverse-bits/)  
[用自己熟悉的编程语言，手写各种初级排序代码，提交到学习总结中。]()  
[数组的相对排序（谷歌在半年内面试中考过）](https://leetcode-cn.com/problems/relative-sort-array/)  
[有效的字母异位词（Facebook、亚马逊、谷歌在半年内面试中考过）](https://leetcode-cn.com/problems/valid-anagram/)  

* **中等**

[LRU 缓存机制（亚马逊、字节跳动、Facebook、微软在半年内面试中常考）](https://leetcode-cn.com/problems/lru-cache/#/)  
[力扣排行榜（Bloomberg 在半年内面试中考过）](https://leetcode-cn.com/problems/design-a-leaderboard/)  
[合并区间（Facebook、字节跳动、亚马逊在半年内面试中常考）](https://leetcode-cn.com/problems/merge-intervals/)  

* **困难**

[N 皇后（字节跳动、亚马逊、百度在半年内面试中考过）](https://leetcode-cn.com/problems/n-queens/description/)  
[N 皇后 II （亚马逊在半年内面试中考过）](https://leetcode-cn.com/problems/n-queens-ii/description/)  
[翻转对（字节跳动在半年内面试中考过）](https://leetcode-cn.com/problems/reverse-pairs/)  

### 下周预习题目：

[不同路径](https://leetcode-cn.com/problems/unique-paths/)  
[最小路径和](https://leetcode-cn.com/problems/minimum-path-sum/)  
