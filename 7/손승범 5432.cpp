#include <iostream>
#include <vector>
#include <string>
using namespace std;
int N, A, res, T, t;
string str;
int main() {
	cin >> T;
	for (t = 1; t <= T; t++) {
		cin >> str;
		vector<int>v;
		res = 0;
		int cnt = 0;
		for (int i = 0; i < str.length(); i++)
			if (str[i] == '(') {
				v.push_back(cnt);
			}
			else {
				if (str[i - 1] == '(')
					cnt++;
				if (str[i - 1] == ')')
					res += cnt - v.back() + 1;
				v.pop_back();
			}
			cout << '#' << t << ' ' << res << endl;
	}
	return 0;
}