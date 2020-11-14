/*
 * =====================================================================================
 *
 *       Filename:  03-151-reverseWords.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/11/14 16时22分14秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
char * reverseWords(char * s){
    // 1.消除前面多余空格
    while (*s == ' ') {
        s++;
    }

    // 2.消除后面的空格，且长度-1
    int len = strlen(s) - 1;
    if (len < 0) {
        return s;
    };
    while (s[len] == ' ') {
        s[len] = '\0';
        len--;
    }

    // 3.栈翻转单词（先进先出）
    char **stack = (char **)malloc(sizeof(char *) * (len + 2) / 2);  // 栈内指针最大不超过
    char *token = strtok(s, " "), *tmp;
    int top = 0;
    while (token != NULL) {
        // printf("token：%s\n", token);
        tmp = (char *)malloc(sizeof(char) * (len + 2));  // 索引+1=长度+1(\0)
        strcpy(tmp, token);
        stack[top++] = tmp;
        token = strtok(NULL, " ");  // 第二次传入NULL
    }
    
    // 4.出栈翻转
    int word_len = 0;  // 计算单词长度
    while (top) {
        tmp = stack[--top];  // 出栈元素
        strcpy(s + word_len, tmp);  // 连续在s基础上拷贝
        word_len += strlen(tmp);  // 总单词长度增加
        free(tmp);  // 拷贝后就释放
        s[word_len++] = ' ';  // 修改\0为空格再让word_len+1
    }
    free(stack);
    s[word_len-1] = '\0';  // 这里比较关键，把s末尾置0
    return s;
}
