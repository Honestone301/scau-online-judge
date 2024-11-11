#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
using namespace std;
int main() {
	int N;
	cin >> N;
	int X;
	int* arr = new int[N];
	for (int i = 0; i < N;i++) {
		cin >> X;
		if (-10000<=X&&X<=10000) {
			arr[i] = X;
		}
	}
	int min = arr[0];
	int maxdiff = 0;
	for (int i = 0; i < N; i++) {
		int x = arr[i];
		int diff = x - min;
		if (diff>maxdiff) {
			maxdiff = diff;
		}
		if (x<min) {
			min = x;
		}
	}
	cout << maxdiff;
	delete(arr);
	return 0;
}