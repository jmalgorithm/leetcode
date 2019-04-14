#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
using namespace std;
int n, N, x[1000], y[1000];
bool index[1000];
long long cache[1000], result;
double E;
int main() {
	cin >> n;
	for (int t = 1; t <= n; t++) {
		result = 0;
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> x[i];
		for (int i = 0; i < N; i++)
			cin >> y[i];
		cin >> E;
		for (int i = 0; i < N; i++) {
			index[i] = true;
			cache[i] = LLONG_MAX;
		}
		vector<int>v;
		v.push_back(0);
		index[0] = false;
		while (v.size()<N) {
			int ind = -1;
			for (int i = 0; i < N; i++)
				if (index[i]) {
					cache[i] = min(cache[i], (long long)(pow(x[v.back()] - x[i], 2) + pow(y[v.back()] - y[i], 2)));
					if (ind == -1)
						ind = i;
					else if (cache[i] < cache[ind])
						ind = i;
				}
			v.push_back(ind);
			index[ind] = false;
			result += cache[ind];
		}
		printf("#%d %.0lf\n", t, result*E);
	}
	return 0;
}