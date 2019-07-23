package SuperUglyNumber;

import org.omg.PortableInterceptor.INACTIVE;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

/*
Write a program to find the nth super ugly number.

Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k.

Example:

Input: n = 12, primes = [2,7,13,19]
Output: 32
Explanation: [1,2,4,7,8,13,14,16,19,26,28,32] is the sequence of the first 12
             super ugly numbers given primes = [2,7,13,19] of size 4.
Note:

1 is a super ugly number for any given primes.
The given numbers in primes are in ascending order.
0 < k ≤ 100, 0 < n ≤ 1000000, 0 < primes[i] < 1000.
The nth super ugly number is guaranteed to fit in a 32-bit signed integer.
 */
public class SuperUglyNumber {
    boolean isSuperUglyNumber(int[] primes, int num, int index) {
        if (num == 1) {
            return true;
        }
        if (index >= primes.length) {
            return false;
        }
        if (num % primes[index] == 0) {
            if (num / primes[index] == 1) {
                return true;
            } else {
                return isSuperUglyNumber(primes, num / primes[index], 0);
            }
        } else {
            return isSuperUglyNumber(primes, num, index + 1);
        }
    }

    public int nthSuperUglyNumber_violence(int n, int[] primes) {
        int res = 0;
        while (n > 0) {
            for (int i = 1; i < Integer.MAX_VALUE; i++) {
                if (isSuperUglyNumber(primes, i, 0)) {
                    n--;
                }
                if (n == 0) {
                    res = i;
                    break;
                }
            }
        }
        return res;
    }
    public int nthSuperUglyNumber(int n, int[] primes) {
        int[] factor = new int[primes.length];
        List<Integer> res = new ArrayList<>();
        res.add(1);
        List<Integer> minIndex = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            minIndex.clear();
            int minValue = Integer.MAX_VALUE;
            for (int j = 0; j < primes.length; j++) {
                if (minValue > primes[j] * res.get(factor[j])) {
                    minValue = primes[j] * res.get(factor[j]);
                    minIndex.clear();
                    minIndex.add(j);
                } else if (minValue == primes[j] * res.get(factor[j])) {
                    minIndex.add(j);
                }
            }
            res.add(minValue);
            for (int j = 0; j < minIndex.size(); j++) {
                factor[minIndex.get(j)]++;
            }
        }
        return res.get(n-1);
    }

    public static void main(String[] args) {
//        int[] primes = {2, 7, 13, 19};
        int[] primes = {7,19,29,37,41,47,53,59,61,79,83,89,101,103,109,127,131,137,139,157,167,179,181,199,211,229,233,239,241,251};
        SuperUglyNumber superUglyNumber = new SuperUglyNumber();
        int testNum = 100000;
//        int testNum = 12;
        boolean res = superUglyNumber.isSuperUglyNumber(primes, testNum, 0);
        int r = superUglyNumber.nthSuperUglyNumber(testNum, primes);
        System.out.println(r);
    }
}
