#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<string>
#include<map>
#include<vector>

using namespace std;

vector<string> fizzBuzz(int n) {

		vector<string> v(n);
		vector<string>::iterator iter;

		for (int i = 1; i <= n; i++)
		{
			if (i % 3 != 0 && i % 5 != 0)
			{
				//숫자를 문자열로 변환
				string s = to_string(i);
				v[i - 1] = s;
			}
			else
			{
				if (i % 3 == 0)
					v[i - 1] = "Fizz";
				if (i % 5 == 0)
					v[i - 1] = v[i - 1] + "Buzz";
			}
		}

		return v;
	}

int main()
{
	vector<string> v = fizzBuzz(15);

	vector<string>::iterator iter;

	for (iter = v.begin(); iter != v.end(); iter++)
	{
		cout << *iter << endl;
	}

	for (;;);
	return 0;
}