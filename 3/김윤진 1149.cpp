#define _CRT_SECURE_NO_WARNINGS
/*
문제 1149
RGB거리에 사는 사람들은 집을 빨강, 초록, 파랑중에 하나로 칠하려고 한다. 
또한, 그들은 모든 이웃은 같은 색으로 칠할 수 없다는 규칙도 정했다. 
집 i의 이웃은 집 i-1과 집 i+1이다.
각 집을 빨강으로 칠할 때 드는 비용, 초록으로 칠할 때 드는 비용, 파랑으로 드는 비용이 주어질 때, 
모든 집을 칠할 때 드는 비용의 최솟값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 집의 수 N이 주어진다. N은 1,000보다 작거나 같다. 
둘째 줄부터 N개의 줄에 각 집을 빨강으로 칠할 때, 초록으로 칠할 때, 파랑으로 칠할 때 드는 비용이 주어진다. 
비용은 1,000보다 작거나 같은 자연수이다.

출력
첫째 줄에 모든 집을 칠할 때 드는 비용의 최솟값을 출력한다.

예제 입력 
3
26 40 83
49 60 57
13 89 99

예제 출력 
96
*/

#include<iostream>
#include<algorithm>

const int MAX = 1000;
using namespace std;

int dp[MAX][3] = { 0, };
int cost[MAX][3] = { 0, };

int main(void) {
	int n;	//집의 수
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> cost[i][j];
		}
	}
	dp[0][0] = cost[0][0];	//첫 번째 집 R로 칠할 때(R:0)
	dp[0][1] = cost[0][1];	//첫 번째 집 G로 칠할 때(G:1)
	dp[0][2] = cost[0][2];	//첫 번째 집 B로 칠할 때(B:2)
	
	for(int i=0;i<n-1;i++)
	{
		dp[i + 1][0] = min(dp[i][1], dp[i][2]) + cost[i + 1][0];
		dp[i + 1][1] = min(dp[i][0], dp[i][2]) + cost[i + 1][1];
		dp[i + 1][2] = min(dp[i][0], dp[i][1]) + cost[i + 1][2];
	}

	cout << min({ dp[n - 1][0], dp[n - 1][1], dp[n - 1][2] });	//min함수, 3개 이상일 때는 { }안에 씀

	for (;;);
	return 0;

}