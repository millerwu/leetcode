//source: https://leetcode.com/problems/permutations/

/*

Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/

#include <iostream>
#include <vector>
#include <algorithm>

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

	static vector< vector<int> > permute(vector<int>& nums) {
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


void printVector(vector< vector<int> > test)
{
	for (int i = 0; i < test.size(); ++i)
	{
		for (int j = 0; j < test[i].size(); ++j)
		{
			cout << " " << test[i][j];
		}
		cout << endl;
	}
}

int main ()
{
	std::vector<int> test;
	test.push_back(1);
	test.push_back(4);
	test.push_back(6);
	test.push_back(3);

	vector< vector<int> > res = Solution::permute(test);
	printVector(res);
	return 0;
}
