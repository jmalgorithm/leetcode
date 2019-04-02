#include <iostream>
#include <algorithm>
using namespace std;
int n, k;
int coin[100];
int cathe[10001] = { 0 };
int DPS(int a, int b) {
	if (b == 0)
		return 1;
	if (b < 0)
		return 0;
	return cathe[b] += DPS(a, b - coin[a]) ;
}
void DP(int a) {
	if (a == n)
		return;
	for (int i = 0; i < coin[a];i++) {
		DPS(a, k-i);
	}
	DP(a + 1);
}
int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d",&a);
		coin[i] = a;
	}
	cathe[0] = 1;
	DP(0);
	int result = cathe[k];
	printf("%d\n",result);
	return 0;
}
