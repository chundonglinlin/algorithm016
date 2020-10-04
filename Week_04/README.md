学习笔记
新的一周又开始啦

## lesson09(深度优先和广度优先) ##
### 深度优先搜索dfs模板 ###
#### 递归写法 ####
    //C/C++
    //递归写法：
    map<int, int> visited;

    void dfs(Node* root) {
        // terminator
        if (!root) return ;

        if (visited.count(root->val)) {
            // already visited
            return ;
        }

        visited[root->val] = 1;

        // process current node here.
        // ...
        for (int i = 0; i < root->children.size(); ++i) {
            dfs(root->children[i]);
        }
        return ;
    }

#### 非递归写法 ####
    //C/C++
    //非递归写法：
    void dfs(Node* root) {
        map<int, int> visited;
        if(!root) return ;

        stack<Node*> stackNode;
        stackNode.push(root);

        while (!stackNode.empty()) {
            Node* node = stackNode.top();
            stackNode.pop();
            if (visited.count(node->val)) continue;
            visited[node->val] = 1;


            for (int i = node->children.size() - 1; i >= 0; --i) {
                stackNode.push(node->children[i]);
            }
        }

        return ;
    }

### 广度优先搜索bfs模板 ###
    // C/C++
    void bfs(Node* root) {
        map<int, int> visited;
        if(!root) return ;

        queue<Node*> queueNode;
        queueNode.push(root);

        while (!queueNode.empty()) {
            Node* node = queueNode.top();
            queueNode.pop();
            if (visited.count(node->val)) continue;
            visited[node->val] = 1;

            for (int i = 0; i < node->children.size(); ++i) {
                queueNode.push(node->children[i]);
            }
        }

        return ;
    }

### 实战题目 ###

* 102.[二叉树的层序遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/)
* 433.[最小基因变化](https://leetcode-cn.com/problems/minimum-genetic-mutation/#/description)
* 22.[括号生成](https://leetcode-cn.com/problems/generate-parentheses/#/description)
* 515.[在每个树行中找最大值](https://leetcode-cn.com/problems/find-largest-value-in-each-tree-row/#/description)

### 课后作业 ###

* 127.[单词接龙](https://leetcode-cn.com/problems/word-ladder/description/)
* 126.[单词接龙 II](https://leetcode-cn.com/problems/word-ladder-ii/description/)
* 200.[岛屿数量](https://leetcode-cn.com/problems/number-of-islands/)
* 529.[扫雷游戏](https://leetcode-cn.com/problems/minesweeper/description/)

## lesson10(贪心算法) ##

### 实战题目 ###

* 322.coin change题目[链接](https://leetcode-cn.com/problems/coin-change/)
* 动态规划定义[链接](https://zh.wikipedia.org/wiki/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92)

### 课后作业

* 860.[柠檬水找零](https://leetcode-cn.com/problems/lemonade-change/description/)
* 122.[买卖股票的最佳时机 II](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/description/) 
* 455.[分发饼干](https://leetcode-cn.com/problems/assign-cookies/description/)
* 874.[模拟行走机器人](https://leetcode-cn.com/problems/walking-robot-simulation/description/)
* 55.[跳跃游戏](https://leetcode-cn.com/problems/jump-game/)
* 45.[跳跃游戏 II](https://leetcode-cn.com/problems/jump-game-ii/)

## lesson11(二分查找)

* [二分查找代码模板](https://shimo.im/docs/xvIIfeEzWYEUdBPD/read)
```bash
int binarySearch(const vector<int>& nums, int target) {
	int left = 0, right = (int)nums.size()-1;

	while (left <= right) {
		int mid = left + (right - left)/ 2;
		if (nums[mid] == target) return mid;
		else if (nums[mid] < target) left = mid + 1;
		else right = mid - 1;
	}

	return -1;
}
```

* [Fast InvSqrt() 扩展阅读](https://www.beyond3d.com/content/articles/8/)
```bash
float InvSqrt (float x){
    float xhalf = 0.5f*x;
    int i = *(int*)&x;
    i = 0x5f3759df - (i>>1);
    x = *(float*)&i;
    x = x*(1.5f - xhalf*x*x);
    return x;
}
```

### 实战题目

* 69.[x的平方根](https://leetcode-cn.com/problems/sqrtx/)
* 367.[有效的完全平方数](https://leetcode-cn.com/problems/valid-perfect-square/)

### 课后作业

* 33.[搜索旋转排序数组](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/)
* 74.[搜索二维矩阵](https://leetcode-cn.com/problems/search-a-2d-matrix/)
* 153.[寻找旋转排序数组中的最小值](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/)
* 使用二分查找，寻找一个半有序数组 [4, 5, 6, 7, 0, 1, 2] 中间无序的地方

### 周末作业

#### Easy

* 860.[柠檬水找零](https://leetcode-cn.com/problems/lemonade-change/description/)
* 122.[买卖股票的最佳时机 II](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/description/)
* 455.[分发饼干](https://leetcode-cn.com/problems/assign-cookies/description/)
* 874.[模拟行走机器人](https://leetcode-cn.com/problems/walking-robot-simulation/description/)
* 使用二分查找，寻找一个半有序数组 [4, 5, 6, 7, 0, 1, 2] 中间无序的地方

#### Medium

#### Hard



