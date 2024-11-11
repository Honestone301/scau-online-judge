#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include<stdio.h>
#include<string.h>

void cnm(char *a) {
    int len = strlen(a);
    char str[200+1];
    char x[200];        //这是老子的  栈  
    memset(str, ' ', len);        //初始化数组 使其中部分变成‘ ’
    int location[200];
    memset(x, ' ', len);
    int top = -1;
    for (int i = 0; i < len; i++) {
        if (a[i] == '(') {
            x[++top] = '(';//压入左括号
            location[top] = i;
        }
        else if (a[i] == ')') {//遍历字符串中 出现右括号
            if (top == -1||x[top] != '(') {//若是之前没有左括号  注意逻辑先后 一
                //定是先检查top==-1 
                //即栈是否为空 再进行检查栈顶元素是否为左括号
                str[i] = '?';  //直接标记为   ？
            }
            else {      //若是之前有左括号
                top--;   //弹出置顶的元素 即左括号
            }
        }
    }

    //用以处理残留在栈中的左括号
    //而之前的循环算法不会使得栈中有多余的 右括号 存留 所以只能是左括号多
    int base= 0;
    while (top>=0) {
        str[location[top--]] = '$';
    }

    printf("%s\n", a);
    str[len] = '\0';
    printf("%s\n", str);
}

int main()
{
    char strr[200];
    while (scanf("%s", &strr) != EOF) {
        cnm(strr);
    }
    return 0;
}
