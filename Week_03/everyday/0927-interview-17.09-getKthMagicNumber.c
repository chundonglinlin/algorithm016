/*
 * =====================================================================================
 *
 *       Filename:  0927-interview-17.09-getLthMagicNumber.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/09/27 22时35分06秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>

int min(int a, int b, int c) {
    int min = (a < b ? a : b);
    return  (min < c ? min : c);
}

int getKthMagicNumber(int k){
    int *result = malloc(sizeof(int) * k);
    result[0] = 1;
    int param[3] = {0};

    for (int i = 1; i < k; i++) {
        result[i] = min(3 * result[param[0]], 5 *  result[param[1]],  7 * result[param[2]]);
        if (result[i] == 3 * result[param[0]]) {
            param[0]++;
        }
        if (result[i] == 5 * result[param[1]]) {
            param[1]++;
        }
        if (result[i] == 7 * result[param[2]]) {
            param[2]++;
        }
    }

    return result[k - 1];
 }

