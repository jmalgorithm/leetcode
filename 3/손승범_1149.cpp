#include <iostream>
#include <algorithm>
using namespace std;
int n;
int rgb[1000][3];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, c, d;
		cin >> a >> c >> d;
		if (i == 0)
			rgb[i][0] = a, rgb[i][1] = c, rgb[i][2] = d;
		else
			rgb[i][0] = min(rgb[i - 1][1], rgb[i - 1][2]) + a, rgb[i][1] = min(rgb[i - 1][0], rgb[i - 1][2]) + c, rgb[i][2] = min(rgb[i - 1][0], rgb[i - 1][1]) + d;
	}
	int result = min(rgb[n - 1][0], min(rgb[n - 1][1], rgb[n - 1][2]));
	cout << result << endl;
	return 0;
}
