//source: https://leetcode.com/problems/permutation-sequence/

/*
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.
*/

#include <iostream>

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
    static string getPermutation(int n, int k) {
        string res;
        if (n == 0)
        {
            return res;
        }
        vector<int> v;
        for (int i = 1; i <= n; i++)
        {
            v.push_back(i);
        }
        for (int i = 1; i <= k; i++)
        {
            nextPermutation(v);
        }
        
        for (int i = 0; i < n; i++)
        {
            res.append(v[i]);
        }
        return res;
    }
};

int main ()
{
	return 0;
}
