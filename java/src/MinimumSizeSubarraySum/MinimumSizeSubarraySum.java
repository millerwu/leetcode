package MinimumSizeSubarraySum;
/*
Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

Example:

Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.
Follow up:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
 */

import static java.lang.Integer.MAX_VALUE;

public class MinimumSizeSubarraySum {
    public int minSubArrayLen(int s, int[] nums) {
        int left = 0, right = 0;
        int min = Integer.MAX_VALUE;

        while (left < nums.length && right < nums.length) {
            int sum = 0;
            for (int i = left; i <= right; i++) {
                sum += nums[i];
            }
            if (sum >= s) {
                if (left == right) {
                    return 1;
                } else {
                    min = Integer.min(min,right - left + 1);
                    left++;
                }
            } else {
                right++;
            }
        }
        return min == Integer.MAX_VALUE ? 0 : min;
    }

    public static void main(String[] args) {
        int[] nums = {2, 3, 1, 2, 4, 3};
        MinimumSizeSubarraySum minimumSizeSubarraySum = new MinimumSizeSubarraySum();
        int res = minimumSizeSubarraySum.minSubArrayLen(7, nums);
        System.out.println(res);
    }

}
