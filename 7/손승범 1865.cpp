#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int N, T, t;
double res, mat[16][16], cache[16][65536];
double DF(int n, int bitm) {
	if (cache[n][bitm] != -1)
		return cache[n][bitm];
	if (n == N - 1)
		for (int i = 0; i < N; i++)
			if (!(bitm & (1 << i)))
				return cache[n][bitm] = mat[n][i] / 100;
	double res = -1;
	for (int i = 0; i < N; i++)
		if (!(bitm & (1 << i)))
			res = max(res, (mat[n][i] / 100) * DF(n + 1, bitm | (1 << i)));
	return cache[n][bitm] = res;
}
int main() {
	cin >> T;
	cout << fixed;
	cout.precision(6);
	for (t = 1; t <= T; t++) {
		cin >> N;
		res = -1;
		int size = pow(2, N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				cin >> mat[i][j];
			for (int j = 0; j < size; j++)
				cache[i][j] = -1;
		}
		res = DF(0, 0);
		cout << '#' << t << ' ' << (double)res * 100 << endl;
	}
	return 0;
}