//source: https://leetcode.com/problems/sort-colors/

/*
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static void swap(int& a, int& b)
    {
        int i = 0;
        i = a;
        a = b;
        b = i;
    }

    static void sortColors(vector<int>& nums) {
        if (nums.size() <= 1)
        {
            return;
        }
        for (int i = 0; i < nums.size()-1; ++i)
        {
            for (int j = 0; j < nums.size()-i-1; ++j)
            {
                if (nums[j] > nums[j+1])
                {
                    swap(nums[j], nums[j+1]);
                }
            }
        }
    }
};

int main ()
{
    vector<int> test;
    test.push_back(1);
    test.push_back(2);
    test.push_back(0);
    Solution::sortColors(test);
    for (int i = 0; i < test.size(); ++i)
    {
        cout << test[i] << endl;
    }
	return 0;
}
