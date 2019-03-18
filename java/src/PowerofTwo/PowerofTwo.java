package PowerofTwo;


/*
Given an integer, write a function to determine if it is a power of two.

Example 1:

Input: 1
Output: true
Explanation: 20 = 1
Example 2:

Input: 16
Output: true
Explanation: 24 = 16
Example 3:

Input: 218
Output: false
 */
public class PowerofTwo {

    public boolean isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
        }
        if (n == 1) {
            return true;
        }
        while (n % 2 == 0) {
            n = n / 2;
            if (n == 1) {
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        PowerofTwo powerofTwo =  new PowerofTwo();
        boolean res = powerofTwo.isPowerOfTwo(16);
        System.out.println(res);
    }
}
