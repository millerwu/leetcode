//source: https://leetcode.com/problems/search-in-rotated-sorted-array/

/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

*/

#include <iostream>
#include <vector>

class Solution {
public:

    static int search(vector<int>& nums, int target) {
    	int size = nums.size();
    	if (size == 0)
    	{
    		return -1;
    	}
    	int start = 0;
    	int end = nums.size()-1;

    	while (start < end-1){
    		if (nums[start] < nums[(start+end)/2])
    		{
                if (target >= nums[start] && target <= nums[(start+end)/2])
                {

                    end = (start+end)/2;
                    while (start < end) {
                        if (target <= nums[(start+end)/2])
                        {
                            end = (start+end)/2;
                        } else {
                            start = (start+end)/2+1;
                        }
                    }
                    if (target==nums[start])
                        return start;
                    else 
                        return -1;
                } else {
                    start = (start+end)/2;
                }
               
    		} else {
                if (target >= nums[(start+end)/2] && target <= nums[end])
                {
                    start = (start+end)/2;
                     while (start < end) {
                        if (target <= nums[(start+end)/2])
                        {
                            end = (start+end)/2;
                        } else {
                            start = (start+end)/2+1;
                        }
                    }
                    if (target==nums[start])
                        return start;
                    else 
                        return -1;
                } else {
                    end = (start+end)/2;
                }

            }

    	}
        if (target == nums[start])
            return start;
        else if (target == nums[end])
        {
            return end;
        }
        else
            return -1;
        
    }
};

int main ()
{
    std::vector<int> sortedArray;
    sortedArray.push_back(4);
    sortedArray.push_back(1);

    int res = Solution::search(sortedArray, 1);
    cout << "search res = " << res;
	return 0;
}
