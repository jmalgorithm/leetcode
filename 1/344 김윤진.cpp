#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<string>
#include<map>
#include<vector>

using namespace std;

void reverseString(vector<char>& s) {

	for (int i = 0, j = s.size() - 1; i < j; i++, j--)
	{
		swap(s[i], s[j]);
	}
}

int main()
{
	vector<char> s;
	vector<char>::iterator iter1;

	s.push_back('h');
	s.push_back('e');
	s.push_back('l');
	s.push_back('l');
	s.push_back('o');

	reverseString(s);


	for (iter1 = s.begin(); iter1 != s.end(); iter1++)
	{
		cout << *iter1;
	}

	for (;;);
	return 0;
}
