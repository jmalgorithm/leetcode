#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>
#include<string>
#include<map>
#include<vector>

using namespace std;

/*leecode 136. Single Number
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:
Input: [2,2,1]
Output: 1

Example 2:
Input: [4,1,2,1,2]
Output: 4
*/

int singleNumber(vector<int>& nums) {
	int size = nums.size();
	int single=0;

	for(int i=0; i<size; i++)
	{
		single= single^nums[i];
	}
	return single;
}

int main(void)
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(4);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(2);
	
	cout << singleNumber(nums);

	return 0;
}