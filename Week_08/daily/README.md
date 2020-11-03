学习笔记

## 2020-11-02

> - 今天闺女过生日，哎，没法回去陪呀，今天报名来一线支援，非常的辛苦的工作，刮着大风，一车一车的卸货，哎，刷题吧。。。
* Day 57 每日一题推荐：[字符串中的第一个唯一字符](https://leetcode-cn.com/problems/first-unique-character-in-a-string/)
* 思路： 优先想到了hash，将各个字母减去'a'，得到ASCII码，0-26, 然后放在数组里，初始值为0，遇到对应字母，则加加  
```bash
int findUniqNum(char *s)
{
    int result[26] = {0}, len = strlen{s), i;
    for (i = 0; i < len; i++) {
        result[s[i] - 'a'] ++;
    }
    for (i = 0; i < len; i++) {
        if (result[s[i] - 'a'] == 1) {
            return i;
        }
    }

    return -1;
}
```
