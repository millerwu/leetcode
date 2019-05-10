package PerfectSquares;

/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
 */

import java.util.ArrayList;
import java.util.List;

public class PerfectSquares {

    public boolean isPerfectSquareNum(int n) {
        return n ==  (int) Math.pow((int)Math.sqrt(n), 2);
    }

    public int numSquares(int n) {
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (isPerfectSquareNum(i + 1)) {
                res.add(1);
            } else {
                int min = Integer.MAX_VALUE;
                for (int j = 0; j < (i + 1) / 2; j++) {
                    min = Integer.min(min, res.get(j) + res.get(i - j - 1));
                }
                res.add(min);
            }
        }
        return res.get(n - 1);
    }

    public static void main(String[] args) {

        PerfectSquares perfectSquares = new PerfectSquares();
        int num = perfectSquares.numSquares(1);
        System.out.println(num);
    }
}
