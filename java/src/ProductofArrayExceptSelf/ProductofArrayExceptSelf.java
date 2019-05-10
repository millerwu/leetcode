package ProductofArrayExceptSelf;

/*
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
 */


import java.util.HashSet;
import java.util.Set;

public class ProductofArrayExceptSelf {

    public int[] productExceptSelf(int[] nums) {
        long temp = 1;
        Set<Integer> count_zero = new HashSet<>();
        for (int i = 0; i < nums.length; i++) {
            temp *= nums[i];
            if (nums[i] == 0) {
                count_zero.add(i);
            }
        }
        int[] res = new int[nums.length];

        if (count_zero.size() >= 2) {
            return res;
        } else if (count_zero.size() == 1) {
            temp = 1;
            int item = 0;
            for (int i = 0; i < res.length; i++) {
                if (count_zero.contains(i)) {
                    item = i;
                    continue;
                }
                temp *= nums[i];
            }
            res[item] = (int) temp;
            return res;
         }
         else {
            for (int i = 0; i < res.length; i++) {
                res[i] = (int)(temp / nums[i]);
            }
        }
        return res;
    }
    public static void main(String[] args) {
        int[] nums = {1, 0};
        ProductofArrayExceptSelf productofArrayExceptSelf = new ProductofArrayExceptSelf();
        int[] res = productofArrayExceptSelf.productExceptSelf(nums);
        for (int i = 0; i < res.length; i++) {
            System.out.println(res[i]);
        }
    }
}
