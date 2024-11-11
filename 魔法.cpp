#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int i, n;
    cin >> n;
    int write = 0;
    int black = 0;
    vector<int> cows(n);
    for (int i = 0; i < n;i++) {
        scanf("%d ", &cows[i]);
        if (cows[i]==1) {
            write++;
        }
        else {
            black++;
        }
    }
    int x=min(write, black);
    cout << x<<endl;

    return 0;
}

