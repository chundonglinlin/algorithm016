/*
 * =====================================================================================
 *
 *       Filename:  01-860-lemonadeChange.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/10/04 11时54分28秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>

bool lemonadeChange(int *bills, int billsSize)
{
    bool result = true;
    int five = 0, ten = 0;
    for (int i = 0; i < billsSize; i++) {
        if (bills[i] == 5) {
            five++;
        } else if (bills[i] == 10) {
            if (five < 1) {
                result = false;
                break;
            }
            five--;
            ten++;
        } else if (bills[i] == 20) {
            if (ten > 0) {
                if (five < 1) {
                    result = false;
                    break;
                }
                five--;
                ten--;
            } else {
                if (five < 3) {
                    result = false;
                    break;
                } 
                five -= 3;
            }
        }
    }

    return result;
}
