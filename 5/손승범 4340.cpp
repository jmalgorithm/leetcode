#include<iostream>
using namespace std;
int result, n, N;
int mat[50][50];
int min(int a, int b) {
	return (a < b) ? a : b;
}
void find(int a, int b, int c, int d, int e) {
	if (c == 0 && d == -1) {
		result = min(result, e);
		return;
	}
	else if (c >= N || c < 0 || d >= N || d < 0)
		return;
	if (mat[c][d] == 0 || c + d + e>result)
		return;
	int temp = mat[c][d];
	mat[c][d] = 0;
	int x = c - a, y = d - b;
	if (temp<3)
		find(c, d, c + x, d + y, e + 1);
	else {
		if (x == 0) {
			find(c, d, c - 1, d, e + 1);
			find(c, d, c + 1, d, e + 1);
		}
		else {
			find(c, d, c, d - 1, e + 1);
			find(c, d, c, d + 1, e + 1);
		}
	}
	mat[c][d] = temp;
}
int main() {
	cin >> n;
	for (int t = 1; t <= n; t++) {
		result = 0;
		cin >> N;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> mat[i][j];
		find(N - 1, N, N - 1, N - 1, 0);
		cout << '#' << t << ' ' << result << endl;
	}
	return 0;
}