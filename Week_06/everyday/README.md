学习笔记

每日一记

## 2020-10-23  

周五啦，现场一上午保障工作（副市长都来了），下午回公司，晚上和同事吃了烤全羊，还是非常香的，半夜飞回家，耽搁了一天刷题。。。。
* Day47 每日一题推荐：[单词接龙](https://leetcode-cn.com/problems/word-ladder/description/)  
* 思路：  
```bash
int canChange(char *word, char *match, int len)
{
    int ret = 0;
    for (int i = 0; i < len; i++) {
        // 出现两个字母不同时，返回0
        if (word[i] != match[i]) {
            if (ret == 1) {
                // 第二次不相同时，直接返回0
                return 0;
            } else {
                // 出现一次不相同，标识ret=1
                ret = 1;
            }
        }
    }

    return ret;
}

int ladderLength(char *beginWord, char *endWord, char **wordList, int wordListSize)
{
#define MAX_SIZE 10240
    char *queue[MAX_SIZE] = {0}, mark[MAX_SIZE] = {0}, *wordTemp;
    int head = 0, tail = 0;

    int count = 1, queSize = 0;
    int wordLen = strlen(wordList[0]);

    /*  判断结束符在不在list 中 */
    for (int i = 0; i < wordListSize; i++) {
        if(strcmp(endWord, wordList[i]) == 0) {
            break;
        }

        if (i == wordListSize - 1) {
            // 无匹配
            return 0;
        }
    }

    /* beginWord 入队 */
    queue[tail++]  = beginWord;

    while (head != tail) {
        queSize = (tail - head + MAX_SIZE) % MAX_SIZE;
        for (int i = 0; i < queSize; i++) {
            /* 出队 */
            wordTemp = queue[head];
            if (strcmp(wordTemp, endWord) == 0) {
                return count;
            }
            head = (head + 1) % MAX_SIZE;

            for (int j = 0; j < wordListSize; j++) {
                if (mark[j] == 0 && canChange(wordTemp, wordList[j], wordLen) == 1) {
                    mark[j] = 1;
                    if ((tail + 1) % MAX_SIZE != head) {
                        queue[tail] = wordList[j];
                        tail = (tail + 1) % MAX_SIZE;
                    }
                }
            }
        }
        count++;
    }
    return 0;
}
```

## 2020-10-22

今天一早起来去现场，看起来北京城也是很大，坐车1个小时才到达目的地（不如打车快），在现场刷一道简单的题目  
* Day46 每日一题推荐：[最大子序和](https://leetcode-cn.com/problems/maximum-subarray/)  
* 思路： 寻找连续子序列之和的最大值，定义初始化sum，每加一个元素判定是否符合最大值，若是则加上，否则重置从当前值开始重新累计
```bash
int maxSubSum(int *nums, int numsSize)
{
    int result = nums[0], sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum = fmax(sum + nums[i], nums[i]);
        result = fmax(result, sum);
    }
    
    return result;
}
```

## 2020-10-21

今天现场支持，很累，发现了延播的很多bug，急需找时间优化一下，完善完善，凌晨起来刷题吧，明天一早去现场。。。  
* Day45每日一题推荐：[岛屿数量](https://leetcode-cn.com/problems/number-of-islands/)
* 思路：xxxx
```bash
void dfs(char** grid, int row, int col, int rowSize, int colSize)
{
    grid[row][col] = '0';

    if (row - 1 >= 0 && grid[row - 1][col] == '1') {
        dfs(grid, row - 1, col, rowSize, colSize);
    }

    if (row + 1 < rowSize && grid[row + 1][col] == '1') {
        dfs(grid, row + 1, col, rowSize, colSize);
    }

    if (col - 1 >= 0 && grid[row][col - 1] == '1') {
        dfs(grid, row, col - 1, rowSize, colSize);
    }

    if (col + 1 < colSize && grid[row][col + 1] == '1') {
        dfs(grid, row, col + 1, rowSize, colSize);
    }
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    // 考虑使用深度优先
    if (gridSize == 0) {
        return 0;
    }

    int num_islands = 0;
    for (int row = 0; row < gridSize; row++) {
        for (int col = 0; col < gridColSize[row]; col++) {
            if (grid[row][col] == '1') {
                num_islands++;
                dfs(grid, row, col, gridSize, gridColSize[row]);
            }
        }
    }

    return num_islands;
}
```

## 2020-10-20

今天临时叫去现场支持，排查hls无发播放问题，ios很神奇，最终发现是推流软件没关闭“消除隔行”，哇哇。。。。。  
* Day44每日一题推荐：[实现Trie (前缀树）](https://leetcode-cn.com/problems/implement-tri-prefix-tree/#/description）
* 思路：
```bash
#define MAX_TRIE_COUNT 26

typedef struct {
    int end;
    struct _Trie *next[MAX_TRIE_COUNT];
} Trie;

/** Initialize your data structure here. */

Trie* trieCreate() {
    return calloc(1, sizeof(Trie));
}

/** Inserts a word into the trie. */
void trieInsert(Trie* obj, char * word) {
    Trie *node = obj;

    for (int i = 0; word[i] != '\0'; i++) {
        int pos = word[i] - 'a';
        if ( node->next[pos] == NULL){
            node->next[pos] = trieCreate();
        }
        node = node->next[pos];
    }
    node->end = 1;
}

/** Returns if the word is in the trie. */
bool trieSearch(Trie* obj, char * word) {
    Trie *node = obj;

    for (int i = 0; word[i] != '\0'; i++) {
        int pos = word[i] - 'a';
        if ( node->next[pos] == NULL){
            return false;
        }
        node = node->next[pos];
    }
    return node->end > 0;
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWith(Trie* obj, char * prefix) {
    Trie *node = obj;
    for (int i = 0; prefix[i] != '\0'; i++){
        int pos = prefix[i] - 'a';
        if ( node->next[pos] == NULL){
            return false;
        }
        node = node->next[pos];
    }
    return true;
}

void trieFree(Trie* obj) {
    if (obj == NULL) {
        return;
    }

    for (int i = 0; i < MAX_TRIE_COUNT; i++) {
        if (obj->next[i]) {
            trieFree(obj->next[i]);
        }
    }

    free(obj);
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 
 * bool param_2 = trieSearch(obj, word);
 
 * bool param_3 = trieStartsWith(obj, prefix);
 
 * trieFree(obj);
*/
```

