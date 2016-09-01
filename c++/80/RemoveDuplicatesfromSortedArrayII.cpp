//source: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
        {
            return 0;
        }
        cout << "size = "<< nums.size() <<  endl;
        int res = 0;
        int count = 0;
        for (int i = 0; i<nums.size();)
        {
            if (i>0 && nums[i]==nums[i-1])
            {
                if(count==1)
                {
                    nums.erase(nums.begin()+i);
                } else {
                    count++;
                    ++i;
                }
                continue;
            }
            ++i;
            count = 0;
        }
        return nums.size();
    }
};

vector<int> buildVector(int* num, int size)
{
    vector<int> res;
    for (int i=0; i<size; ++i)
    {
        res.push_back(num[i]);
    }
    return res;
}

int main ()
{
    int nums[] = {1, 1, 1, 2, 2, 3};
    vector<int> v_nums = buildVector(nums, sizeof(nums)/sizeof(int));
    
    cout << "res = " << Solution::removeDuplicates(v_nums) << endl;
	return 0;
}
