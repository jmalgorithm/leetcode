#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int N, A, res, temp, T, t, index, tindex;
pair<int, int>arr[1000001];
int main() {
	cin >> T;
	for (t = 1; t <= T; t++) {
		cin >> N;
		res = 0;
		temp = 0;
		index = 1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> A;
				arr[A] = make_pair(i, j);
			}
		}
		for (int i = 1; i < N*N; i++) {
			if (abs(arr[i].first - arr[i + 1].first) + abs(arr[i].second - arr[i + 1].second) == 1) {
				if (temp == 0)
					tindex = i;
				temp++;
			}
			else {
				if (res < temp) {
					res = temp;
					index = tindex;
				}
				temp = 0;
			}
		}
		if (res < temp) {
			res = temp;
			index = tindex;
		}
		cout << '#' << t << ' ' << index << ' ' << res + 1 << endl;
	}
	return 0;
}