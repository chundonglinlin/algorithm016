/*
 * =====================================================================================
 *
 *       Filename:  06-205-isIsomorphic.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/11/14 16时44分57秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
bool isIsomorphic(char * s, char * t){
    int slen = strlen(s), tlen = strlen(t);
    if (slen != tlen) {
        return false;
    }

    //A为存储映射关系的哈希表，B为记录t[i]是否存在映射关系，记得将B看成bool变量数组
    //因为测试案例中有字母也有数字，所以开了256个空间
    int A[256] = {0}, B[256] = {0};
    for(int i = 0;i < slen; i++) {
        if(A[s[i]] == 0 && B[t[i]] == 0) {
            //都为0说明s[i]和t[i]都是第一次出现，建立一对一映射关系
            A[s[i]] = t[i];//将s[i]映射成t[i]
            B[t[i]] = 1;//说明t[i]存在映射关系
        } else if (A[s[i]] !=0 && B[t[i]]==0) {
            //A[s[i]]不为0说明s[i]通过哈希表A映射成了其他的字符
            //已建立映射关系的s[i]企图和未建立映射关系的t[i]建立关系，一对多，错误
            return false;
        } else if (A[s[i]] == 0 && B[t[i]] != 0) {
            //B[t[i]]不为0说明t[i]已存在映射关系
            //未建立映射关系的s[i]企图和已建立映射关系的t[i]建立关系，多对一，错误
            return false;
        } else if(A[s[i]] != 0 && B[t[i]] != 0) {
            //检验，s[i]和t[i]都是第二次及以后出现，都已建立映射关系
            //通过哈希表检验两者一对一映射关系是否正确
            if(A[s[i]] != t[i]) {
                return false;
            }
        }
    }
    return true;
}
