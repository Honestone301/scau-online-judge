#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main() {
    // 关闭同步以提高cin cout速度
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    scanf("%d", &n);

    vector<long long> a(n + 1); // 使用long long以避免溢出
    vector<long long> sum(n + 1, 0); // 前缀和数组，初始化为0

    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        sum[i] = sum[i - 1] + a[i]; // 计算前缀和
    }

    int m;
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        int L, R;
        scanf("%d %d", &L, &R);
        printf("%lld\n", sum[R] - sum[L - 1]); // 计算区间和并输出
    }

    return 0;
}