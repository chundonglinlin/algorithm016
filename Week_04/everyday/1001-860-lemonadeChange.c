/*
 * =====================================================================================
 *
 *       Filename:  1001-860-lemonadeChange.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/10/01 16时47分05秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>

int lemonadeChange(int *bills, int billsSize)
{
    int money[2] = {0};
    for (int i = 0; i < billsSize; i++) {
        if (bills[i] == 5) {
            money[0]++;
        } else ifi (bills[i] == 10) {
           if (money[0] == 0) {
                return false;
           } 
           money[0]--;
        } else if (bills[i] == 20) {
            if (money[1] > 0) {
                if (money[0] > 0) {
                    money[0]--;
                    money[1]--;
                } else {
                    return false;
                }
            } else {
                if (money[0] > 1) {
                    money[0] -= 2;
                } else {
                    return false;
                }
            }
        }
    }

    return true;
}
