#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

/*leecode 46. Permutations
Given a collection of distinct integers, return all possible permutations.

Example:
Input: [1,2,3]
Output:
[
[1,2,3],
[1,3,2],
[2,1,3],
[2,3,1],
[3,1,2],
[3,2,1]
]
*/

vector<vector<int>> permute(vector<int>& nums) {
	vector<int> v;
	vector<vector<int>> result;
	queue<int> q;

	for (int i = 0; i<nums.size(); i++)
		q.push(nums[i]);

	recursion(q, v, result);

	return result;
}

void recursion(queue<int>& q, vector<int>& v, vector<vector<int>>& result) {

	int size = q.size();

	if (q.empty())
		result.push_back(v);
	else
	{
		for (int i = 0; i<size; i++)
		{
			int temp = q.front();
			v.push_back(temp);
			q.pop();

			recursion(q, v, result);

			q.push(temp);
			v.pop_back(); //벡터의 맨 마지막 값 삭제

		}
	}
}
