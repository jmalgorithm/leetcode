#include <iostream>
#include <algorithm>
using namespace std;
int mat[101][101];
int result[101] = { 0 };
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			mat[i][j] = 500;
	for (int i = 0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		mat[a][b] = 1;
		mat[b][a] = 1;
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				mat[i][j] = (mat[i][j]>mat[i][k] + mat[k][j]) ? mat[i][k] + mat[k][j] : mat[i][j];
	int index = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (mat[i][j] != 500)
				result[i] += mat[i][j];
		}
		index = (result[i]<result[index]) ? i : index;
	}
	cout << index << endl;
}