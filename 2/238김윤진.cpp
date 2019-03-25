#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>
#include<string>
#include<map>
#include<vector>

using namespace std;

/*leecode 238. Product of Array Except Self
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:
Input:  [1,2,3,4]
Output: [24,12,8,6]


Note: Please solve it without division and in O(n).

Follow up:
 Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
*/

vector<int> productExceptSelf(vector<int>& nums) {

		int size = nums.size();
		vector<int> answer(size, 1);

		int zero_count = 0;
		int all_except_zero = 1;

		for (int i = 0; i<size; i++)
		{
			if (nums[i] == 0)
			{
				zero_count++;
				if (zero_count>1)
					break;
			}
			else
				all_except_zero *= nums[i];
		}

		if (zero_count == 0)
		{
			for (int i = 0; i<size; i++)
			{
				answer[i] = all_except_zero / nums[i];
			}
		}
		else if (zero_count == 1)
		{
			for (int i = 0; i<size; i++)
			{
				if (nums[i] == 0)
					answer[i] = all_except_zero;
				else
					answer[i] = 0;
			}
		}
		else
		{
			answer.assign(size, 0);
		}

		return answer;
}

int main(void)
{
	vector<int> nums;
	nums.push_back(0);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);

	int size = nums.size();

	vector<int> answer = productExceptSelf(nums);

	for (int i = 0; i < size; i++)
		cout << answer[i]<<endl;

	for (;;);
	return 0;
}