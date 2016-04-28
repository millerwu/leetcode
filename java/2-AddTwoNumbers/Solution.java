//source:https://leetcode.com/problems/add-two-numbers/
//author:Miller Wu
//data:2016/04/23

/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

*/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */

public class Solution {
    static public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        if (l1 == null)
        {
            return l2;
        }  
        if (l2 == null)
        {
            return l1;
        }
        ListNode head = new ListNode(0);
        ListNode cur = head;
        int plus = 0;
        while (l1 != null && l2 != null)
        {
            int sum = l1.val + l2.val + plus;
            plus = sum/10;
            sum = sum%10;
            cur.next = new ListNode(sum);
            System.out.println("sum = " + sum);
            cur = cur.next;
            l1 = l1.next;
            l2 = l2.next;
                
        }
        if (l1 != null)
        {
            if (plus != 0)
            {
                cur.next = addTwoNumbers(l1, new ListNode(plus));
            } else {
                cur.next = l1;
            }
        }
        else if (l2 != null)
        {
            if (plus != 0)
            {
                cur.next = addTwoNumbers(l2, new ListNode(plus));
            } else {
                cur.next = l2;
            }
        } else if (plus != 0)
            {
                cur.next = new ListNode(plus);
            }
        
        return head.next;
    }
    
    public static void main(String[] args) {
        ListNode l1 = new ListNode(1);
        l1.next = new ListNode(8);
        // l1.next.next = new ListNode(3);
        
        ListNode l2 = new ListNode(9);
        // l2.next = new ListNode(6);
        // l2.next.next = new ListNode(4);
        
        ListNode res = addTwoNumbers(l1, l2);
        
        while (res!=null)
        {
            System.out.println(res.val);
            res = res.next;            
        }
    }
}

    
