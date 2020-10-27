学习笔记

## 2020-10-26

> - 今天一早起床赶飞机，结果说需要核酸检测才行，没办法只能退票，去定点医院做个检测后，等结果出来再买票了，卧铺一晚上（临铺鼾声不停）  
* Day50 每日一题推荐：[朋友圈](https://leetcode-cn.com/problems/friend-circles/)  
* 思路：  
```bash
void Visist(int** M, int MSize, int *visit, int num) //用来标记&&访问一个起点开始的朋友圈
{
    for(int i = 0; i< MSize; i++) {
        if(M[num][i] == 1 && visit[i]==0) {
            visit[i] = 1;
            Visist(M, MSize, visit, i);
        }
    }
}

int findCircleNum(int** M, int MSize, int* MColSize) {
#define MAX_SIZE 1024
    int *visit = calloc(MAX_SIZE, sizeof(int));//用来标记一个节点是否被访问过！
    int circleNum = 0;
    for(int i = 0; i < MSize; i++) {
        if(visit[i] == 0) {
            Visist(M, MSize, visit, i);
            circleNum++;
        }
    }

    return circleNum;
}
```
