package SummaryRanges;

/*
Given a sorted integer array without duplicates, return the summary of its ranges.

Example 1:

Input:  [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.
Example 2:

Input:  [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.
 */

import java.util.LinkedList;
import java.util.List;

public class SummaryRanges {

    public List<String> summaryRanges(int[] nums) {
        if (nums.length == 0) {
            return null;
        }
        List<String> list = new LinkedList<>();
        String str = Integer.toString(nums[0]);
        int i = 1;
        int continue_step = 0;
        boolean started = true;
        while (i < nums.length) {
            if (!started) {
                str = Integer.toString(nums[i]);
                started = true;
                i++;
                continue_step = 0;
                continue;
            }
            if (nums[i] - nums[i-1] == 1) {
                continue_step++;
                i++;
            } else {
                if (continue_step == 0) {
                    list.add(str);
                } else {
                    str = str + "->" + Integer.toString(nums[i-1]);
                    list.add(str);
                }
                started = false;
            }
        }
        if (continue_step == 0) {
            list.add(str);
        } else {
            str = str + "->" + Integer.toString(nums[i-1]);
            list.add(str);
        }
        return list;
    }

    static public void main(String[] args) {
        int[] nums = {0,2,3,4,6,8,9};
        int[] nums2 = {0,1,2,4,5,7};
        SummaryRanges summaryRanges = new SummaryRanges();
        List<String> res = summaryRanges.summaryRanges(nums2);
        for (int i = 0; i < res.size(); i++) {
            System.out.println(res.get(i));
        }
    }
}
