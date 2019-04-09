#define _CRT_SECURE_NO_WARNINGS
/*
백준 문제 - 17069 파이프 옮기기2

유현이가 새 집으로 이사했다. 새 집의 크기는 N×N의 격자판으로 나타낼 수 있고, 1×1크기의 정사각형 칸으로 나누어져 있다. 각각의 칸은 (r, c)로 나타낼 수 있다. 여기서 r은 행의 번호, c는 열의 번호이고, 행과 열의 번호는 1부터 시작한다. 각각의 칸은 빈 칸이거나 벽이다.
오늘은 집 수리를 위해서 파이프 하나를 옮기려고 한다. 파이프는 아래와 같은 형태이고, 2개의 연속된 칸을 차지하는 크기이다.
파이프는 회전시킬 수 있으며, 아래와 같이 3가지 방향이 가능하다.

파이프는 매우 무겁기 때문에, 유현이는 파이프를 밀어서 이동시키려고 한다. 벽에는 새로운 벽지를 발랐기 때문에, 파이프가 벽을 긁으면 안된다. 즉, 파이프는 항상 빈 칸만 차지해야 한다.
파이프를 밀 수 있는 방향은 총 3가지가 있으며, →, ↘, ↓ 방향이다. 파이프는 밀면서 회전시킬 수 있다. 회전은 45도만 회전시킬 수 있으며, 미는 방향은 오른쪽, 아래, 또는 오른쪽 아래 대각선 방향이어야 한다.
파이프가 가로로 놓여진 경우에 가능한 이동 방법은 총 2가지, 세로로 놓여진 경우에는 2가지, 대각선 방향으로 놓여진 경우에는 3가지가 있다.
아래 그림은 파이프가 놓여진 방향에 따라서 이동할 수 있는 방법을 모두 나타낸 것이고, 꼭 빈 칸이어야 하는 곳은 색으로 표시되어져 있다.
가장 처음에 파이프는 (1, 1)와 (1, 2)를 차지하고 있고, 방향은 가로이다. 파이프의 한쪽 끝을 (N, N)로 이동시키는 방법의 개수를 구해보자.

입력
첫째 줄에 집의 크기 N(3 ≤ N ≤ 32)이 주어진다. 둘째 줄부터 N개의 줄에는 집의 상태가 주어진다. 빈 칸은 0, 벽은 1로 주어진다. (1, 1)과 (1, 2)는 항상 빈 칸이다.

출력
첫째 줄에 파이프의 한쪽 끝을 (N, N)으로 이동시키는 방법의 수를 출력한다. 이동시킬 수 없는 경우에는 0을 출력한다.

예제 입력
5
0 0 1 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0

예제 출력
0
*/
#include <stdio.h>
#include<iostream>

using namespace std;

#define HORIZONTAL 0
#define VERTICAL 1
#define DIAGONAL 2

int n;
bool home[32 + 1][32 + 1];
long long int dp[32 + 1][32 + 1][3];

int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> home[i][j];	//벽=1, 빈 공간=0

	dp[1][2][HORIZONTAL] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (home[i][j])continue;	//벽이면 무시

			dp[i][j][HORIZONTAL] += dp[i][j - 1][HORIZONTAL] + dp[i][j - 1][DIAGONAL];
			dp[i][j][VERTICAL] += dp[i - 1][j][VERTICAL] + dp[i - 1][j][DIAGONAL];
			
			if (home[i - 1][j] == 0 && home[i][j - 1] == 0)
				dp[i][j][DIAGONAL] += dp[i - 1][j - 1][HORIZONTAL] + dp[i - 1][j - 1][VERTICAL] + dp[i - 1][j - 1][DIAGONAL];
		}
	}
	
	cout << dp[n][n][HORIZONTAL] + dp[n][n][VERTICAL] + dp[n][n][DIAGONAL];
	for (;;);
	return 0;
}
