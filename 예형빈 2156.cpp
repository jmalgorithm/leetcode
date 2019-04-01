#include<iostream>
using namespace std;
int arr[10001][3];
int main() {
	int max(int, int);
	
	int n,value;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> value;
		if (i == 1) 
			arr[i][1] = value;
		else if (i == 2) {
			arr[i][1] = value;
			arr[i][2] = arr[i - 1][1] + value;
		}
		else {
			arr[i][1] = max(max(arr[i-3][1],arr[i-3][2]),max(arr[i - 2][1],arr[i-2][2])) + value;
			arr[i][2] = arr[i - 1][1] + value;
		}
	}
	cout << max(max(arr[n-1][1],arr[n-1][2]),max(arr[n][1], arr[n][2]));
	return 0;
}
int max(int x, int y) {
	if (x > y)
		return x;
	return y;
}