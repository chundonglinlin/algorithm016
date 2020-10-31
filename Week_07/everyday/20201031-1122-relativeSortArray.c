/*
 * =====================================================================================
 *
 *       Filename:  20201031-1122-relativeSortArray.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/10/31 20时53分27秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize){
#define MAX_SIZE 1024
    int arr[MAX_SIZE] = {0};
    int i, j=0;
    for(i = 0; i < arr1Size; i++){//记录arr1数字出现的次数次数
        arr[arr1[i]]++;
    }
    for(i = 0; i < arr2Size; i++){//找到在arr2和arr1都出现的数字
        while(arr[arr2[i]] > 0){
            arr1[j] = arr2[i];
            j++;
            arr[arr2[i]]--;
        }
    }
    for(i = 0; i < MAX_SIZE; i++){//找arr1有，arr2没有的
        while(arr[i] > 0){
            arr1[j++] = i;
            arr[i]--;
        }
    }
    *returnSize = arr1Size;
    return arr1;
}
