#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
pair<double, double> point[512];
double cathe[512][512], n;
double dis(int x, int y) {
	return sqrt(pow(point[x].first - point[y].first, 2) + pow(point[x].second - point[y].second, 2));
}
double dp(int x, int y) {
	if (y == n - 1)
		return dis(x, y);
	if (cathe[x][y])
		return cathe[x][y];
	return cathe[x][y]=min(dp(x, y + 1) + dis(y, y + 1), dp(y, y + 1) + dis(x, y + 1));
}
int main() {
	int t;
	double x, y;
	for (cin >> t;t--;) {
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cathe[i][j] = 0;
		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			point[i] = make_pair(x, y);
		}
		double result = dp(0, 0);
		cout << result << endl;
	}
	return 0;
}
