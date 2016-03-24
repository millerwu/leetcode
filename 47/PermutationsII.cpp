//source: https://leetcode.com/problems/permutations-ii/
//This Solution is the same with Permutarion.

/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
*/

#include <iostream>

class Solution {
public:

	static void nextPermute(vector<int>& nums) {
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

    		swap(nums[place-1], nums[j]);
    		sort(nums.begin()+place, nums.end());
    		return;
    	}

    	sort(nums.begin(), nums.end());
	}

	static vector< vector<int> > permuteUnique(vector<int>& nums) {
        vector< vector<int> > res;
        if (nums.size() == 0)
        {
        	return res;
        }
        sort(nums.begin(), nums.end());
        vector<int> start = nums;
        do {
        	res.push_back(nums);
        	nextPermute(nums);
        } while (start != nums);

        return res;
    }
    
};

int main ()
{
	return 0;
}
