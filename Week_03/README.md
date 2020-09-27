学习笔记

# 解题技巧 #
## 递归模板 ##
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

## 分枝代码模版 ##
    // C/C++
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

## 牛顿迭代 ##
### 原理 ###
* 牛顿迭代法快速寻找平方根 [原理](http://www.matrix67.com/blog/archives/361)

### 参考代码 ###
    int mysqrt(int x){
        double tmpx = x;
        double k = 1.0;
        double k0 = 0.0;
        while(abs(k0-k) >= 1){
            k0 = k;
            k = (k + tmpx/k)/2;
        }
        return (int)k;
    }

    int mysqrt(int x){
        float tmpx = (float)x;
        float xhalf = 0.5f*tmpx;
        int i = *(int*)&tmpx;
        i = 0x5f375a86 - (i >> 1);
        tmpx = *(float*) & i;
        tmpx = tmpx * (1.5f - xhalf*tmpx*tmpx);
        tmpx = tmpx * (1.5f - xhalf*tmpx*tmpx);


        int res = (int)(1.0/tmpx);
        if((res+1) * (res + 1) <= x)
            res += 1;
        return res;
    }
