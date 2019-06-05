package AdditiveNumber;

/*
Additive number is a string whose digits can form additive sequence.

A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.

Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.

Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.

Example 1:

Input: "112358"
Output: true
Explanation: The digits can form an additive sequence: 1, 1, 2, 3, 5, 8.
             1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
Example 2:

Input: "199100199"
Output: true
Explanation: The additive sequence is: 1, 99, 100, 199.
             1 + 99 = 100, 99 + 100 = 199
Follow up:
How would you handle overflow for very large input integers?
 */

public class AdditiveNumber {


    public boolean isSumEqual(String num1, String num2, String num_sum) {
        if ((num1.length() > 1 && num1.charAt(0) == '0') || (num2.length() > 1 && num2.charAt(0) == '0') || (num_sum.length() > 1 && num_sum.charAt(0) == '0')) {
            return false;
        }
        int max_length = Integer.max(num1.length(), num2.length());
        int min_length = Integer.min(num1.length(), num2.length());
        if (num_sum.length() < max_length || num_sum.length() > (max_length + 1)) {
            return false;
        }
        int carry = 0;
        for (int i = 0; i < max_length; i++) {
            int sum = 0;
            if (i < num1.length() && i < num2.length()) {
                sum = num1.charAt(num1.length() - i - 1) - '0' + num2.charAt(num2.length() - i - 1) - '0' + carry;
            } else if (i < num1.length()) {
                sum = num1.charAt(num1.length() - i - 1) - '0' + carry;
            } else if (i < num2.length()) {
                sum = num2.charAt(num2.length() - i - 1) - '0' + carry;
            }
            if ((num_sum.charAt(num_sum.length() - i - 1) - '0') != sum % 10) {
                return false;
            } else {
                carry = sum / 10;
            }
        }
        if (carry == 1 && num_sum.charAt(0) - '0' != carry) {
            return false;
        }

        return true;
    }

    public boolean isAdditiveNumber(String num1, String num2, String add_num) {
        if (add_num.length() == 0) {
            return true;
        }
        int max_length = Integer.max(num1.length(), num2.length());
        int min_length = Integer.min(num1.length(), num2.length());
        for (int i = min_length; i <= max_length + 1; i++) {
            if (isSumEqual(num1, num2, add_num.substring(0, Integer.min(add_num.length(), i)))) {
                return isAdditiveNumber(num2, add_num.substring(0, i), add_num.substring(i));
            }
        }
        return false;
    }

    public boolean isAdditiveNumber(String num) {
        if (num.length() == 0) {
            return false;
        }
        for (int i = 0; i < num.length() - 2; i++) {
            for (int j = i + 1; j <  num.length() - 1; j++) {
                if (isAdditiveNumber(num.substring(0, i + 1), num.substring(i + 1, j + 1), num.substring(j + 1))) {
                    return true;
                }
            }
        }
        return false;
    }

    public static void main(String[] args) {
        String num_sum = "101";
        AdditiveNumber additiveNumber = new AdditiveNumber();
        boolean res = additiveNumber.isAdditiveNumber(num_sum);
        System.out.println(res);
    }
}
