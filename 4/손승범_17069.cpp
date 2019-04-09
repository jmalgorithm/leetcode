#include<iostream>
using namespace std;
int n, a;
int mat[32][32] = { 0 };
long long cathe[32][32][32][32] = { 0 };
long long bfs(int x1, int y1, int x2, int y2) {
	long long result = 0;
	if (cathe[x1][y1][x2][y2] != 0)
		return cathe[x1][y1][x2][y2];
	if (x2 == n - 1 && y2 == n - 1)
		return 1;
	if (x2 > n - 1 || y2 > n - 1)
		return 0;
	if (x1!=x2&&mat[x2 + 1][y2] == 0)
		result += bfs(x2, y2, x2 + 1, y2);
	if (y1!=y2&&mat[x2][y2 + 1] == 0)
		result += bfs(x2, y2, x2, y2 + 1);
	if (mat[x2 + 1][y2] == 0 && mat[x2][y2 + 1] == 0 && mat[x2 + 1][y2 + 1] == 0)
		result += bfs(x2, y2, x2 + 1, y2 + 1);
	return cathe[x1][y1][x2][y2]=result;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a;
			mat[i][j] = a;
		}
	}
	cout << bfs(0, 0, 0, 1) << endl;
	return 0;
}
