//source: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/

#include <iostream>

class Solution {
public:
    bool search(vector<int>& nums, int target) {
    	if (nums.size()<=0)
    	{
    		return false;
    	}
    	int start = 0;
    	int end = nums.size()-1;

    	int mid = (start+end)/2;
    	while (start<end)
    	{
    		if (nums[start]<nums[mid])
    		{
				if (target>=nums[start] && target <= nums[mid])
    			{
    				end = mid;
    				mid = (start+end)/2;
    				while (start < end)
    				{
    					if (nums[mid] >= target)
    					{
							end = mid;    						
    					} else {
    						start = mid+1;
    					}
    				}
    				return nums[end]==target;
    			} 
    			start = mid;
    			mid = (start+end)/2;
    			continue;
    		} else {

    		}
    	}
        
    }
};

int main ()
{
	return 0;
}
