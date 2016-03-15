//source: https://leetcode.com/problems/next-permutation/

/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers. 

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order). 

The replacement must be in-place, do not allocate extra memory. 

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static void nextPermutation(vector<int>& nums) {
    	if (nums.size() <= 1)
    	{
    		return;
    	}

    	int place = nums.size() - 1;
    	int i = 0;
    	while (place > 0) {
    		if (nums[place] <= nums[place-1]) {
    			place--;
    			continue;
    		}
    		int j =  nums.size() -1;
    		while (nums[place-1] >= nums[j])
    		{
    			j--;
    		}

    		int tmp = nums[place-1];
    		nums[place-1] = nums[j];
    		nums[j] = tmp;

    		sort(nums.begin()+place, nums.end());
    		return;
    	}

    	sort(nums.begin(), nums.end());
    }
};

void print(vector<int>& nums) {
	for (int i = 0; i < nums.size(); ++i)
	{
		cout<< nums[i] << " ";
	}
	cout << "\n" << endl;
}

bool isBeginVector(std::vector<int>& v) {
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i] != i+1)
			return false;
	}
	return true;
}

int main ()
{
	std::vector<int> test;

	int s = 4;
	for (int i = 1; i < s; i++)
		test.push_back(i);
	while(true) {
		print(test);
		Solution::nextPermutation(test);
		if( isBeginVector(test))
			break;
	}
	return 0;
}
