#define _CRT_SECURE_NO_WARNINGS
/*
백준 문제 - 2293 동전1
n가지 종류의 동전이 있다. 각각의 동전이 나타내는 가치는 다르다. 
이 동전을 적당히 사용해서, 그 가치의 합이 k원이 되도록 하고 싶다. 
그 경우의 수를 구하시오. 각각의 동전은 몇 개라도 사용할 수 있다.
사용한 동전의 구성이 같은데, 순서만 다른 것은 같은 경우이다.

입력
첫째 줄에 n, k가 주어진다. (1 ≤ n ≤ 100, 1 ≤ k ≤ 10,000) 
다음 n개의 줄에는 각각의 동전의 가치가 주어진다. 
동전의 가치는 100,000보다 작거나 같은 자연수이다.

출력
첫째 줄에 경우의 수를 출력한다. 경우의 수는 2^31보다 작다.

예제 입력
3 10
1
2
5

예제 출력
10
*/

#include<iostream>
#include<algorithm>

const int MAX = 10000;
using namespace std;

int dp[MAX + 1] = { 0, };	//index를 합으로 하는 동전들의 경우의 수
int coin[100 + 1] = { 0 };

int main(void) {
	int n,k;	//동전 개수, 목표하는 동전의 총합
	cin >> n >> k;

	for (int i = 1; i <= n; i++)	//각 동전의 cost
		cin >> coin[i];

	dp[0] = 1;	//0을 만드는 경우의 수는 1가지

	for (int i = 1; i <= n; i++)
	{
		for (int j = coin[i]; j <= k; j++)
		{
			dp[j] = dp[j] + dp[j - coin[i]];
		}
	}

	cout << dp[k];


	//for (;;);
	return 0;

}