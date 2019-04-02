#define _CRT_SECURE_NO_WARNINGS
/*
백준 문제 - 2156 포도주 시식 

효주는 포도주 시식회에 갔다. 그 곳에 갔더니, 테이블 위에 다양한 포도주가 들어있는 포도주 잔이 일렬로 놓여 있었다. 효주는 포도주 시식을 하려고 하는데, 여기에는 다음과 같은 두 가지 규칙이 있다.
1.포도주 잔을 선택하면 그 잔에 들어있는 포도주는 모두 마셔야 하고, 마신 후에는 원래 위치에 다시 놓아야 한다.
2.연속으로 놓여 있는 3잔을 모두 마실 수는 없다.
효주는 될 수 있는 대로 많은 양의 포도주를 맛보기 위해서 어떤 포도주 잔을 선택해야 할지 고민하고 있다. 1부터 n까지의 번호가 붙어 있는 n개의 포도주 잔이 순서대로 테이블 위에 놓여 있고, 각 포도주 잔에 들어있는 포도주의 양이 주어졌을 때, 효주를 도와 가장 많은 양의 포도주를 마실 수 있도록 하는 프로그램을 작성하시오.
예를 들어 6개의 포도주 잔이 있고, 각각의 잔에 순서대로 6, 10, 13, 9, 8, 1 만큼의 포도주가 들어 있을 때, 첫 번째, 두 번째, 네 번째, 다섯 번째 포도주 잔을 선택하면 총 포도주 양이 33으로 최대로 마실 수 있다.

입력
첫째 줄에 포도주 잔의 개수 n이 주어진다. (1≤n≤10,000) 둘째 줄부터 n+1번째 줄까지 포도주 잔에 들어있는 포도주의 양이 순서대로 주어진다. 포도주의 양은 1,000 이하의 음이 아닌 정수이다.

출력
첫째 줄에 최대로 마실 수 있는 포도주의 양을 출력한다.

예제 입력
6
6
10
13
9
8
1

예제 출력
33
*/

#include<iostream>
#include<algorithm>

const int MAX = 10000;
using namespace std;

int dp[MAX+1][2] = { 0, };
int cost[MAX+1]= { 0 };

int main(void) {
	int n;	//포도주 잔 개수
	cin >> n;

	for (int i = 1; i <= n; i++)	//각 계단의 cost
	{
		cin >> cost[i];
	}

	dp[0][0] = 0;
	dp[0][0] = 0;
	dp[1][0] = cost[1];
	dp[1][1] = cost[1];

	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = dp[i - 1][1] + cost[i];
		dp[i][1] = max(dp[i - 2][0], dp[i - 2][1]) + cost[i];
	
		//cout << "dp[" << i << "][0]=" << dp[i][0] << " , ";	
		//cout << "dp[" << i << "][1]=" << dp[i][1] << endl;
	}

	cout << max({ dp[n][0], dp[n][1],dp[n-1][0],dp[n-1][1] });


	for (;;);
	return 0;

}