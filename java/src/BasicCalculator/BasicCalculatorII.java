package BasicCalculator;

/*
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

Example 1:

Input: "3+2*2"
Output: 7
Example 2:

Input: " 3/2 "
Output: 1
Example 3:

Input: " 3+5 / 2 "
Output: 5
 */

import java.util.Stack;

public class BasicCalculatorII {

    private int getNum(char c) {
        return c - '0';
    }

    public int calculate(String s) {
        if (s.length() == 0) {
            return 0;
        }

        Stack<Character> signStack = new Stack<>();
        Stack<Integer> numStack = new Stack<>();
        int i = 0;
        while (i < s.length()) {
            if (Character.isDigit(s.charAt(i))) {
                int num = getNum(s.charAt(i));
                while (i + 1 < s.length() && Character.isDigit(s.charAt(i + 1))) {
                    i++;
                    num = num * 10 + getNum(s.charAt(i));
                }
                if (signStack.empty()) {
                    numStack.push(num);
                } else {
                    if (signStack.peek() == '*') {
                        signStack.pop();
                        int topNum = numStack.pop();
                        num = num * topNum;
                    } else if (signStack.peek() == '/') {
                        signStack.pop();
                        int topNum = numStack.pop();
                        num = topNum / num;
                    }
                    if (signStack.empty()) {
                        numStack.push(num);
                    } else {
                        while (i + 1 < s.length() && s.charAt(i + 1) == ' ') {
                            i++;
                        }
                        if (i + 1 < s.length() && (s.charAt(i + 1) == '*' || s.charAt(i + 1) == '/')) {
                            numStack.push(num);
                        } else {
                            if (signStack.peek() == '+') {
                                signStack.pop();
                                int topNum = numStack.pop();
                                num = topNum + num;
                            } else if (signStack.peek() == '-') {
                                signStack.pop();
                                int topNum = numStack.pop();
                                num = topNum - num;
                            }
                            numStack.push(num);
                        }
                    }

                }
            } else if (s.charAt(i) == ' ') {

            } else {
                signStack.push(s.charAt(i));
            }
            i++;
        }
        return numStack.peek();
    }

    public static void main(String[] args) {
        BasicCalculatorII basicCalculator = new BasicCalculatorII();
        String testString = " 3+2*2";
        int res = basicCalculator.calculate(testString);
        System.out.println(res);
    }
}
