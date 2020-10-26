/*
 * =====================================================================================
 *
 *       Filename:  20201026-547-findCircleNum.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/10/27 07时47分16秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
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
