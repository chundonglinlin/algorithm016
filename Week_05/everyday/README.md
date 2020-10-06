学习笔记

每日一记

## 2020-10-06

昨晚刷题又打了一局游戏，今早起的有点晚，娃说要去跳蹦床，我们急急忙忙出发去，顺便团购代打卡票，玩了蹦床、海洋球、沙子，吃了个午饭，下午娃竟然非要滑冰，我被迫陪娃进滑冰场，娃第一次滑冰竟然就会了（把我给惊得不行，真是厉害！），晚上回家刷题

* Day30每日一题推荐：[两数之和](https://leetcode-cn.com/problems/two-sum/submissions/)
```bash
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    *returnSize = 0;

    // hash
#define MAX_SIZE 10240
    int hash[MAX_SIZE];
    memset(hash, -1, sizeof(int) * MAX_SIZE);
    
    for (int i = 0; i < numsSize; i++) {
        int pos = hash[(target - nums[i] + MAX_SIZE) % MAX_SIZE];
        if (pos != -1) {
            int * result = malloc(sizeof(int) * 2);
            result[0] = pos;
            result[1] = i;
            *returnSize = 2;
            return result;
        }
    }
    
    return NULL;
}
```

## 2020-10-05

今天一早起来，准备带娃去爬山，到了山底下人山人海，经历千辛万苦最终我们登顶（爬山真累，她们娘俩早早睡了，我还得刷题）

* Day29每日一题推荐：[单词接龙](https://leetcode-cn.com/problems/word-ladder/description/)

**思路** 有点难的一道题目
```bash
int canChange(char *word, char *match, int len)
{
    int ret = 0;
    for ( int i = 0; i < len; i++) {
        if (word[i] != match[i]) {
            if (ret == 1) {
                 return 0;
            } else {
                ret =  1;
            }
        }
    }

    return ret;
}
int ledderLength(char *beginWord, char *endWord, char **wordList, int wordListSize)
{
#define MAX_SIZE 100000
    char *queue[MAX_SIZE], mark[MAX_SIZE] = {0};
    int head = 0, tail = 0, ledder = 1, wordLen = 0, queueSize = 0;

    for (int i = 0; i < wordListSize; i++) {
        if (strcmp(wordList[i], endWord) == 0) {
            break;
        }

        if (i == wordListSize - 1) {
            // no search result
            return 0;
        }
    }

    wordLen = strlen(wordList[0]);

    queue[tail++] = beginWord;

    while (head != tail) {
        queueSize = (tail - head + MAX_SIZE) % MAX_SIZE;

        for (int i = 0; i < queueSize; i++) {
            char *temp = queue[head];
            if (strcmp(temp, endWord) == 0) {
                return ledder;
            }
            head = (head + 1) % MAX_SIZE;

            for (int j = 0; j < wordListSize; j++) {
                if (mark[j] == 0 && canChange(wordList[j], temp, wordLen) == 1) {
                    mark[j] = 1;
                    if (((tail + 1) % MAX_SIZE) != head) {
                        queue[tail] = wordList[j];
                        tail = (tail + 1) % MAX_SIZE;
                    }
                }
            }
        }
        ledder++;
    }

    return 0;
}
```
