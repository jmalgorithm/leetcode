
#include<iostream>
#include<string>
#include<stack>
using namespace std;

int count(string s) {
	stack<int> st;
	int cnt = 0;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
			st.push(i);
		if (s[i] == ')')
		{
			if (st.top() + 1 == i) //인접괄호
			{
				st.pop();
				cnt += st.size();
			}
			else
			{
				st.pop();
				cnt += 1;
			}

		}
	}
	return cnt;

	
}

int main(void)
{
	string s;

	cin >> s;
	cout << count(s);

	return 0;
}
