//source: https://leetcode.com/problems/jump-game-ii/
//data: 2016/03/17
//author: WuMiaoLiang

/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    static int jump(vector<int>& nums) {
        if (nums.size() == 1)
        {
            return 0;
        }
        
        int cur_max = nums[0];
        int steps = 1;
        int cur_start = 0;

        while (cur_max < (nums.size()-1)) {
        	int z_max = 0;
        	int i_start = 0;
        	for (int i = cur_start+1; i <= cur_max; ++i)
        	{
        		if ((i+nums[i]) > z_max)
        		{
        			i_start = i;
        			z_max = i+nums[i];
        		}
           	}
           	cur_start = i_start;
           	cur_max = z_max;
        	steps++;
        }
        return steps;
    }
};

int main ()
{
    int array[] = {2, 3, 1, 1, 4};
	std::vector<int> v(array, array+sizeof(array)/sizeof(int));
	int res = Solution::jump(v);
	cout << "res = " << res << endl;
}
