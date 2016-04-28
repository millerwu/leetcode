//source:https://leetcode.com/problems/longest-substring-without-repeating-characters/
//author:
//data:

/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.


*/
import java.util.HashMap;
public class Solution {
   static public int lengthOfLongestSubstring(String s) {
        if (s.length() == 0)
            return 0;
        int i = 0, j = 0;
        int result = 0;
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        
        while (j < s.length())
        {
            Integer c = new Integer(s.charAt(j));
            if (!map.containsKey(c))
            {
                map.put(c, j);
            } else {
                int length = j - i;
                result = result > length ? result : length;
                Integer index = map.get(c);
                i = i > index+1 ? i : index+1;
                map.put(c, j);
            }
            j++;
        }
        
        return j - i > result ? j - i : result;
        
    }
    
    public static void main(String[] args) {
        int length = Solution.lengthOfLongestSubstring("abba");
        System.out.println("length = " + length);
    }
}

    
