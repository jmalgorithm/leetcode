// 삼성 1249
// 출발지 S에서 도착지 G까지 경로 중 복구시간이 가장 짧은 경로에 대한 복구 시간을 구해라.
// 2차원 배열로 주어지는 지도는 각 칸마자 파여진 도로의 깊이가 주어짐.
// 복구 시간은 깊이에 비례함.
// 상하좌우로 한 칸씩 움직일 수 있음.
// 현위치 칸의 도로를 복구해야만 다른 곳으로 이동 가능
// 출발지는 좌상단, 도착지는 우하단. 입력데이터에서는 0으로 표시됨.
// 출발지, 도착지를 제외한 곳이 0인 것은 복구 작업이 불필요한 곳.

#include<iostream>
#include<queue>]
#include<cstdio>
using namespace std;
const int MAX = 100;

int m[MAX+1][MAX + 1] = { 0, };
int dp[MAX + 1][MAX + 1] = { 0, };

int main(void)
{
	int T;
	cin >> T;	//테스트 케이스
	
	for(int t = 1; t <= T; t++)
	{
		int n;
		cin >> n;	//지도의 크기

		// 지도 정보
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf_s("%1d", &m[i][j]);
			}
		}

		fill(&dp[0][0], &dp[n][n], 0);

		queue<pair<int, int>> q;
		q.push(make_pair(0, 0));
		dp[0][0] = 0;


		while (!q.empty())
		{
			int x = q.front().first;
			int y = q.front().second;

			if (x == n - 1 && y == n - 1)
			{
				cout << "#" << t << " " << dp[x][y] << endl;
				break;
			}

			q.pop();

			//상
			if (x - 1 >= 0)
			{
				dp[x - 1][y] = dp[x][y] + m[x - 1][y];
				q.push(make_pair(x - 1, y));
				
			}
			//하
			if (x + 1 < n )
			{
				dp[x + 1][y] = dp[x][y] + m[x + 1][y];
				q.push(make_pair(x + 1, y));
				
			}
			//좌
			if (y - 1 >= 0 )
			{
				dp[x][y - 1] = dp[x][y] + m[x][y - 1];
				q.push(make_pair(x, y - 1));
				
			}
			//우
			if (y + 1 < n)
			{
				dp[x][y + 1] = dp[x][y] + m[x][y + 1];
				q.push(make_pair(x, y + 1));
			}

		}

	}

	return 0;
}

