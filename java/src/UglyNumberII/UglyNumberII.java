package UglyNumberII;

/*
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.

Example:

Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
Note:

1 is typically treated as an ugly number.
n does not exceed 1690.

 */

import java.util.ArrayList;
import java.util.List;

public class UglyNumberII {
    public int nthUglyNumber(int n) {
        List<Integer> res = new ArrayList<>();
        res.add(1);
        int n2 = 0, n3 = 0, n5 = 0;
        for (int i = 1; i < n; i++) {
            int nm2 = 2 * res.get(n2);
            int nm3 = 3 * res.get(n3);
            int nm5 = 5 * res.get(n5);
            int nm = Integer.min(nm2, Integer.min(nm3, nm5));
            res.add(nm);
            if (nm == nm2) {
                n2++;
            }
            if (nm == nm3) {
                n3++;
            }
            if (nm == nm5) {
                n5++;
            }
        }
        return res.get(res.size()-1);
    }

    public static void main(String[] args) {
        UglyNumberII uglyNumberII = new UglyNumberII();
        int res = uglyNumberII.nthUglyNumber(10);
        System.out.println(res);
    }
}
