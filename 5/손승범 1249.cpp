#include<iostream>
#include<queue>
using namespace std;
int n, N;
char mat[100][100];
int visit[100][100];
int dir[4][2] = { { 0,1 },{ 1,0 },{ -1,0 },{ 0,-1 } };
void BFS() {
	visit[0][0] = mat[0][0] - '0';
	queue<pair<int, int>>que;
	que.push(make_pair(0, 0));
	while (que.size() != 0) {
		int f = que.front().first, s = que.front().second;
		for (int i = 0; i < 4; i++) {
			int dx = f + dir[i][0], dy = s + dir[i][1];
			if ((dx >= 0 && dx < N) && (dy >= 0 && dy < N)) {
				int T = visit[f][s] + mat[dx][dy] - '0';
				if (T < visit[dx][dy]) {
					visit[dx][dy] = T;
					que.push(make_pair(dx, dy));
				}
			}
		}
		que.pop();
	}
}
int main() {
	cin >> n;
	for (int t = 1; t <= n; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> mat[i][j];
				visit[i][j] = 1000000;
			}
		}
		BFS();
		cout << '#' << t << ' ' << visit[N - 1][N - 1] << endl;
	}
	return 0;
}