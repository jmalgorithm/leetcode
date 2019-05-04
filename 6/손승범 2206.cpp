#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int n, m, ans = 10000000;
char mat[1000][1000];
bool visit[2][1000][1000];
pair<int, int> dir[4] = { { 0,1 },{ 1,0 },{ -1,0 },{ 0,-1 } };
bool isin(int x, int y) {
	return((x < n&&x >= 0) && (y < m&&y >= 0)) ? true : false;
}
void bfs() {
	int Count = 0;
	queue<pair<pair<int, int>, int>> que;
	visit[mat[0][0] - '0'][0][0] = true;
	que.push(make_pair(make_pair(0, 0), mat[0][0] - '0'));
	while (que.size() != 0) {
		int S = que.size();
		for (; S; S--) {
			pair<int, int> p = que.front().first;
			int s = que.front().second;
			if (p.first == n - 1 && p.second == m - 1)
				ans = min(ans, Count);
			for (int i = 0; i < 4; i++) {
				int dx = p.first + dir[i].first, dy = p.second + dir[i].second;
				if (isin(dx, dy)) {
					int index = s + mat[dx][dy] - '0';
					if (index < 2 && !visit[index][dx][dy]) {
						visit[index][dx][dy] = true;
						que.push(make_pair(make_pair(dx, dy), index));
					}
				}
			}
			que.pop();
		}
		Count++;
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> mat[i][j];
	bfs();
	ans = (ans == 10000000) ? -1 : ans + 1;
	cout << ans << endl;
	return 0;
}