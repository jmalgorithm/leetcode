#include<iostream>
using namespace std;
long long d[32][32][3] = { 0, };
int main() {
	int n, arr[32][32];
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	d[0][1][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (arr[i][j + 1] == 0)
				d[i][j + 1][0] += d[i][j][0] + d[i][j][1];
			if (arr[i][j + 1] == 0 && arr[i + 1][j] == 0 && arr[i + 1][j + 1] == 0)
				d[i + 1][j + 1][1] += d[i][j][0] + d[i][j][1] + d[i][j][2];
			if (arr[i + 1][j] == 0)
				d[i + 1][j][2] = d[i][j][2] + d[i][j][1];
		}
	}
	cout << d[n - 1][n - 1][0] + d[n - 1][n - 1][1] + d[n - 1][n - 1][2];
	return 0;
}
