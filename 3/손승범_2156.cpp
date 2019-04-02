#include <iostream>
using namespace std;
int n;
int dp[10004] = { 0 };
int dps[10004] = { 0 };
int max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		dp[i] = a;
	}
	dps[1] = dp[1];
	dps[2] = dp[1] + dp[2];
	for (int i = 3; i <= n;i++) {
		dps[i] = max(dps[i-1],max(dps[i-2]+dp[i],dps[i-3]+dp[i-1] + dp[i]));
	}
	cout << dps[n] << endl;
	return 0;
}
