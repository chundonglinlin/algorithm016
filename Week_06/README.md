学习笔记

## lesson12（动态规划）

### 1.动态规划的实现以及关键点

* **递归代码模板**
C/C++代码模板  
```bash
// C/C++
void recursion(int level, int param) { 
  // recursion terminator
  if (level > MAX_LEVEL) { 
    // process result 
    return ; 
  }

  // process current logic 
  process(level, param);

  // drill down 
  recursion(level + 1, param);

  // reverse the current level status if needed
}
```

* **分治代码模板**
C/C++代码模板  
```bash
C/C++
int divide_conquer(Problem *problem, int params) {
  // recursion terminator
  if (problem == nullptr) {
    process_result
    return return_result;
  } 

  // process current problem
  subproblems = split_problem(problem, data)
  subresult1 = divide_conquer(subproblem[0], p1)
  subresult2 = divide_conquer(subproblem[1], p1)
  subresult3 = divide_conquer(subproblem[2], p1)
  ...

  // merge
  result = process_result(subresult1, subresult2, subresult3)
  // revert the current level status
 
  return 0;
}
```

* **动态规划定义**  
参考链接: https://en.wikipedia.org/wiki/Dynamic_programming


### 2.DP例题解析

* **Fibonacci数列**
    > 时间复杂度最大O(n^2)
    ```bash
    int fib(int n) {
      return n <= 1 ? n : fib(n -1) + fib(n - 2);
    }
    ```
    优化点，增加重复步骤的存储,时间复杂度O(n)
    ```bash
    int fib(int n, int *memo) {
      if (n <= 1) {
        return n;
      }
      
      if (memo[n] == 0) {
        memo[n] = fib(n -1) + fib(n - 2);
      }
      
      return memo[n];
    }
    ```

* **路径计数**
    > - 动态规划关键点
    1.最优子结构opt[n] = best_of(opt[n-1],opt[n-2],...)  
    2.存储中间状态：opt[i]  
    3.递推公式（状态转移方程或DP方程）  
      Fib：opt[i]=opt[n-1]+opt[n-2]  
      二位路径：opt[i, j]=opt[i+1][j]+opt[i][j+1](且判断a[i][j]是否为空)
    

### 3.DP例题解析

* **动态规划**

> - 小结  
1.打破自己的思维惯性，形成机器思维  
2.理解复杂逻辑的关键  
3.也是职业进阶的要点要领  

> - 参考链接：
[62. 不同路径](https://leetcode-cn.com/problems/unique-paths/)  
[63. 不同路径 II](https://leetcode-cn.com/problems/unique-paths-ii/)  
[1143. 最长公共子序列](https://leetcode-cn.com/problems/longest-common-subsequence/)
[【MIT课程】动态规划 I - 最短路径算法](https://www.bilibili.com/video/av53233912?from=search&seid=2847395688604491997)


### 4.实战题目解析

### 5.实战题目解析

### 6.实战题目解析

### 本周作业

* 中等
    > 最小路径和()  
    解码方法()  
    最大正方形()  
    任务调度器()  
    回文子串()  

* 困难
    > 最长有小括号()  
    编辑距离()  
    矩形区域不超过 K 的最大数值和()  
    青蛙过河()  
    分割数组的最大值()  
    学生出勤记录 II()  
    最小覆盖子串()  
    戳气球()  
