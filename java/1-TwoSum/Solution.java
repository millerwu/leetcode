//source:https://leetcode.com/problems/two-sum/
//author:
//data:

/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

import java.util.HashMap;

public class Solution {
    static public int[] twoSum(int[] nums, int target) {
    	HashMap<Integer, Integer> m = new HashMap<Integer, Integer>();

    	for (int i = 0; i < nums.length; i++ ) {
    		if (!m.containsKey(new Integer(nums[i]))) {
    			m.put(target-nums[i], i);
    		}
    		else {
    			return new int[]{i, m.get(nums[i])};
    		}
    	}
    	
        throw new RuntimeException();
    }
    
    public static void main(String[] args) {

    	int[] nums = new int[]{2, 7, 11, 15};

    	int[] res = twoSum(nums, 9);

    	for (int i = 0; i < res.length; i++) {
    		System.out.println(res[i]+ " ");
    	}
        
    }
}

    
