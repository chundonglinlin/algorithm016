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
    * 二叉树的层序遍历 []()
    * 最小基因变化 []()
    * 括号生成 []()
    * 在每个树行中找最大值 []()

### 课后作业 ###
    * 单词接龙 []()
    * 单词接龙 II []() 
    * 岛屿数量 []()
    * 扫雷游戏 []()

## lesson10(贪心算法) ##



## lesson11(二分查找) ##


