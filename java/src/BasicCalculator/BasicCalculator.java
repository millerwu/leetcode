/*
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

Example 1:

Input: "1 + 1"
Output: 2
Example 2:

Input: " 2-1 + 2 "
Output: 3
Example 3:

Input: "(1+(4+5+2)-3)+(6+8)"
Output: 23
 */

package BasicCalculator;

import java.util.Stack;

public class BasicCalculator {
    public int calculate(String s) {
        Stack<Character> signStack = new Stack<>();
        Stack<Integer> numStack = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            Character cur = s.charAt(i);
            int top_num = 0;
            int cur_num = 0;
            if (cur == '-' || cur == '+' || cur == '(') {
                signStack.push(cur);
                continue;
            } else if (cur == ' ') {
                continue;
            } else if (cur == ')') {
                cur_num = numStack.pop();
                signStack.pop();
            } else {
                // TODO get complete number
                int cur_index = i;
                while (i + 1 < s.length() && Character.isDigit(s.charAt(i + 1))) {
                    i++;
                }
                for (int j = cur_index; j <= i; j++) {
                    System.out.println(s.charAt(j) - '0');
                    cur_num = cur_num * 10 + s.charAt(j) - '0';
                }

            }
            if (signStack.empty() || signStack.peek() == '(') {
                numStack.push(cur_num);
            } else if (signStack.peek() == '+') {
                signStack.pop();
                top_num = numStack.pop();
                numStack.push(top_num + cur_num);
            } else if (signStack.peek() == '-') {
                signStack.pop();
                top_num = numStack.pop();
                numStack.push(top_num - cur_num);
            }
        }
        return numStack.pop();
    }

    static public void main(String[] args) {
        BasicCalculator basicCalculator = new BasicCalculator();
        String test = "2147483647";
        int res = basicCalculator.calculate(test);
        System.out.println(res);
    }
}
