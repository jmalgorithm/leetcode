#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, N;
int mat[100][100];
int dir[4][2] = { { 0,1 },{ 1,0 },{ -1,0 },{ 0,-1 } };
bool compare(pair<int, int>a, pair<int, int>b) {
	if (a.first*a.second < b.first*b.second)
		return true;
	else if (a.first*a.second > b.first*b.second)
		return false;
	else if (a.first < b.first)
		return true;
	return false;
}
pair<int, int>MAX(pair<int, int>a, pair<int, int>b) {
	return make_pair(max(a.first, b.first), max(a.second, b.second));
}
pair<int, int> DFS(int a, int b) {
	mat[a][b] = 0;
	pair<int, int>result = make_pair(a, b);
	for (int i = 0; i < 4; i++) {
		int dx = a + dir[i][0], dy = b + dir[i][1];
		if ((dx >= 0 && dx < N) && (dy >= 0 && dy < N) && mat[dx][dy] != 0)
			result = MAX(result, DFS(dx, dy));
	}
	return result;
}
int main() {
	cin >> n;
	for (int t = 1; t <= n; t++) {
		cin >> N;
		vector<pair<int, int>> V;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> mat[i][j];
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (mat[i][j] != 0) {
					pair<int, int>T = DFS(i, j);
					V.push_back(make_pair(T.first - i + 1, T.second - j + 1));
				}
		sort(V.begin(), V.end(), compare);
		cout << '#' << t << ' ' << V.size();
		for (int i = 0; i < V.size(); i++)
			cout << ' ' << V[i].first << ' ' << V[i].second;
		cout << endl;
	}
	return 0;
}