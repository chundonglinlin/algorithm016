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
