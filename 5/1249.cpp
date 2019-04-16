// �Ｚ 1249
// ����� S���� ������ G���� ��� �� �����ð��� ���� ª�� ��ο� ���� ���� �ð��� ���ض�.
// 2���� �迭�� �־����� ������ �� ĭ���� �Ŀ��� ������ ���̰� �־���.
// ���� �ð��� ���̿� �����.
// �����¿�� �� ĭ�� ������ �� ����.
// ����ġ ĭ�� ���θ� �����ؾ߸� �ٸ� ������ �̵� ����
// ������� �»��, �������� ���ϴ�. �Էµ����Ϳ����� 0���� ǥ�õ�.
// �����, �������� ������ ���� 0�� ���� ���� �۾��� ���ʿ��� ��.

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
	cin >> T;	//�׽�Ʈ ���̽�
	
	for(int t = 1; t <= T; t++)
	{
		int n;
		cin >> n;	//������ ũ��

		// ���� ����
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

			//��
			if (x - 1 >= 0)
			{
				dp[x - 1][y] = dp[x][y] + m[x - 1][y];
				q.push(make_pair(x - 1, y));
				
			}
			//��
			if (x + 1 < n )
			{
				dp[x + 1][y] = dp[x][y] + m[x + 1][y];
				q.push(make_pair(x + 1, y));
				
			}
			//��
			if (y - 1 >= 0 )
			{
				dp[x][y - 1] = dp[x][y] + m[x][y - 1];
				q.push(make_pair(x, y - 1));
				
			}
			//��
			if (y + 1 < n)
			{
				dp[x][y + 1] = dp[x][y] + m[x][y + 1];
				q.push(make_pair(x, y + 1));
			}

		}

	}

	return 0;
}

