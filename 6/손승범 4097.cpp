#include <iostream>
#include <algorithm>
using namespace std;
int n;
int main() {
	do {
		cin >> n;
		if (n == 0)
			break;
		int res = -10001, t, s = -10001;
		for (int i = 0; i < n; i++) {
			cin >> t;
			s = max(s, 0) + t;
			res = max(res, s);
		}
		cout << res << endl;
	} while (true);
	return 0;
}