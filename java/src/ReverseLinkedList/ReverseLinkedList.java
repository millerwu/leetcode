package ReverseLinkedList;

public class ReverseLinkedList {

    public class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }

    public ListNode reverseList(ListNode head) {
        if (head == null) {
            return null;
        }
        ListNode fake = new ListNode(0) ;
        ListNode cur = head;
        fake.next = cur;
        while (cur.next != null) {
            ListNode temp = cur.next;
            cur.next = cur.next.next;
            temp.next = fake.next;
            fake.next = temp;
        }
        return fake.next;
    }

    public void printList(ListNode head) {
        while (head != null) {
            System.out.println(head.val);
            head = head.next;
        }
    }

    public static void main (String[] args) {
        int[] nums = {1, 2, 3, 4, 5};
        ReverseLinkedList list = new ReverseLinkedList();
        ReverseLinkedList.ListNode head = list.new ListNode(nums[0]);
        ReverseLinkedList.ListNode cur = head;
        for (int i = 1; i < nums.length; i++) {
            ReverseLinkedList.ListNode node = list.new ListNode(nums[i]);
            cur.next = node;
            cur = cur.next;
        }
        cur.next = null;
        list.printList(head);
        System.out.println("reverse res:");
        ListNode reverse = list.reverseList(head);
        list.printList(reverse);
        return;
    }
}
