学习笔记

## 2020-11-09

> - 一年一度的双十一来了，熬夜值班备战，来吧
* Day 65每日一题推荐：[三角形最小路径和](https://leetcode-cn.com/problems/triangle/)
* 思路：动态规划
```
int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
    // 动态规划
    int f[2][triangleSize];
    memset(f, 0, sizeof(f));
    f[0][0] = triangle[0][0];
    for (int i = 1; i < triangleSize; ++i) {
        int curr = i % 2;
        int prev = 1 - curr;
        f[curr][0] = f[prev][0] + triangle[i][0];
        for (int j = 1; j < i; ++j) {
            f[curr][j] = fmin(f[prev][j - 1], f[prev][j]) + triangle[i][j];
        }
        f[curr][i] = f[prev][i - 1] + triangle[i][i];
    }
    int ret = f[(triangleSize - 1) % 2][0];
    for (int i = 1; i < triangleSize; i++) {
        ret = fmin(ret, f[(triangleSize - 1) % 2][i]);
    }
    return ret;
}
```


> - 今天回来上班，哎，早起赶车，路上玩手机，加油加油，
* Day 64每日一题推荐：[删除排序链表中的重复元素](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/)  
* 思路：1）有序 2）相邻元素比较即可  
```bash
struct ListNode* deleteDuplicates(struct ListNode* head){
{
    struct ListNode *temp = head;
    while (temp && temp->next) {
        struct ListNode *next = temp->next;
        if (temp->val == next->val) {
            temp->next = next->next;
            free(next);
        } else {
            temp = next;
        }
    }
    return head;
}
```
