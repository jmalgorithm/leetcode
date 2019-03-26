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
	
	vector<vector<int>> result;
	
	sort(nums.begin(),nums.end());	//sort(시작주소, 끝주소):오른차순 정렬
	do {
		result.push_back(nums);
	} while (next_permutation(nums.begin(), nums.end()));
	//next_permutation(시작주소, 끝주소)- 다음 순열있으면 true반환한 뒤 다음순열을 구하고, 없으면 false반환
	
	return result;
}

int main(void)
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);

	vector<vector<int>> result = permute(nums);

	int size = result.size();

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < result[i].size(); j++)
		{
			cout << result[i][j];
		}
		cout << endl;
	}

	for (;;);
	return 0;
}