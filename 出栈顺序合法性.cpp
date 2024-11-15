#include <stdio.h>
#include <stdlib.h>
#include<vector>
#define MAX_SIZE 10000
#include<iostream>
#include<stdio.h>


// 判断出栈序列是否合法
int isPopOrder(int pushOrder[], int popOrder[], int n) {
    std::vector<int>stack[MAX_SIZE];
    int i = 0, j = 0;
    int top = -1;

    while (j < n) {
        while (top == -1 || stack[top] != popOrder[i]) {
            if (i == n) {
                return 0;
            }
            stack[++top] = popOrder[i++];
        }

        if (popOrder[j] == stack[top]) {
            top--;
            j++;
        }

    }
    // 如果所有元素都能按照出栈序列出栈，说明出栈序列合法
    return 1;
}

int main() {
    int n;
    int pushOrder[MAX_SIZE];
    int popOrder[MAX_SIZE];

    scanf("%d", &n);        //有几个元素

    for (int i = 0; i < n; i++) {       //压入顺序
        scanf("%d", &pushOrder[i]);
    }

    for (int i = 0; i < n; i++) {       //弹出顺序
        scanf("%d", &popOrder[i]);
    }

    if (isPopOrder(pushOrder, popOrder, n)) {       //判断顺序
        printf("yes\n");
    }
    else {      //否则 则不是弹出顺序
        printf("no\n");
    }

    return 0;
}