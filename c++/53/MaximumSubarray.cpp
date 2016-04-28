//source: https://leetcode.com/problems/maximum-subarray/

/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static int maxSubArray(vector<int>& nums) {
        int last_max = nums[0];
        int max = last_max;
        for (int i = 1; i < nums.size(); i++)
        {
            last_max = std::max(last_max+nums[i], nums[i]);
            max = std::max(last_max, max);
        }
        return max;
    }
};

int main ()
{
    vector<int> num;
    num.push_back(-2);
    num.push_back(1);
    num.push_back(-3);
    num.push_back(4);
    num.push_back(-1);
    num.push_back(2);
    num.push_back(1);
    num.push_back(-5);
    num.push_back(4);
    int res = Solution::maxSubArray(num);
    cout << "res = " << res << endl;
	return 0;
}
