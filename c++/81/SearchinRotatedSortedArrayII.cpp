//source: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
   	static bool search(vector<int>& nums, int target) {
    	if (nums.size()<=0)
    	{
    		return false;
    	}
    	int start = 0;
    	int end = nums.size()-1;

    	int mid = (start+end)/2;
    	while (start<end-1)
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
    					mid = (start+end)/2;
    				}
    				if (nums[end]==target)
    				 {
    				 	return true;
    				 } else {
    				 	return false;
    				 }
    			} 
    			start = mid;
    			mid = (start+end)/2;
    			continue;
    		} else if (nums[mid] < nums[end]){
    			if (target>=nums[mid] && target <=nums[end])
    			{
    				start=mid;
    				mid = (start+end)/2;
    				while(start < end)
    				{
    					if (nums[mid]>=target)
    					{
    						end = mid;
    					} else {
    						start = mid+1;
    					}
    					mid = (start+end)/2;
    				}
    				if (nums[end]==target)
    				 {
    				 	return true;
    				 } else {
    				 	return false;
    				 }
    			}
    			end = mid;
    			mid = (start+end)/2;
    			continue;
    		} else {
    			if (nums[start]==target)
    			{
    				return true;
    			}
    			start++;
    			mid = (start+end)/2;
    		}
    		
    	}
	if (nums[start]==target || nums[end] == target)
	{
		return true;
	} 
	return false;
    }
};

int main ()
{
	std::vector<int> v;
	// v.push_back(1);
	// v.push_back(5);
	// v.push_back(6);
	// v.push_back(7);
	// v.push_back(0);
	// v.push_back(1);
	// v.push_back(2);

	v.push_back(1);
	v.push_back(1);
	v.push_back(3);
	v.push_back(1);
	int i = 0;
	cin >> i;
	bool r = Solution::search(v, i);
	cout << "res = " << r << endl;
	return 0;
}
