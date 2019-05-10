package DifferentWaystoAddParentheses;

/*
Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.

Example 1:

Input: "2-1-1"
Output: [0, 2]
Explanation:
((2-1)-1) = 0
(2-(1-1)) = 2
Example 2:

Input: "2*3-4*5"
Output: [-34, -14, -10, -10, 10]
Explanation:
(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
 */

import java.util.ArrayList;
import java.util.List;

public class DifferentWaystoAddParentheses {
    public List<Integer> diffWaysToCompute(String input) {
        List<Integer> res = new ArrayList<>();
        boolean isDigit = true;
        for (int i = 0; i < input.length(); i++) {
            if (input.charAt(i) == '+' || input.charAt(i) == '-' || input.charAt(i) == '*') {
                List<Integer> left = diffWaysToCompute(input.substring(0, i));
                List<Integer> right = diffWaysToCompute(input.substring(i + 1, input.length()));
                for (int j = 0; j < left.size(); j++) {
                    for (int k = 0; k < right.size(); k++) {
                        if (input.charAt(i) == '+')     {
                            res.add(left.get(j) + right.get(k));
                        } else if (input.charAt(i) == '-') {
                            res.add(left.get(j) - right.get(k));
                        } else {
                            res.add(left.get(j) * right.get(k));
                        }
                    }
                }
                isDigit = false;
            }
        }
        if (isDigit && input.length() > 0) {
            res.add(Integer.valueOf(input));
        }
        return res;
    }

    static public void main(String[] args) {
        DifferentWaystoAddParentheses differentWaystoAddParentheses = new DifferentWaystoAddParentheses();
        String input = "21-1-1";
        List<Integer> res = differentWaystoAddParentheses.diffWaysToCompute(input);
        for (int i = 0; i < res.size(); i++) {
            System.out.println(res.get(i));
        }
    }
}
