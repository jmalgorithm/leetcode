#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int stair[300];
int cathe[300][300] = { 0 };
int str(int a,int b,int m) {
	if (b==-1) {}
	else {
		m += stair[b];
		if (b == n-1)
			return m;
		else if (b > n-1)
			return 0;
	}
	if (a != -1 && b != -1) {
		if (cathe[a][b] > m)
			return m;
		else cathe[a][b] = m;
	}
	int A = 0, B = 0;
	if (a == -1 || b - a != 1) {
		int c = b + 1;
		A = str(b, c, m);
	}
	int c = b + 2;
	B = str(b, c, m);
	return max(A, B);
}
int main() {
	cin >> n;
	for (int i = 0; i < n;i++) {
		cin >> stair[i];
	}
	int result = str(-1,-1,0);
	cout << result << endl;
}
