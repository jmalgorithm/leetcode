#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n, k,coin,i,j,x;
	scanf("%d %d", &n, &k);
	int* result = (int*)malloc(sizeof(int)*k+1);
	for (i = 0; i < k + 1; i++)
		result[i] = 0;
	result[0] = 1;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &coin);
		for (int x = k; x >= 0; x--)
		{
			//printf("X: %d\n", x);
			if (result[x] != 0)
				for (int j = coin; x + j <= k; j= j+ coin) 
	                	result[x + j] += result[x];
		}
	}
	printf("%d", result[k]);
	return 0;
}