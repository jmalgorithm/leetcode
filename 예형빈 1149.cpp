#include<stdio.h>

int main() {
	int min(int, int);
	int n, r, g, b, arr[1001][3];
	scanf("%d", &n);
	arr[0][0] = 0; arr[0][1] = 0; arr[0][2] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", &r, &g, &b);
		arr[i][0] = min(arr[i - 1][1] + r, arr[i - 1][2] + r);
		arr[i][1] = min(arr[i - 1][0] + g, arr[i - 1][2] + g);
		arr[i][2] = min(arr[i - 1][0] + b, arr[i - 1][1] + b);
	}
	printf("%d", min(arr[n][0], min(arr[n][1], arr[n][2])));
	return 0;
}

int min(int x, int y) {
	if (x > y)
		return y;
	return x;
}