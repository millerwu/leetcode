package CombinationSum;

import java.util.*;

/*
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Note:

All numbers will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]
 */
public class CombinationSumIII {

    void combiationSumHelper(List<List<Integer>> res, List<Integer> curr, int k, int start, int sum) {
        if (sum < 0 || curr.size() > k ) {
            return;
        }
        if (sum == 0 && curr.size() == k) {
            res.add(new ArrayList<>(curr));
            return;
        }
        for (int i = start; i <= 9; i++) {
            curr.add(i);
            combiationSumHelper(res, curr, k, i+1, sum-i);
            curr.remove(curr.size()-1);
        }
    }

    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        List<Integer> curr = new ArrayList<>();
        combiationSumHelper(res, curr, k, 1, n);
        return res;
    }

    public static void main(String[] args) {
        CombinationSumIII combinationSum = new CombinationSumIII();
        List<List<Integer>> res = combinationSum.combinationSum3(3, 9);
        System.out.println(res);

    }
}
