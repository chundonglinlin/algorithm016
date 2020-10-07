/*
 * =====================================================================================
 *
 *       Filename:  1007-874-robotSim.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/10/07 22时02分50秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>

int robotSim(int *commands, int commandsSize, int **obstacles, int obstaclesSize, int *obstaclesColSize)
{
    //0.走法定义(上右下左)
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    //1.障碍物坐标定义
    Node *node = malloc(sizeof(Node) * obstaclesSize);
    for (int i = 0; i < obstaclesSize; i++) {
        node[i].x = obstacles[i][0].x;
        node[i].y = obstacles[i][1].y;
    }

    //2.有序排序快排
    qsort(node, obstaclesSize, sizeof(Node), cmp);

    //3.cmd遍历坐标，通过二分查找有序组是否含有障碍物坐标
    int x = 0, y =0, di = 0;
    for (int i = 0; i < commandsSize; i++) {
        if (commands[i] == -2) {
            di = (di + 3) % 4;
        } else if (commands[i] == -1) {
            di = (di + 1) % 4;
        } else {
            for (int j = 0; j < commands[i]; j++) {
                //4.每步按照di方向走
                cur.x = x + dx[di];
                cur.y = y + dy[di];
                if (bsearch(&cur, node, obstaclesSize, sizeof(Node), cmp) == NULL) {
                    x = cur.x;
                    y = cur.y;
                    result = max(result, x * x + y * y);
                }
            }
        }
    }

    return result;
}
